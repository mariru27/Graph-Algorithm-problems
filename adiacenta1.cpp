#include <iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream myfileOut;
	ifstream myfileIn;
	
	myfileIn.open("adiacenta1.in");
	myfileOut.open("adiacenta1.out");
	int max = 0;
	int i,j;
	int adiacentMatrix[150][150]{};

	while (myfileIn >> i >> j) {
		adiacentMatrix[i][j] = 1;
		adiacentMatrix[j][i] = 1;
		if (max < i)
			max = i;
		else
			if (max < j)
				max = j;
	}

	for (int i = 1; i <= max; i++) {
		for (int j = 1; j <= max; j++) {
			myfileOut << adiacentMatrix[i][j] << " ";
		}
		myfileOut << endl;
	}

	myfileIn.close();
	myfileOut.close();
	return 0;
}