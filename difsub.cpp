#include <iostream>
#include<queue>
#include<fstream>

using namespace std;

ofstream myfileOut;
ifstream myfileIn;

int main() {
	myfileIn.open("difsub.in");
	myfileOut.open("difsub.out");
	struct MyStruct{
		int node = 0;
		int left = 0, right = 0;
	}tree[2000];
	int n;
	int currentNode = 0, root = 0;
	int sumLeftSubTree = 0, sumRightSubTree = 0;
	
	myfileIn >> n;

	for (int i = 1; i <= n; i++) {
		myfileIn >> tree[i].node >> tree[i].left >> tree[i].right;
	}

	int i = 0;
	bool findLeaf = false;

	while (findLeaf == false) {
		++i;
		if (tree[i].left == 0 && tree[i].right == 0) {
			int j = 0;
			while (j != n){
				++j;
				if (tree[j].left == i || tree[j].right == i) {
					i = j;
					j = 0;
					root = i;
				}
			}
			findLeaf = true;
		}
	}
	
	//sum left subgraph

	queue<int> path1;
	path1.push(tree[root].left);

	while (path1.empty() == false) {
		currentNode = path1.front();
		sumLeftSubTree = sumLeftSubTree + tree[currentNode].node;
		path1.pop();
		if (tree[currentNode].left != 0)
			path1.push(tree[currentNode].left);
		if (tree[currentNode].right != 0)
			path1.push(tree[currentNode].right);
	}

	//sum right subgraph

	queue<int> path2;
	path2.push(tree[root].right);

	while (path2.empty() == false) {
		currentNode = path2.front();
		sumRightSubTree = sumRightSubTree + tree[currentNode].node;
		path2.pop();
		if (tree[currentNode].left != 0)
			path2.push(tree[currentNode].left);
		if (tree[currentNode].right != 0)
			path2.push(tree[currentNode].right);
	}
	
	myfileOut << abs(sumLeftSubTree - sumRightSubTree);
	
	myfileIn.close();
	myfileOut.close();
	return 0;
}