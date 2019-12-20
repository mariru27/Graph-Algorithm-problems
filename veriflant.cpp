#include<iostream>
#include<fstream>
#include<queue>
#include<vector>

using namespace std;
ofstream myfileOut;
ifstream myfileIn;


void chain(int n, int** adiacentMatrix, int nr, int* node) {
	//display if a chain is elementar or not elementar or,is not a chain;
	int k = 0;
	bool distinct = true;

	if (nr <= 1)
		myfileOut << "NU";
	else
	{
		for (int i = 0; i < nr; i++) {
			if (adiacentMatrix[node[i]][node[i + 1]] == 1) {
				++k;
			}
		}
		if (k == (nr - 1)) {
			for (int i = 0; i < nr; i++) {
				for (int j = i + 1; j <= nr; j++) {
					if (node[i] == node[j])
						distinct = false;
				}
			}
			if(distinct == true)
				myfileOut << "ELEMENTAR";
			else
				myfileOut << "NEELEMENTAR";
		}

		if (k != (nr - 1))
			myfileOut << "NU";
	}

}

int main() {
	myfileIn.open("veriflant.in");
	myfileOut.open("veriflant.out");
	
	int** adiacentMatrix;
	int n, m;
	myfileIn >> n >> m;

	adiacentMatrix = new int* [200];
	for (int i = 0; i <= 200; i++) {
		adiacentMatrix[i] = new int[200];
	}


	int a, b;
	for (int j = 1; j <= m; j++) {
		myfileIn >> a >> b;
		adiacentMatrix[a][b] = 1;
		adiacentMatrix[b][a] = 1;
	}


	int numbChains;

	myfileIn >> numbChains;
	int nr;
	for (int i = 1; i <= numbChains; i++) {
		myfileIn >> nr;
		int node[200]{};
		for (int j = 0; j < nr; j++) {
			myfileIn >> node[j];
		}
		chain(n, adiacentMatrix, nr, node);
		if (i != numbChains)
			myfileOut << endl;
	}

	myfileIn.close();
	myfileOut.close();
	return 0;
}