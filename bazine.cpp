#include <iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
int adiacentMatrix[150][150]{};
int n, m;

void bfs(int i, int j) {
	adiacentMatrix[i][j] = 0;
	adiacentMatrix[j][i] = 0;
	queue<int> que;
	que.push(j);
	que.push(i);
	int node = j;

	while (!que.empty()) {
		node = que.front();
		que.pop();
		for (int k = 1; k <= n; k++) {
			if (adiacentMatrix[node][k] == 1) {
				adiacentMatrix[node][k] = 0;
				adiacentMatrix[k][node] = 0;
				que.push(k);
			}
		}
	}




}

int main() {
	ofstream myfileOut;
	ifstream myfileIn;

	myfileIn.open("bazine.in");
	myfileOut.open("bazine.out");

	myfileIn >> n;
	myfileIn >> m;
	
	int val1, val2;
	for (int i = 1; i <= n; i++) {
		adiacentMatrix[i][i] = 1;
	}

	for (int i = 0; i <= m; i++) {
		myfileIn >> val1 >> val2;
		adiacentMatrix[val1][val2] = 1;
		adiacentMatrix[val2][val1] = 1;
	}

	int taps = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adiacentMatrix[i][j] == 1) {
				bfs(i, j);
				++taps;
			}
		}
	}

	myfileOut << taps;


	myfileIn.close();
	myfileOut.close();
	return 0;
}