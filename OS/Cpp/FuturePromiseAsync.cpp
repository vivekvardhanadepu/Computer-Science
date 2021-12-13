#include <iostream>
#include <thread>
#include <future>

using namespace std;

// mutex mu;
// condition_variable cond;

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

    promise<int> p;
    // promise<int> p2 = move(p);
    future<int> f = p.get_future();
    shared_future<int> sf = f.share();
    // thread t1(factorial, 4, ref(x));
    // future<int> fu = async(launch::deferred | launch::async, factorial, 4);
    // future<int> fu = async(launch::async, factorial, ref(f));
    future<int> fu = async(launch::async, factorial, sf);
    future<int> fu2 = async(launch::async, factorial, sf);
    future<int> fu3 = async(launch::async, factorial, sf);

    // p.set_exception(make_exception_ptr(runtime_error("To err is human")));
    p.set_value(4); // broadcasting to all shared futures
    // fu.get();
    cout<<"output: "<<x<<endl;
    // t1.join();
    return 0;
}