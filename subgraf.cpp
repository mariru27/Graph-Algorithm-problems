#include <iostream>
#include<fstream>
#include<queue>
using namespace std;

bool verificaPrim(int n) {
	int i = 1;
	int prim = 0;
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	while ((i <= (n / 2)) && prim < 2) {
		++i;
		if ((n % i) == 0)
			prim++;
	}


	if (prim == 0)
		return true;
	else
		return false;
}


int main() {
	ofstream myfileOut;
	ifstream myfileIn;

	myfileIn.open("subgraf.in");
	myfileOut.open("subgraf.out");

	int n;
	int a, b;
	int adiacentMatrix[150][150]{};

	int nrNeighborhood[10]{};
	myfileIn >> n;

	while (myfileIn >> a >> b) {
		adiacentMatrix[a][b] = 1;
		adiacentMatrix[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (verificaPrim(i) == true) {
			for (int j = 1; j <= n; j++) {
				adiacentMatrix[i][j] = 0;
				adiacentMatrix[j][i] = 0;
			}
		}
	}
	int edges = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adiacentMatrix[i][j] == 1) {
				++edges;
				adiacentMatrix[i][j] = 0;
				adiacentMatrix[j][i] = 0;
			}
		}
	}
	myfileOut << edges;
	myfileIn.close();
	myfileOut.close();
	return 0;
}