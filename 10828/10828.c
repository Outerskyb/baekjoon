#include<stdio.h>
#include<string.h>

void push(int* stack, int pos, int data) {
	stack[pos] = data;
}

int pop(int* stack, int pos) {
	if (pos==-1) {
		return -1;
	}
	return stack[pos];
}

int empty(int* stack, int pos) {
	if (pos == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int size(int *stack, int pos) {
	return pos;
}
int top(int *stack, int pos) {
	if (empty(stack, pos)) {
		return -1;
	}
	return stack[--pos];
}

int main(int argc, char *argv[]) {
	int N;
	int stack[10000];
	int pos = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char  query[100];
		scanf("%s", query);
		if (strcmp(query, "push")==0) {
			int data;
			scanf("%d", &data);
			push(stack, pos, data);
			pos++;
		}
		else if (strcmp(query, "pop")==0) {
			pos--;
			printf("%d\n", pop(stack, pos));
			if (pos == -1) {
				pos++;
			}
		}
		else if (strcmp(query, "top") == 0) {
			printf("%d\n", top(stack, pos));
		}
		else if (strcmp(query, "empty") == 0) {
			printf("%d\n", empty(stack, pos));
		}
		else if (strcmp(query, "size") == 0) {
			printf("%d\n", size(stack, pos));
		}

	}
	return 0;
}