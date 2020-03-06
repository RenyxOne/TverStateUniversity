#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class versh {
public:
    char name;
    int son;
    bool Used;
    vector<char> Sons;
    versh() { name = 0; son = 0; Used = false; Sons.resize(0); }
    friend istream& operator >> (istream& is, versh& a) {
        return is >> a.name >> a.son;
    }
    friend ostream& operator << (ostream& os, versh& a) {
        for (char i : a.Sons)
            os << i << ' ';
        return os;
    }
    void used() { Used = true; }
    bool isUsed() { return Used; }
    void addSon(versh& a) { Sons.push_back(a.name); son -= 1; a.used(); }
};

int main()
{
    int count;
    cin >> count;
    vector<versh> G(count);
    for (int i = 0; i < count; i++)
        cin >> G[i];

    for (int i = G.size() - 1; i >= 0; i -= 1)
    {
        if (G[i].son != 0) {
            int l = i + 1;
            while (G[i].son) { if (!G[l].isUsed() && l < G.size()) { G[i].addSon(G[l]); } l++; }
        }
    }
    for (versh i : G)
        if (!(i.Sons.empty())) cout << i.name << " -> " << i << endl;
}