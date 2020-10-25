#include <iostream>
#include <vector>
using namespace std;

double f1(double x) {
	return 1.0 / x;
}

double f2(double x) {
	return x * x * x * x;
}

double formulaGaussa(vector<double>& x, vector<double>& y, double x1) {
	double y1 = 0;

	int x0 = 0;
	while (x0 < x.size() && x1 > x[x0]) //Обычно вторая формула Гаусса применяется при x < x0
		x0++; 

	if (x0 == 0 || x0 == x.size()) {
		cout << "\n\nНеправильное значение x\n\n" << endl;
		return INT_MAX;
	}

	cout << "Для x = " << x1 << " в качестве x0 выбран узел " << x[x0] << " с индексом " << x0 << endl;
	double h = x[1] - x[0];
	double q = (x1 - x[x0]) / h;

	int n = (x.size() - (x0+1) < x0 ? x.size() - (x0+1) : x0); //выбирается максимальный порядок многочлена Pn(x)

	vector<vector<double>> tablica(2*n+1, vector<double>(2 * n + 2));

	for (int i = x0 - n, k = 0; i <= x0 + n; i++, k++) {
		tablica[k][0] = x[i];
		tablica[k][1] = y[i];
	}

	for (int j = 2; j < 2 * n + 2; j++)
		for (int i = 0; i < 2 * n - (j - 2); i++)
			tablica[i][j] = tablica[i + 1][j - 1] - tablica[i][j - 1];

	cout << "\nТаблица выглядит так:\ni\tx\t\y";
	for (int i = 0; i < 2 * n; i++) cout << "\t/\\" << i + 1 << "y";
	cout << endl;

	for (int i = 0; i < tablica.size(); i++) {
		cout << i - n << "\t";
		cout << fixed;
		for (int j = 0; j < tablica[i].size() - i; j++) {
			cout.precision(2);
			cout << tablica[i][j] << '\t';
		}
		cout << endl;
	}

	y1 = tablica[tablica.size() / 2][1]; // y0
	double chislitel = q;
	double znamenatel = 1;
	int chAddNum = 1;
	int znAddNum = 2;
	bool ch = true;
	int deltaY = 1; //Порядок конечной разности дельта y 

	for (int i = tablica.size()/2 - 1; i >= 0;) {
		y1 += (chislitel/znamenatel) * tablica[i][1 + deltaY];

		if (ch)
			chislitel *= (q + chAddNum);
		else {
			chislitel *= (q - chAddNum);
			chAddNum++;
			i--;
		}

		znamenatel *= znAddNum;
		deltaY++;
		znAddNum++;
		ch = !ch;
	}

	return y1;
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество узлов" << endl;
	int n = 0;
	while (n <= 1) cin >> n; //Количество узлов строго больше 1
	vector<double> x(n);
	vector<double> y(n);

	cout << "Введите " << n << " значений x" << endl;

	for (int i = 0; i < n; i++) cin >> x[i];
	
	while (true) {
		cout << "Выберите режим:\n1) Посчитать значения y по формуле y = 1/x\n2) Посчитать значения y по формуле y = x^4\n3) Ввести значения y вручную" << endl;
		int mode;
		cin >> mode;
		if (mode == 1) {
			for (int i = 0; i < n; i++)
				y[i] = f1(x[i]);
			break;
		}
		else if (mode == 2) {
			for (int i = 0; i < n; i++)
				y[i] = f2(x[i]);
			break;
		}
		else if (mode == 3) {
			cout << "Введите " << n << " значений y" << endl;
			for (int i = 0; i < n; i++)
				cin >> y[i];
			break;
		}
		else
			cout << "Неправильный режим, попробуйте снова" << endl;
	}

	cout << endl;

	cout << "Таблица значений:\nx\ty" << endl;
	for (int i = 0; i < n; i++) cout << x[i] << '\t' << y[i] << endl;

	cout << endl;
	
	while (true) {
		cout << "Введите значение x" << endl;
		double x1;
		cin >> x1;

		double res = formulaGaussa(x, y, x1);
		if (res != INT_MAX) {
			cout.precision(5);
			cout << "\nВ точке x = " << x1 << " примерное значение y = " << res << endl;
		}
	}

}