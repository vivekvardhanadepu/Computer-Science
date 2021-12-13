#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <deque>

using namespace std;

int factorial(int n){
    int res = 1;
    for(int i=n;i>0;i--){
        res*=i;
    }

    cout<<"factorial is "<<res<<endl;
    return res;
}

deque<packaged_task<int()>> q;
void popper(){
    this_thread::sleep_for(std::chrono::seconds(2));
    packaged_task<int()> t2;
    t2 = move(q.front());
    t2();
}

int main(){
    // packaged_task<int(int)> pt(factorial);
    thread t(popper);
    packaged_task<int()> pt(bind(factorial,6));
    q.push_back(pt);
    /// ...
    // future<int> f = pt.get_future();
    // pt(); // runs in a different context
    // int x = f.get();
    // cout<<x<<endl;
    t.join();
    return 0;
}