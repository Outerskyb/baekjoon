#include<stdio.h>
#include<string.h>

void push(int* queue, int front,int end, int data) {
	queue[pos] = data;
}

int pop(int* queue, int front,int end) {
	if (pos == -1) {
		return -1;
	}
	return queue[pos];
}

int empty(int* queue, int front,int end) {
	if (pos == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int size(int *queue, int front,int end) {
	return pos;
}
int top(int *queue, int front,int end) {
	if (empty(queue, front,end)) {
		return -1;
	}
	return queue[--pos];
}

int main(int argc, char *argv[]) {
	int N;
	int queue[10000];
	int front = 0;
	int end = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char  query[100];
		scanf("%s", query);
		if (strcmp(query, "push") == 0) {
			int data;
			scanf("%d", &data);
			push(queue, front,end, data);
			pos++;
		}
		else if (strcmp(query, "pop") == 0) {
			pos--;
			printf("%d\n", pop(queue, pos));
			if (pos == -1) {
				pos++;
			}
		}
		else if (strcmp(query, "top") == 0) {
			printf("%d\n", top(queue, pos));
		}
		else if (strcmp(query, "empty") == 0) {
			printf("%d\n", empty(queue, pos));
		}
		else if (strcmp(query, "size") == 0) {
			printf("%d\n", size(queue, pos));
		}

	}
	return 0;
}