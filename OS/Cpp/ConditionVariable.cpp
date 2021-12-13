#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;

void function1(){
    int count = 10;
    while(count){
        unique_lock<mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        // cond.notify_one();
        cond.notify_all();
        this_thread::sleep_for(chrono::milliseconds(1000));
        count--;
    }
}

void function2(){
    int data = 0;
    while(data!=1){
        unique_lock<mutex> locker(mu);
        // if(!q.empty()){
        //     data = q.back();
        //     q.pop_back();
        //     locker.unlock();
        //     cout<<"got a value: "<<data<<endl;
        // }else{
        //     locker.unlock();
        //     std::this_thread::sleep_for(std::chrono::seconds(10)); // to mitigate busy waiting
        // }
        cond.wait(locker, [](){return !q.empty();});
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout<<"got a value: "<<data<<endl;
    }
}

int main(){
    thread t1(function1);
    thread t2(function2);
    t1.join();
    t2.join();
    return 0;
}