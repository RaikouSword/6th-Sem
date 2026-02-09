#include <iostream>
using namespace std;

class Matrix {
private:
    int row, col;
    int **arr;

public:
    // Constructor
    Matrix(int r = 0, int c = 0) {
        row = r;
        col = c;

        if (row > 0 && col > 0) {
            arr = new int*[row];
            for (int i = 0; i < row; i++)
                arr[i] = new int[col];
        } else {
            arr = nullptr;
        }
    }

    // Input
    void input() {
        cin >> row >> col;
        arr = new int*[row];
        for (int i = 0; i < row; i++)
            arr[i] = new int[col];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> arr[i][j];
    }

    // Display
    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                cout << arr[i][j] << "\t";
            cout << endl;
        }
    }

    // Addition
    Matrix add(Matrix m) {
        Matrix res(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                res.arr[i][j] = arr[i][j] + m.arr[i][j];
        return res;
    }

    // Multiplication
    Matrix multiply(Matrix m) {
        Matrix res(row, m.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < m.col; j++) {
                res.arr[i][j] = 0;
                for (int k = 0; k < col; k++)
                    res.arr[i][j] += arr[i][k] * m.arr[k][j];
            }
        }
        return res;
    }

    // Transpose
    Matrix transpose() {
        Matrix t(col, row);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                t.arr[j][i] = arr[i][j];
        return t;
    }

    // Equality check
    bool isEqual(Matrix m) {
        if (row != m.row || col != m.col)
            return false;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (arr[i][j] != m.arr[i][j])
                    return false;

        return true;
    }

    // Diagonal matrix check
    bool isDiagonal() {
        if (row != col) return false;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (i != j && arr[i][j] != 0)
                    return false;

        return true;
    }

    // Unit matrix check
    bool isUnit() {
        if (row != col) return false;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (i == j && arr[i][j] != 1) return false;
                if (i != j && arr[i][j] != 0) return false;
            }
        return true;
    }

    // Sparse matrix check
    bool isSparse() {
        int zeroCount = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (arr[i][j] == 0)
                    zeroCount++;

        return zeroCount > (row * col) / 2;
    }

    // Interchange 1st and 3rd row
    void swapFirstThirdRow() {
        if (row < 3) return;

        for (int j = 0; j < col; j++) {
            int temp = arr[0][j];
            arr[0][j] = arr[2][j];
            arr[2][j] = temp;
        }
    }

    // Determinant (only for 2x2 and 3x3)
    int determinant() {
        if (row == 2 && col == 2) {
            return (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
        }

        if (row == 3 && col == 3) {
            return arr[0][0]*(arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1])
                 - arr[0][1]*(arr[1][0]*arr[2][2] - arr[1][2]*arr[2][0])
                 + arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]);
        }
        cout<<"Determinant not supported for this size\n";
        return 0;
    }
};

int main() {
    Matrix A, B;

    cout << "Enter matrix A (row col elements):\n";
    A.input();

    cout << "Enter matrix B (row col elements):\n";
    B.input();

    cout << "\nMatrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    return 0;
}
