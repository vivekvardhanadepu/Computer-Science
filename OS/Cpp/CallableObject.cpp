#include <iostream>
#include <thread>

using namespace std;

class A{
    public:
        void f(int x, char c){cout<<x<<" "<<c<<endl;}
        long g(double x){ return 0;}
        int operator()(int x){ cout<<x<<endl;
        return 0;}
};

int main(){
    A a;
    thread t1(a,6); // copy of a() in thread 
    thread t2(ref(a),6); // a() in thread
    thread t3(A(), 6);  // temp A
    thread t4([](int x){return x*x;}, 6); // lambda function
    thread t7(move(a),6); // a is moved to child thread
    thread t5(&A::f, a, 6, 'a'); // copy of a.f(6, 'a') in thread
    thread t6(&A::f, &a, 6, 'a'); // copy of a.f(6, 'a') in thread
    

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();

    return 0;
}