#include <iostream>
using namespace std;

class Rectangle{
    public:
    int length;
    int breadth;

    void input(int l,int b){
        length=l;
        breadth = b;
    }

    void perimeter(){
        cout<<"Perimeter: "<<2*(length+breadth)<<endl;
    }

    void area(){
        cout<<"Area: "<<length*breadth<<endl;
    }
    
};

int main(){
    Rectangle rect;
    int l,b;
    cin>>l>>b;
    rect.input(l,b);
    rect.perimeter();
    rect.area();
    return 0;
}
