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
        total_mark=0;
        for(int x=0;x<5;x++){
            total_mark+=marks[x];
        }
        percentage = (total_mark/500.0)*100;
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

    void display(){
        cout<<"\nName: "<<name<<"\nPercentage: "<<percentage<<"%\nGrade: "<<grade<<endl;
    }
};

void topper(Student s[],int n){
    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].percentage > s[topperIndex].percentage) {
            topperIndex = i;
        }
    }
    cout<<"\nTopper: "<<endl;
    cout<<"Name: "<<s[topperIndex].name<<" with "<<s[topperIndex].percentage<<"%"<<endl;
}

int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << (i + 1) << ":";
        s[i].input();
    }
    int search_reg;
    bool found = false;
    cout<<"\nSearch Record: "<<endl;
    cout<<"Enter registration number to search: ";
    cin >> search_reg;
    for (int i = 0; i < n; i++) {
        if (s[i].reg_no == search_reg) {
            s[i].display();
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found!" << endl;
    topper(s, n);

    return 0;
}