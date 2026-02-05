#include<iostream>
using namespace std;


class student{
    int reg_no;
    char name[100];
    float marks[5];

    public:
    void input();
    void display();
};

void student::input(){
    cout<<"Enter registration no.: "<<endl;
    cin>>reg_no;
    cout<<"Enter name: "<<endl;
    cin>>name;
    cout<<"Enter the marks of 5 subjects: "<<endl;
    for(int i=0;i<5;i++){
        cin>>marks[i];
    }
}

void student::display(){
    cout<<"Registration no.: "<<reg_no<<endl;
    cout<<"Name: "<<name<<endl;
    for(int i=0;i<5;i++){
        cout<<"Marks"<<"["<<i+1<<"]: "<<marks[i];
    }
}

int main(){
    student st[5];

    //input
    for(int i=0;i<5;i++){
        st[i].input();
    }

    //display
    for(int i=0;i<5;i++){
        st[i].display();
    }

    return 0;
}