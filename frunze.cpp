#include<iostream>
#include<fstream>
#include<memory>

using namespace std;


int main() {
	ifstream in;
	ofstream out;
	in.open("frunze.in");
	out.open("frunze.out");

	unique_ptr<int[]> t(new int[101]{});
	unique_ptr<int[]> frequencyTable(new int[101]{});

	int n, root = 0;
	in >> n;
	for (int i = 1; i <= n; i++) {
		in >> t[i];
		if (t[i] == 0)
			root = i;
	}

	int tata;
	for (int i = 1; i <= n; i++) {
		tata = t[i];
		frequencyTable[i]++;
		while (tata != 0) {
			frequencyTable[tata]++;
			tata = t[tata];
		}
	}

	out << root << endl;

	int nrFrunze = 0;
	for (int i = 0; i <= n; i++) {
		if (frequencyTable[i] == 1) {
			nrFrunze++;
		}

	}

	out << nrFrunze << endl;
	for (int i = 0; i <= n; i++) {
		if (frequencyTable[i] == 1) {
			out << i;
			if (i != n)
				out << " ";
		}
	}
	in.close();
	out.close();
	return 0;
}