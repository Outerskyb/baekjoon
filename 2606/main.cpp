#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int vertex;
	int edge;

	scanf("%d", &vertex);
	scanf("%d", &edge);
	
	vector<int> partial_order(vertex+1);
	int **ary;
	ary = (int**)malloc(sizeof(int*)*edge);
	for (int i = 0; i < edge; i++) {
		ary[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0; i <= vertex; i++) {
		partial_order[i] = i;
	}

	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &ary[i][0], &ary[i][1]);
		partial_order[ary[i][0]] = (partial_order[ary[i][0]] < partial_order[ary[i][1]]) ? partial_order[ary[i][0]] : partial_order[ary[i][1]];
		partial_order[ary[i][1]] = (partial_order[ary[i][0]] < partial_order[ary[i][1]]) ? partial_order[ary[i][0]] : partial_order[ary[i][1]];
	}
	for (int j = 0; j < edge; j++) {
		for (int i = 0; i < edge; i++) {
			partial_order[ary[i][0]] = (partial_order[ary[i][0]] < partial_order[ary[i][1]]) ? partial_order[ary[i][0]] : partial_order[ary[i][1]];
			partial_order[ary[i][1]] = (partial_order[ary[i][0]] < partial_order[ary[i][1]]) ? partial_order[ary[i][0]] : partial_order[ary[i][1]];
		}
	}
	int count = 0;

	for (int i = 0; i <= vertex; i++) {
		if (partial_order[i] == 1) {
			count++;
		}
	}
	printf("%d", --count);
}