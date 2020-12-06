#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void check_diagonal(const vector<vector<double>> &matrix) {
	bool flag = true;
	for (int i = 0; i < matrix.size(); i++) {
		double Aii = fabs(matrix[i][i]);
		double sumAij = 0;
		for (int j = 0; j < matrix.size(); j++) {
			if (j == i) continue;
			sumAij += fabs(matrix[i][j]);
		}
		if (Aii < sumAij) flag = false;
	}
	if (flag) cout << endl << "Матрица обладает свойством диагонального преобладания" << endl << endl;
	else cout << endl << "Матрица НЕ обладает свойством диагонального преобладания" << endl << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество неизвестных" << endl;
	cin >> n;
	vector<vector<double>> A(n,vector<double>(n+1));
	vector<double> B(n);


	cout << "Заполните матрицу, построчно\nВведите все коэффициенты X-iтых и значение уравнения" << endl;
	
	for (int i = 0; i < n; i++) {
		cout << "Введите "<< i+1 << " уравнение" << endl;
		for (int j = 0; j < n+1; j++)
			cin >> A[i][j];
	}

	cout << "\nВы ввели следующую СЛАУ:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (A[i][j] > 0)
				cout << '+' << A[i][j] << "X." << j+1 << ' ';
			else 
				cout << A[i][j] << "X." << j + 1 << ' ';
		cout << "= " << A[i][n] << endl;
	}

	check_diagonal(A);

	cout << "Приведём систему к виду удобную для итерации:" << endl;
	for (int i = 0; i < n; i++) {
		if (A[i][i] > 0)
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				A[i][j] *= -1;
			}
		else {
			A[i][i] *= -1;
			A[i][n] *= -1;
		}

		double tmp = A[i][0];
		A[i][0] = A[i][i];
		A[i][i] = tmp;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n + 1; j++)
			A[i][j] /= A[i][0];
		A[i][0] = 1;
	}

	for (int i = 0; i < n; i++) {
		cout << "X." << i + 1 << " = " << A[i][n] << ' ';
		for (int j = 1, k = 0; j < n; j++, k++) {
			if (k == i) k++;
			if (A[i][j] > 0)
				cout << '+' << A[i][j] << "X." << k+1 << ' ';
			else
				cout << A[i][j] << "X." << k+1 << ' ';
		}
		cout << endl;
	}

	vector<double> Xk(n);
	double eps;

	cout << "Введите начальные приближения Xi" << endl;
	for (int i = 0; i < n; i++) cin >> Xk[i];
	cout << "Введите точность до которой нужно вычислить (не менее 1 * 10^(-15) )" << endl;
	cin >> eps;

	vector<double> Xk_plus_1(n);
	int iteraciya = 0;

	cout << 'i';
	for (int i = 0; i < n; i++) cout << "\t\tX." << i + 1;
	cout << endl;
	
	cout << iteraciya;
	cout << fixed;
	for (int i = 0; i < n; i++) cout << setprecision(12) << "\t" << Xk[i];
	cout << endl;

	bool flag = true;
	while (flag) {
		flag = false;
		
		iteraciya++;
		for (int i = 0; i < n; i++) {
			Xk_plus_1[i] = A[i][n];
			for (int j = 1, k = 0; j < n; j++, k++) {
				if (k == i) k++;
				Xk_plus_1[i] += A[i][j] * Xk[k];
			}
		}

		for (int i = 0; i < n; i++) {
			if (fabs(Xk[i] - Xk_plus_1[i]) > eps) flag = true;
			Xk[i] = Xk_plus_1[i];
		}

		cout << iteraciya;
		for (int i = 0; i < n; i++) cout << "\t" << Xk[i];
		cout << endl;

	}

	cout << "Ответ:" << endl;
	for (int i = 0; i < n; i++) cout << "X." << i + 1 << " = " << Xk[i] << endl;
	
}
//Пример 4 10 1 1 5 12 2 10 1 1 13 2 2 10 1 14 2 4 7 15 13 1.2 0 0 0 0.0000001
//Точные значения для примера X1 = 1, X2 = 1, X3 = 1, X4 = 0;