#include <iostream>
#include <thread>
#include <future>

using namespace std;

mutex mu;
condition_variable cond;

int factorial(shared_future<int> f){
    int n = f.get();
    int res = 1;
    for(int i=n;i>0;i--){
        res*=i;
    }

    cout<<"factorial is "<<res<<endl;
    // x = res;
    return res;
}

int main(){
    int x;

    thread t1(facrorial, 6);
    this_thread::sleep_for(chrono::milliseconds(1));
    chrono::steady_clock::time_point tp = chrono::steady_clock::now()+chrono::milliseconds(20);
    this_thread::sleep_until(tp);
    promise<int> p;

    unique_lock<mutex> locker(mu);
    locker.try_lock();
    locker.try_lock_for(chrono::nanoseconds(1000));
    locker.try_lock_until(tp);

    condition_variable cond;
    cond.wait_for(locker, chrono::milliseconds(10))
    cond.wait_until(locker, tp);
    // promise<int> p2 = move(p);
    future<int> f = p.get_future();

    f.wait(); // internally called by get()
    f.wait_for(chrono::milliseconds(20));
    f.wait_until(tp);
    
    future<int> fu3 = async(launch::async, factorial, sf);

    -
    cout<<"output: "<<x<<endl;
    // t1.join();
    return 0;
}