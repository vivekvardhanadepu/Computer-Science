#include <iostream>
using std::string;
using std::endl;
using std::cout;

class Employee{
    public:
        string name;
        string company;
        int age;

        void IntroduceYourself(){
            cout<<name<<endl;
            cout<<company<<endl;
            cout<<age<<endl;
        }

        Employee(string name, string company, int age){
            this->name = name;
            this->company = company;
            this->age = age;
        }
};

int main(){
    Employee employee1 = Employee("matheew", "gogole", 25);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("cheta", "AI", 30);
    employee1.IntroduceYourself();
    return 0; 
}