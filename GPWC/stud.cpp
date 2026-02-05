#include <iostream>
using namespace std;

class Student{
    public:
    int reg_no;
    char name[100];
    float marks[5];
    int total_mark=0;
    float percentage = 0.0;
    char grade;

    void cal(){
        for(int x=0;x<5;x++){
            total_mark+=marks[x];
        }
        percentage = (total_mark/500)*100;
        if(percentage>=95 && percentage<=100) grade = 'O';
        else if(percentage>=90 && percentage<95) grade='A';
        else if(percentage>=80 && percentage<90) grade='B';
        else if(percentage>=70 && percentage<80) grade='C';
        else if(percentage>=60 && percentage<70) grade='D';
        else grade='F';
    }

    void input(){
        cout<<"Enter registration no.: "<<endl;
        cin>>reg_no;
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter the marks of 5 subjects: "<<endl;
        for(int i=0;i<5;i++){
            cin>>marks[i];
        }
    }

    void display(int reg_no){
        for(int x=0;x<5;x++){

        }
        cout<<"Name: "<<name<<endl;
        for(int i=0;i<5;i++){
            cout<<"Marks"<<"["<<i+1<<"]: "<<marks[i];
        }
        cout<<"Percentage: "<<percentage<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
};

int main(){
    
}