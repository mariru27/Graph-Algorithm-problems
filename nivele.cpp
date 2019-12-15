#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("nivele.in");
	out.open("nivele.out");
	int n, m;
	int t[10000]{};
	in >> n;
	for (int i = 1; i <= n; i++) {
		in >> t[i];
	}
	in >> m;
	int val = 0, k = 0;
	for (int i = 1; i <= m; i++) {
		k = 1;
		in >> val;
		while (t[val] != 0) {
			k++;
			
			val = t[val];
		}
		out << k ;
		if (m != i)
			out << endl;
	}
	
	in.close();
	out.close();
	return 0;
}