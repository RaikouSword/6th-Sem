#include <iostream>
using namespace std;

class Matrix{
    private:
    int row, col;
    int **arr;

    public:
    Matrix(int r=0,int c=0){
        row=r;
        col=c;
        if(r>0 && c>0){
            arr = new int*[row];
            for(int x=0;x<row;x++){
                arr[x] = new int[col];
            }
        }else{
            arr = NULL;
        }
    }
    void input(){
        cin>>row>>col;
        arr = new int*[row];
        for(int x=0;x<row;x++){
                arr[x] = new int[col];
            }
        for (int x=0;x<row;x++){
            for(int y=0;y<col;y++){
                cin>>arr[x][y];
            }
        }
    }

    void display(){
        for (int x=0;x<row;x++){
            for(int y=0;y<col;y++){
                cout<<arr[x][y]<<"\t";
            }
            cout<<"\n";
        }
    }

    Matrix add(Matrix m){
        Matrix res(row, col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                res.arr[i][j] = arr[i][j] + m.arr[i][j];
        return res;
    }
    
    Matrix multiply(Matrix m){
        Matrix res(row, m.col);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < m.col; j++) {
                res.arr[i][j] = 0;
                for(int k = 0; k < col; k++)
                    res.arr[i][j] += arr[i][k] * m.arr[k][j];
            }
        }
        return res;
    }

    Matrix transpose(){
        Matrix t(col, row);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                t.arr[j][i] = arr[i][j];
        return t;
    }

    bool isEqual(Matrix m){
        if(row != m.row || col != m.col)return false;

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(arr[i][j] != m.arr[i][j])return false;
        return true;
    }

    bool isDiagonal(Matrix m){
        if(row != col) return false;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(i != j && arr[i][j] != 0) return false;

        return true;
    }

    bool isUnit (Matrix m){
        if(row != col) return false;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if(i == j && arr[i][j] != 1) return false;
                if(i != j && arr[i][j] != 0) return false;
            }
        return true;
    }

    void swap(){
        if(row < 3) return;
        for(int j = 0; j < col; j++) {
            int temp = arr[0][j];
            arr[0][j] = arr[2][j];
            arr[2][j] = temp;
        }
    }
};

int main(){

    return 0;
}