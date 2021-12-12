#include <iostream>
#include <thread>

using namespace std;

void f1(){
    cout<<"okay"<<endl;
}

class Fctor{
    public:
        void operator()(string& s1){
            for(int i=0;i<3;i++){
                cout<<s1<<" From fctor "<<i<<endl;
            }
            s1 = "clearly I never fail";
        }
};

int main(){
    // Fctor fct1;
    // thread t1(fct1);
    string s = "This is kells";
    thread t2((Fctor()), ref(s));
    cout<<"parent id: "<<this_thread::get_id()<<endl;
    // thread t2((Fctor()), move(s));
    
    // thread t2 = t1 // throws error as thread obj is not copiable
    thread t1 = move(t2);
    cout<<"child id: "<<t1.get_id()<<endl;
    cout<<"hardware concurrency: "<<thread::hardware_concurrency()<<endl;
    try{
        for(int i=0;i<20;i++){
            cout<<s<<" "<<i<<endl;
        }
    } catch(std::exception& e){
        t1.join();
        throw e;
    }
    t1.join();
    return 0;
}