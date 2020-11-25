#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double Pi = 3.1415926535897932384626433832795;

vector<vector<pair<double, double>>> tablichka(6);

void init_tablichka() {
	//tablichka(N,(Корень, Вес))   Значения корней и весов для конкретного n 

	//pair(Корень, Вес) 

	//n = 1;
	tablichka[0].push_back(make_pair(0, 2));

	//n = 2;
	tablichka[1].push_back(make_pair(-0.5773503, 1));
	tablichka[1].push_back(make_pair(0.5773503, 1));

	//n = 3;
	tablichka[2].push_back(make_pair(-0.7745967, 0.5555556));
	tablichka[2].push_back(make_pair(0, 0.8888889));
	tablichka[2].push_back(make_pair(0.7745967, 0.5555556));

	//n = 4;
	tablichka[3].push_back(make_pair(-0.8611363, 0.3478548));
	tablichka[3].push_back(make_pair(-0.3399810, 0.6521451));
	tablichka[3].push_back(make_pair(0.3399810, 0.6521451));
	tablichka[3].push_back(make_pair(0.8611363, 0.3478548));

	//n = 5;
	tablichka[4].push_back(make_pair(-0.9061798, 0.4786287));
	tablichka[4].push_back(make_pair(-0.5384693, 0.2369269));
	tablichka[4].push_back(make_pair(0, 0.5688888));
	tablichka[4].push_back(make_pair(0.5384693, 0.2369269));
	tablichka[4].push_back(make_pair(0.9061798, 0.4786287));

	//n = 6;
	tablichka[5].push_back(make_pair(-0.9324700, 0.1713245));
	tablichka[5].push_back(make_pair(-0.6612094, 0.3607616));
	tablichka[5].push_back(make_pair(-0.2386142, 0.4679140));
	tablichka[5].push_back(make_pair(0.2386142, 0.4679140));
	tablichka[5].push_back(make_pair(0.6612094, 0.3607616));
	tablichka[5].push_back(make_pair(0.9324700, 0.1713245));
}

double f1(double x) {
	return 12 * (x * x * x * x * x);
}

double f2(double x) {
	return x * x * sin(x);
}

double gauss(double a, double b, int n, double (*f)(double)) {
	double Xi, S = 0.0;

	for (int i = 0; i < n; i++)
	{
		Xi = ((a + b) / 2) + ((b - a) / 2) * tablichka[n-1][i].first;
		S += tablichka[n-1][i].second * f(Xi);
	}
	return ((b - a) / 2) * S;
}

double Runge(double a, double b, int n, double (*f)(double)) {
	int k = 2 * n - 1;
	
	double In = gauss(a, b, n, f);
	double I2n = gauss(a, b, 2*n, f);

	return fabs((In - I2n) / (pow(2, k) - 1));
	
}

int main() {
	setlocale(LC_ALL, "Russian");
	int mode, n;
	init_tablichka();

	do {
		cout << "Выберите интегралл\n1) 12x^5 * dx\tот -1 до 3\n2) x^2 * sin(x) * dx\tот 0 до Pi/2" << endl;
		cin >> mode;
	} while (mode != 1 && mode != 2);

	do {
		cout << "Введите N из отрезка [1,3]" << endl;
		cin >> n;
	} while (n <= 0 || n >= 4);
	cout << fixed;
	cout.precision(6);
	if (mode == 1) {
		
		cout << gauss(-1, 3, n, f1) << "\tТочное значение: 1456" << endl;
		cout << "Погрешность по правилу Рунге:\t" << Runge(-1, 3, n, f1);
	}
	else {
		cout << gauss(0, Pi / 2, n, f2) << "\tТочное значение: Pi-2 ~ 1.141592653589793..." << endl;
		cout << "Погрешность по правилу Рунге:\t" << Runge(0, Pi / 2, n, f2);
	}
}