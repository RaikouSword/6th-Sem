#include <bits/stdc++.h>
using namespace std;

class Ls{
    public:
    int arr[6];
    int l = INT_MIN;
    int sl = INT_MIN;

    void ans(){
        for(int x=0;x<6;x++){
            if(arr[x]>=l){
                sl=l;
                l=arr[x];
            }else if(arr[x]>=sl && arr[x]<l){
                sl=arr[x];
            }else{
                continue;
            }
        }
    }
    
    void display(){
        cout<<"Largest: "<<l<<endl;
        cout<<"Second Largest: "<<sl<<endl;
    }
};

int main(){
    Ls ls;
    for(int x=0;x<6;x++){
        cin>>ls.arr[x];
    }
    ls.ans();
    ls.display();
    return 0;
}