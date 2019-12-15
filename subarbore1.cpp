#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> vec;
int n, m;
int t[10000]{};



int main() {
	ifstream in;
	ofstream out;
	in.open("subarbore1.in");
	out.open("subarbore1.out");


	in >> n;
	in >> m;
	for (int i = 1; i <= n; i++) {
		in >> t[i];
	}
	
	vector<int> vec;
	queue<int> coada;
	bool findSol = false;
	coada.push(m);
	int node = 0;
	while (!coada.empty()){
		bool find = false;
		node = coada.front();
		coada.pop();
		for (int i = 1; i <= n; i++) {
			if (t[i] == node) {
				find = true;
				coada.push(i);
			}
		}
		if (find == false)
			vec.push_back(node);
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		out << vec[i];
		if (i != vec.size() - 1) {
			out << " ";
		}
	}
	in.close();
	out.close();
	return 0;
}