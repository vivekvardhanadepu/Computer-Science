#include <iostream>
#include <thread>

using namespace std;

void f1(){
    cout<<"okay"<<endl;
}

int main(){
    thread t1(f1);
    // t1.join();
    t1.detach();
    //...
    if(t1.joinable())
    t1.join();
    return 0;
}