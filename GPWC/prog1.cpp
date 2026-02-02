#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    char ch;
    cin>>ch;
    switch(ch){
        case '+':cout<<"Sum: "<<x+y<<endl;
        break;
        case '-':cout<<"Diff: "<<x-y<<endl;
        break;
        case '*':cout<<"Prod: "<<x*y<<endl;
        break;
        case '/':cout<<"Div: "<<x/y<<endl;
        break;
        default: cout<<"Invalid"<<endl;
        break;
    }    
    return 0;
}