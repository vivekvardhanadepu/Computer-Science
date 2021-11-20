#include <iostream>
using std::string;
using std::endl;
using std::cout;

class AbstractEmployee{
    virtual void askForPromotion()=0; 
};

class Employee: public AbstractEmployee{
    private:
        string name;
        string company;
        int age;

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

int main(){
    Employee employee1 = Employee("matheew", "gogole", 25);
    // employee1.IntroduceYourself();
    employee1.setName("new_matheew");
    employee1.askForPromotion();

    Employee employee2 = Employee("cheta", "AI", 30);
    // employee2.IntroduceYourself();
    employee2.askForPromotion();
    return 0; 
}