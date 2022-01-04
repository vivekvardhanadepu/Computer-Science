#include <mutex>
#include <condition_variable>

class Foo {
    mutex lockAB;
    condition_variable condAB, condBC;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> locker(lockAB);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        locker.unlock();
        this_thread::sleep_for(chrono::milliseconds(10));
        condAB.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> locker(lockAB);
        condAB.wait(locker);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        locker.unlock();
        this_thread::sleep_for(chrono::milliseconds(10));
        condBC.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> locker(lockAB);
        condBC.wait(locker);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

class Foo {
public:
  mutex a, b;
  
  Foo(){
    a.lock(), b.lock();
  }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    a.unlock();
  }

  void second(function<void()> printSecond) {
    a.lock();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    a.unlock(), b.unlock();
  }

  void third(function<void()> printThird) {
    b.lock();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    b.unlock();
  }

};

class Foo {
atomic<int> progress = 0;
    
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        ++progress;
    }

    void second(function<void()> printSecond) {
        while(progress <1)
        {
            
        }
        
        printSecond();
        ++progress;
    }

    void third(function<void()> printThird) {
        while(progress <2)
        {
            
        }
        printThird();
    }
};

// https://leetcode.com/problems/print-in-order/