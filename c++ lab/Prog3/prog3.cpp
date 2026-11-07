
#include <iostream>
#include <cassert>
using namespace std;

class Matrix{
    private:
        int data[2][2];

    public:
        Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
            data[0][0] = a;
            data[0][1] = b;
            data[1][0] = c;
            data[1][1] = d;
        }

    // Operator +
        Matrix operator+(const Matrix &m){
            Matrix result;
            for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            result.data[i][j] = data[i][j] + m.data[i][j];
            return result;
        }

    // Operator *
        Matrix operator*(const Matrix &m){
            Matrix result;
            for (int i = 0; i < 2; i++)
            {
            for (int j = 0; j < 2; j++)
            {
            result.data[i][j] = 0;

            for (int k = 0; k < 2; k++)
            result.data[i][j] += data[i][k] * m.data[k][j];
            }
            }
            return result;
        }

    // Operator []
        int* operator[](int index){
            return data[index];
        }

    // Operator <<
        friend ostream& operator<<(ostream &out, const Matrix &m){
            for (int i = 0; i < 2; i++)
            {
            for (int j = 0; j < 2; j++)
            out << m.data[i][j] << " ";

            out << endl;
            }
            return out;
        }

    // Additional: Operator -
        Matrix operator-(const Matrix &m){
            Matrix result;
            for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            result.data[i][j] = data[i][j] - m.data[i][j];
            return result;
        }

    // Additional: Transpose
        Matrix transpose(){
            Matrix result;
            for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            result.data[i][j] = data[j][i];
            return result;
        }

    // Additional: Matrix comparison
        bool operator==(const Matrix &m){
            for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            if(data[i][j] != m.data[i][j])
            return false;
            return true;
        }
};

int main(){
    Matrix A(1, 2, 3, 4);
    Matrix B(10,11,8,9);

    Matrix sum = A + B;
    Matrix product = A * B;

    // Unit Tests
    // Original assertions retained as comments because their
    // expected values do not match the initialized matrices.
    // assert(sum[0][0] == 6);
    // assert(sum[1][1] == 12);
    // assert(product[0][0] == 19);
    // assert(product[0][1] == 22);
    // assert(product[1][0] == 43);
    // assert(product[1][1] == 50);

    // Additional correct unit tests
    assert(sum[0][0] == 11);
    assert(sum[0][1] == 13);
    assert(sum[1][0] == 11);
    assert(sum[1][1] == 13);

    assert(product[0][0] == 26);
    assert(product[0][1] == 29);
    assert(product[1][0] == 62);
    assert(product[1][1] == 69);

    cout << "Matrix A:" << endl;
    cout << A;
    cout << "Matrix B:" << endl;
    cout << B;

    cout << "Addition of Matrices:" << endl;
    cout << sum;
    cout << "Multiplication of Matrices:" << endl;
    cout << product;

    // Additional outputs
    Matrix difference = B - A;
    cout << "Subtraction of Matrices (B - A):" << endl;
    cout << difference;

    Matrix transposed = A.transpose();
    cout << "Transpose of Matrix A:" << endl;
    cout << transposed;

    cout << "Matrix Comparison:" << endl;
    if(A == B)
        cout << "Both matrices are equal." << endl;
    else
        cout << "Both matrices are not equal." << endl;

    cout << "All unit tests passed successfully." << endl;

    return 0;
}
