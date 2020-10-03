#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
	int op;
	int mutable;
	int value;
} Node;

int getCurrentValue(int length, Node *nodes[length], int pindex){
	Node *parent = nodes[pindex-1];

	// if leaf, return value
	if (parent->value != -1) return parent->value;

	int left = getCurrentValue(length, nodes, 2 * pindex);
	int right = getCurrentValue(length, nodes, 2 * pindex + 1);
	return parent->op == 1 ? left && right : left || right;
}

int min(int a, int b){
	return a > b ? b : a;
}


int getMinimumMutations(int length, Node *nodes[length], int goal, int mutations, int node){
	if ((node * 2) >= length) return INT_MAX/2;
	Node *parent = nodes[node - 1];
	if (parent->value == goal) return mutations;

	int leftNum = 2 * node;
	int rightNum = leftNum+1;
	Node *left = nodes[leftNum - 1];
	Node *right = nodes[leftNum];

	// Either of the children need to be changed
	if (goal != parent->op) return min(
		getMinimumMutations(length, nodes, goal, mutations, leftNum),
		getMinimumMutations(length, nodes, goal, mutations, rightNum)
	);

	// Children are unique
	if (left->value != right->value){
		// Changing one of the children gets us the goal outcome, so find out which is wrong
		int leftWrong = goal ? !left->value && right->value : left->value && !right->value;
		int rightWrong = goal ? left->value && !right->value : !left->value && right->value;
		// If possible, change self instead
		if (parent->mutable) return mutations + 1;
		// Otherwise, change problem child
		return getMinimumMutations(length, nodes, goal, mutations, leftNum + (rightWrong ? 1 : 0));
	}

	// Cannot mutate self, so mutate both children to get goal
	if (!parent->mutable) return (mutations +
		getMinimumMutations(length, nodes, goal, 0, leftNum) +
		getMinimumMutations(length, nodes, goal, 0, rightNum)
	);

	// Mutate just one child
	mutations++;
	return min(
		getMinimumMutations(length, nodes, goal, mutations, leftNum),
		getMinimumMutations(length, nodes, goal, mutations, rightNum)
	);
}

int computeMutations(int length, Node *nodes[length], int goal){
	for (int i = 0; i < (length - 1) / 2; i++){
		// populate branch values
		nodes[i]->value = getCurrentValue(length, nodes, i + 1);
	}

	return getMinimumMutations(length, nodes, goal, 0, 1);
}

int main(){
	int cases = 0;
	if (!scanf("%d\n", &cases)){
		printf("Could not read number of cases\n");
		return 1;
	};
	for (int i = 0; i < cases; i++){
		int nodeCount = 0;
		int goal = 0;
		if (!scanf("%d %d\n", &nodeCount, &goal)){
			printf("Could not read node count & goal value\n");
			return 1;
		}

		Node *nodes[nodeCount];
		int nodeIndex = 0;
		for (int j = 0; j < (nodeCount - 1) / 2; j++){
			Node *node = malloc(sizeof(Node));
			node->value = -1;
			if (!scanf("%d %d\n", &node->op, &node->mutable)){
				printf("Could not read node operator & mutability\n");
				return 1;
			}
			nodes[nodeIndex] = node;
			nodeIndex++;
		}
		for (int j = 0; j < (nodeCount + 1) / 2; j++){
			Node *node = malloc(sizeof(Node));
			node->mutable = 0;
			node->op = -1;
			if (!scanf("%d\n", &node->value)){
				printf("Could not read leaf node value\n");
				return 1;
			}

			nodes[nodeIndex] = node;
			nodeIndex++;
		}

		int minimum = computeMutations(nodeCount, nodes, goal);
		printf("Case #%d: ", i + 1);
		if (minimum >= INT_MAX/2){
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", minimum);
		}

		for (int i = 0; i < nodeCount; i++){
			free(nodes[i]);
		}
	}

	return 0;
}
