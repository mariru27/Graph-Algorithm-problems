#include <iostream>
#include<fstream>
#include<queue>
#include<vector>

using namespace std;
ofstream myfileOut;
ifstream myfileIn;


int main() {
	myfileIn.open("bifrunze.in");
	myfileOut.open("bifrunze.out");
	int n;
	myfileIn >> n;
	int left = 0, right = 0, currentNode = 0;
	for (int i = 1; i <= n; i++) {
		myfileIn >> currentNode >> left >> right;
		if (left == 0 && right == 0) {
			myfileOut << i;
			if (i != n) {
				myfileOut << " ";
			}
		}
	}
	
	myfileIn.close();
	myfileOut.close();
	return 0;
}