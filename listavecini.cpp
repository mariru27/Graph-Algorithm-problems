#include <iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream myfileOut;
	ifstream myfileIn;
	
	myfileIn.open("listavecini.in");
	myfileOut.open("listavecini.out");
	int n;
	int a,b;
	int adiacentMatrix[150][150]{};

	int nrNeighborhood[10]{};
	myfileIn >> n;

	while (myfileIn >> a >> b) {
		adiacentMatrix[a][b] = 1;
		adiacentMatrix[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adiacentMatrix[i][j] != 0)
				++nrNeighborhood[i];
		}
	}

	int k1 = 0, k2 = 0;
	for (int i = 1; i < n; i++) {
		myfileOut << nrNeighborhood[i] << " ";
		for (int j = 1; j <= n; j++) {
			if (adiacentMatrix[i][j] != 0)
				myfileOut << j << " ";

			if (adiacentMatrix[n][j] != 0 && i == 1)
				k1++;

		}
		myfileOut << endl;
	}
	myfileOut << nrNeighborhood[n] << " ";
	--k1;
	for (int i = 0; i <= n; i++) {
		if (adiacentMatrix[n][i] != 0 && k1!=0) {
			myfileOut << i << " ";
			k1--;
		}else
		if (adiacentMatrix[n][i] != 0 && k1 == 0) {
			myfileOut << i;
		}


	}


	myfileIn.close();
	myfileOut.close();
	return 0;
}