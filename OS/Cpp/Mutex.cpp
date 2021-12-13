#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;

void print(int i){
    lock_guard<mutex> guard(mu); // mu is unlocked when guard goes out of scope
    mu.lock();
    cout<<i<<endl;
    mu.unlock();
}

void print_arr(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        print(arr[i]);
    }
}

int main(){
    
    thread t1(print_arr);
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    t1.join();
    for(int i=0;i<10;i++){
        print(-arr[i]);
    }
    return 0;
}