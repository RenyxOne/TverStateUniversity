#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class edge {
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
	edge() { from = 0; to = 0; w = 0; }
	~edge() { from = 0; to = 0; w = 0; }
	edge(const edge& a) {
		from = a.from;
		to = a.to;
		w = a.w;
	}
	edge(char from, char to, int w) {
		this->from = from;
		this->to = to;
		this->w = w;
	}
	void swap(edge& a) {
		edge temp(*this);
		*this = a;
		a = temp;
	}
	edge operator = (const edge& a) {
		from = a.from;
		to = a.to;
		w = a.w;
		return *this;
	}
	bool operator > (const edge& a) {
		return (w > a.w);
	}
	bool operator < (const edge& a) {
		return (w < a.w);
	}
	friend ostream& operator<< (ostream& os, edge& a) {
		return os << '(' << a.from << ',' << a.to << ',' << a.w << ')';
	}
	friend istream& operator>> (istream& is, edge& a)
	{
		return is >> a.from >> a.to >> a.w;
	}
};
class graph {
public:
	vector<vector<int>> Graph;
	vector<char> V;

	graph() { Graph.resize(26); }
	graph(vector<edge>& E) {
		for (int i = 0; i < E.size(); i++)
			*this = *this + E[i];
		getVersh();
	}
	graph(const graph &a) {
		Graph = a.Graph;
		V = a.V;
	}
	~graph() { Graph.resize(0); V.resize(0); }
	void getVersh() {
		vector<char> temp;
		for (int i = 0; i < Graph.size(); i++)
			if (!Graph[i].empty()) temp.push_back(i + 'a');
		V = temp;
	}
	char getV() {
		return V[0];
	}
	vector<vector<int>> getGraph() {
		return Graph;
	}

	graph doGraph(vector<edge>& E) {
		graph temp;
		for (int i = 0; i < E.size(); i++)
			temp = temp + E[i];
		temp.getVersh();
		return temp;
	}
	graph operator + (edge& a) {
		Graph[a.From()-'a'].push_back(a.To()-'a');
		Graph[a.To()-'a'].push_back(a.From()-'a');
		getVersh();
		return *this;
	}
	graph& operator = (const graph &a) {
		Graph = a.Graph;
		V = a.V;
		return *this;
	}
	friend ostream& operator << (ostream& os, const graph& a) {
		for (int i : a.V)
		{
			os << (char)i << " -> ";
			for (int j : a.Graph[i-'a'])
				os << (char)(j+'a')<< ' ';
			os << endl;
		}
		return os;
	}
};

void BubbleSort(vector<edge>& E) {
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

bool HaveCycle(graph &G, int U, int prevU, vector<bool> &done) {
	done[U] = true;
	for (int v = 0; v < G.Graph[U].size(); v++)
	{
		if (!done[G.Graph[U][v]]) {
			if (HaveCycle(G, G.Graph[U][v], U, done)) return true;
		}
		else if (G.Graph[U][v] !=prevU)
			return true;
	}
	return false;
}

int main()
{
	int cE;

	cout << "Vvedite kolichestvo reber" << endl;
	cin >> cE;

	vector<edge> E(cE);

	for (int i = 0; i < E.size(); i++)
		cin >> E[i];

	graph G;

	//Сортируем по весу
	BubbleSort(E);
	vector<edge> T;
	//Подбираем ребра
	for (int i = 0; i < E.size(); i++) {
		vector<bool> temp(26, 0);
		graph tG = G + E[i];
		if (!HaveCycle(tG, E[0].From()-'a', -1, temp)) {
			G = tG;
			T.push_back(E[i]);
		}
	}
	cout << "Minimalnoe ostavnoe derevo" << endl;

	//Вывод ребер
	/*for (int i = 0; i < T.size(); i++)
		cout << T[i] << endl;*/

	//Вывод списка смежности
	cout << G;
}