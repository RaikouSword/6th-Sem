#include <iostream>
using namespace std;

class Display{ //virtual class 
    public:
        void show(){
            cout<<"Display class"<<endl;
        }
};

class A: public virtual Display{
    public:
        void show1(){
            cout<<"Class A"<<endl;
        }
};

class B: virtual public  Display{
    public:
        void show2(){
            cout<<"Class B"<<endl;
        }
};

class D: public A, public B{
    public:
        void show3(){
            cout<<"Class D"<<endl;
        }
};

int main(){
    D d;
    // d.show();
    d.show();
    return 0;
}