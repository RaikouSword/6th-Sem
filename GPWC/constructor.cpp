#include <iostream>
using namespace std;

class A{
    int x,y;
    public:
        A(); // declaration of default constructor
        A(int m); //declaration of parametrized constructor
        A(A &obj); //declaration of copy constructor    
        // ~A();   -> destructor
};
A::A(){
    x=y=0;
    cout<<"default constructor is invoked"<<endl;
}
A::A(int m){
    x=y=m;
    cout<<"parametrized constructor is invoked"<<endl;
}
A::A(A &obj){
    x = obj.x;
    y = obj.y;
    cout<<"copy constructor is invoked"<<endl;
}
int main(){
    A obj1;
    A obj2(5);
    A *obj3 = new A(10);
    A obj4(obj2);
    return 0;
}