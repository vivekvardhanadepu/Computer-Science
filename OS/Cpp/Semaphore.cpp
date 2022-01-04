#include <iostream>
#include <thread>
#include <semaphore>
 
using namespace std;

counting_semaphore<1> printSemaphore(0);

void f1(){
    cout<<"Hello";
    printSemaphore.release();
}

void f2(){
    printSemaphore.acquire();
    cout<<"World"<<endl;
}

int main(){
    thread t1(f1);
    thread t2(f2);

    t1.join();
    t2.join();
    return 0;
}