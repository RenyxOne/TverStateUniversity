#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class node {
private:
	unsigned char from;
	unsigned char to;
	int w;
public:
	int Weight() {
		return w;
	}
	char From() {
		return from;
	}
	char To() {
		return to;
	}
	node() {};
	node(const node& a) {
		from = a.from;
		to = a.to;
		w = a.w;
	}
	node(char from, char to, int w) {
		this->from = from;
		this->to = to;
		this->w = w;
	}
	void swap(node& a) {
		node temp(*this);
		*this = a;
		a = temp;
	}
	node operator = (const node& a) {
		from = a.from;
		to = a.to;
		w = a.w;
		return *this;
	}
	bool operator > (const node& a) {
		return (w > a.w);
	}
	bool operator < (const node& a) {
		return (w < a.w);
	}
	friend ostream& operator<< (ostream& os, node& a) {
		return os << '(' << a.from << ',' << a.to << ',' << a.w << ')';
	}
	friend istream& operator>> (istream& is, node& a)
	{
		return is >> a.from >> a.to >> a.w;
	}
};

void BubbleSort(vector<node>& E) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < E.size() - 1; i++)
			if (E[i] > E[i + 1]) {
				flag = true;
				E[i].swap(E[i + 1]);
			}
	}
}

vector<vector<int>> Smezh(vector<node>& E)
{
	vector<vector<int>> G(26);
	for (int i = 0; i < E.size(); i++) {
		G[E[i].From() - 'a'].push_back(E[i].To() - 'a');
		G[E[i].To() - 'a'].push_back(E[i].From() - 'a');
	}
	return G;
}

bool HaveCycle(vector<vector<int>> G) {
	if (1)
	return false;
}

int main()
{
	int cE;

	cout << "Input |E|" << endl;
	cin >> cE;

	vector<vector<int>> G(26);
	vector<node> E(cE);

	for (int i = 0; i < E.size(); i++)
		cin >> E[i];

	G = Smezh(E);

	vector<char> V;
	for (int i = 0; i < G.size(); i++)
		if (!G[i].empty()) V.push_back(i + 'a');

	/*cout << "Graph sostoit iz vershin" << endl;
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ' ';
	cout << endl;*/

	//Сортируем по весу
	BubbleSort(E);

	for (int i = 0; i < E.size(); i++)
		cout << E[i] << endl;
}