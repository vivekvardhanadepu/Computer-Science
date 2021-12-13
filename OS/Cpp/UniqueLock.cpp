#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mu;

class LogFile{
    mutex _mu;
    mutex _mu2;
    once_flag _once_open;
    ofstream _f;
    public:
        void print(int i){
            {
                unique_lock<mutex> guard(_mu2);
                if(!_f.is_open())
                    _f.open("log.txt");
            }
            call_once(_once_open, [&](){_f.open('log.txt')}); // equiv to above, but, more efficient
            unique_lock<mutex> guard2(_mu);  // equivalent to lock_guard, but, perf heavy
            //...
            guard3.lock();      // explicit lock and unlock
            // mu.lock();
            cout<<i<<endl;
            guard3.unlock();
            // mu.unlock();
        }
}

void print(int i){
    // lock_guard<mutex> guard(mu, adopt_lock); // mu is unlocked when guard goes out of scope
    unique_lock<mutex> guard2(mu);  // equivalent to lock_guard, but, perf heavy
    unique_lock<mutex> guard3(mu, defer_lock); // can be deferred until after

    //...
    guard3.lock();      // explicit lock and unlock
    // mu.lock();
    cout<<i<<endl;
    guard3.unlock();
    // mu.unlock();

    unique_lock<mutex> guard4 = move(guard3); // unique_lock can be moved
}

void print_arr(){
    for(int i=0;i<100;i++){
        print(i);
    }
}

int main(){
    
    thread t1(print_arr);
    for(int i=0;i<100;i++){
        print(-i);
    }
    t1.join();
    return 0;
}