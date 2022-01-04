class ZeroEvenOdd {
private:
    int n;
    bool isOdd = false;
    bool isZero = true;
    
    condition_variable cv;
    mutex mtx;
	
    // a helper print function to be used by odd and even printing methods
    void print(int i, function<void(int)> printNumber, function<bool()> pred) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, pred);
        printNumber(i);
        isZero = true;
        ul.unlock();
        cv.notify_all();
    }
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(mtx);
            cv.wait(ul, [this]() { return isZero; });
            printNumber(0);
            isOdd = !isOdd;
            isZero = false;
            ul.unlock();
            cv.notify_all();
        }
        
    }

    void even(function<void(int)> printNumber) {
        auto evenPred = [this]() { 
            return !isZero && !isOdd; 
        };
        
        for (int i = 2; i <= n; i += 2) {
            print(i, printNumber, evenPred);
        }
    }

    void odd(function<void(int)> printNumber) {
        auto oddPred = [this]() { 
            return !isZero && isOdd; 
        };
        
        for (int i = 1; i <= n; i += 2) {
            print(i, printNumber, oddPred);
        }
    }
};

// https://leetcode.com/problems/print-zero-even-odd/