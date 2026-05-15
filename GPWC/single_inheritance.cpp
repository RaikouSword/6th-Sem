#include <iostream>
using namespace std;

class Base{
    public:
        int x=100;
        Base(){
            cout<<"Base class constructor"<<endl;
        }
        ~Base(){
            cout<<"Base class destructor"<<endl;
        }
        virtual void show(){ //virtual function
            cout<<"Base class: "<<"x="<<x<<endl;
        }
        virtual void show() = 0; //pure virtual -> so called abstract class
};

class Derived: public Base{
    public:
        int x = 200;
        Derived(){
            cout<<"Derived class constuctor"<<endl;
        }
        ~Derived(){
            cout<<"Derived class destructor"<<endl;
        }
        void show(){
            cout<<"Derived class: "<<"x="<<x<<endl;
        }
};

int main(){
    Base *ptr;
    Derived d;
    d.show(); // priority is derived
    //what if we want to print base show from d
    //ans
    d.Base::show();

    ptr = &d;
    ptr->show(); // here base will come not derived , as priority shifted to base class because of pointer

    //what if same situation but we want derived class output?
    // ptr->Derived::show();

    //Constructor and destructor
    Derived dd;

    return 0;
}