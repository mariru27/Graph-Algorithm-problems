#include <iostream>
#include<fstream>
#include<queue>
using namespace std;
struct MyStruct {
	int val1 = 0;
	int val2 = 0;
}grad[100];

int k = 0,n;

bool edgeWasBefore(int a, int b) {
	
	for (int i = 0; i < n; i++) {
		if (grad[i].val1 == a && grad[i].val2 == b)
			return true;
	}
	return false;
}

int main() {
	ofstream myfileOut;
	ifstream myfileIn;

	myfileIn.open("graf_partial_2.in");
	myfileOut.open("graf_partial_2.out");

	int a, b;
	int adiacentMatrix[150][150]{};
	int maxGrad = 0;
	int index = 0;
	int gradMaxim[151]{};

	myfileIn >> n;

	while (myfileIn >> a >> b) {
		adiacentMatrix[a][b] = 1;
		adiacentMatrix[b][a] = 1;
		if (edgeWasBefore(a, b) == false) {
			++gradMaxim[a];
			++gradMaxim[b];

			if (maxGrad < gradMaxim[a])
				maxGrad = gradMaxim[a];
			if (maxGrad < gradMaxim[b])
				maxGrad = gradMaxim[b];
		}
		
		grad[k].val1 = a;
		grad[k].val2 = b;
		++k;
	}

	int deletedEdges = 0;
	for (int i = 1; i <= 150; i++) {
		if (gradMaxim[i] == maxGrad) {
			for (int j = 0; j <= n; j++) {
				if (adiacentMatrix[i][j] == 1)
					++deletedEdges;
				adiacentMatrix[i][j] = 0;
				adiacentMatrix[j][i] = 0;
			}
		}
	}



	myfileOut << deletedEdges << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			myfileOut << adiacentMatrix[i][j];
			if (n != j)
				myfileOut << " ";
		}
		if (n != i)
			myfileOut << endl;
	}

	myfileIn.close();
	myfileOut.close();
	return 0;
}