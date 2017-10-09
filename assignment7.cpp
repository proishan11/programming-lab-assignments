#include<iostream>
using namespace std;

class Matrix{
	private:
		int m, n;
		int matrix[100][100], t_matrix[100][100];
	public:
		Matrix(int rows, int cols){
			m = rows;
			n = cols;
			for(int i=0; i<m; ++i)
				for(int j=0; j<n; ++j)
					matrix[i][j] = 0;
		}

		void fillMatrix(){
			cout << "Enter data in matrix" << endl;
			for(int i=0; i<m; ++i)
				for(int j=0; j<n; ++j){
					cout << "Enter value of a["<<i<<"]["<<j<<"]" << endl;
					cin >> matrix[i][j];
				}
			printMatrix();
		}

		void printMatrix(bool transposed = false){
			if(!transposed)
				cout << "Your current matrix is" << endl;
			else{cout << "The transposed matrix is\n";}
			for(int i=0; i<m; ++i){
				for(int j=0; j<n; ++j)
					cout << matrix[i][j] << " ";
				cout << endl;
			}
		}

		Matrix transposed(){
			Matrix temp(n,m);
			for(int i=0; i<n; ++i){
				for(int j=0; j<m; ++j){
					temp.matrix[i][j] = matrix[j][i];
					cout << temp.matrix[i][j] << " ";
				}
				cout << endl;
			}
			return temp;
		}

		Matrix operator *(Matrix b){
			Matrix temp(m,b.n);
			for(int i=0; i<m; ++i)
				for(int j=0; j<b.n; ++j)
					for(int k=0; k<n; ++k)
						temp.matrix[i][j] += matrix[i][k]*b.matrix[k][j];
			return temp;
		}
};

int main(){
	int m, n, x, y;
	cout << "Enter m and n for first matrix" << endl;
	cin >> m >> n;
	cout << "Enter x and y for second matrix" << endl;
	cin >> x >> y;
	Matrix a(m,n);
	Matrix b(x,y);
	Matrix tr(y,x);
	Matrix result(m, x);
	a.fillMatrix();
	b.fillMatrix();
	tr = b.transposed();
	result = a*tr;
	result.printMatrix();
}