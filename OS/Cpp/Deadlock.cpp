#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;
mutex mu2;

void print(int i){
    lock(mu, mu2); // lock more than 1 mutex at a time
    lock_guard<mutex> guard(mu, adopt_lock); // mu is unlocked when guard goes out of scope
    lock_guard<mutex> guard2(mu2, adopt_lock); // adopt_lock adopts the lock from the prev multi-lock
    // mu.lock();
    cout<<i<<endl;
    // mu.unlock();
}

void print2(int i){
    lock_guard<mutex> guard(mu2); // mu2 is unlocked when guard goes out of scope
    lock_guard<mutex> guard2(mu);
    // mu.lock();
    cout<<i<<endl;
    // mu.unlock();
}

void print_arr(){
    for(int i=0;i<100;i++){
        print(i);
    }
}

int main(){
    
    thread t1(print_arr);
    for(int i=0;i<100;i++){
        print2(-i);
    }
    t1.join();
    return 0;
}