#include <iostream>
using namespace std;

class Base1{
    public:
        int x=100;
        Base1(){
            cout<<"Base1 class constructor"<<endl;
        }
        ~Base1(){
            cout<<"Base1 class destructor"<<endl;
        }
        void show(){
            cout<<"Base1 class: "<<"x="<<x<<endl;
        }
};

class Base2{
    public:
        int x=300;
        Base2(){
            cout<<"Base2 class constructor"<<endl;
        }
        ~Base2(){
            cout<<"Base2 class destructor"<<endl;
        }
        void show(){
            cout<<"Base2 class: "<<"x="<<x<<endl;
        }
};

class Derived: public Base1, public Base2{
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
    Derived d;
    // d.show();
    Base1 *ptr1;
    Base2 *ptr2;
    ptr1 = &d;
    ptr2 = &d;
    ptr1->show();
    ptr2->show();
    return 0;
}