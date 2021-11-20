#include <iostream>
using std::string;
using std::endl;
using std::cout;

class AbstractEmployee{
    virtual void askForPromotion()=0; 
};

class Employee: AbstractEmployee{
    private:
        string company;
        int age;

    protected:
        string name;

    public:
        void setName(string name){
            this->name = name;
        }

        string getName(){
            return this->name;
        }

        void setCompany(string company){
            this->company = company;
        }

        string getCompany(){
            return this->company;
        }

        void setAge(int age){
            if(age>=19)
            this->age = age;
        }

        int getAge(){
            return this->age;
        }

        void IntroduceYourself(){
            cout<<name<<endl;
            cout<<company<<endl;
            cout<<age<<endl;
        }

        void askForPromotion(){
            if(age>25){
                cout<<name<<" can't be promoted"<<endl;
            }
            else{
                cout<<name<<" got promoted"<<endl;
            }
        }

        Employee(string name, string company, int age){
            this->name = name;
            this->company = company;
            this->age = age;
        }
};

class Developer: public Employee{
    public:
        string language;
        Developer(string name, string company, int age, string language):Employee(name, company, age){
            this->language = language;
        }
        void fixBug(){
            cout<<this->name<<" fixed bug using "<<language<<endl;
        }
};

class Teacher: Employee{
    public:
        string sub;
        void prepLesson(){
            cout<<name<<" is preparing "<<sub<<endl;
        }
        Teacher(string name, string company, int age, string sub):Employee(name, company, age){
            this->sub = sub;
        }
};

int main(){
    // Employee employee1 = Employee("matheew", "gogole", 25);
    // employee1.IntroduceYourself();
    // employee1.setName("new_matheew");
    // employee1.askForPromotion();

    // Employee employee2 = Employee("cheta", "AI", 30);
    // employee2.IntroduceYourself();
    // employee2.askForPromotion();

    Developer dev1 = Developer("salina", "Amazomn", 20, "cpp");
    // dev1.IntroduceYourself();
    dev1.fixBug();
    dev1.askForPromotion();

    Teacher t1 = Teacher("Jsack", "skl", 45, "coding");
    t1.prepLesson();
    return 0; 
}