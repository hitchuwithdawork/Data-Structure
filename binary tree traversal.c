#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *l, *r, *p;
	int val;
};

typedef struct node Node;

Node* newnode(int v) { // 동적할당을 통해 새로운 Node 생성
	Node* node = (Node*)malloc(sizeof(Node));
	node->l = node->r = node->p = NULL;
	node->val = v;
	return node;
}

void link(Node* p, Node* l, Node* r) { // 부모자식 관계 연결
	p->l = l;
	p->r = r;
	if (l)
		l->p = p;
	if (r)
		r->p = p;
}

void preorder(Node* root) {
	// 재귀 없는 전위 순회
	Node* stk[13];
	int top = 0;
	
	printf("Pre-order : ");
	stk[top++] = root;
	while (top > 0) {
		Node* node = stk[--top];
		printf(" %d", node->val);
		if (node->r)
			stk[top++] = node->r;
		if (node->l)
			stk[top++] = node->l;
	}
	printf("\n");
}

void inorder(Node* root) {
	//  중위 순회
	Node* stk[13];
	int top = 0;

	printf("In-order : ");
	Node* node = root;
	while (node != NULL || top > 0) {
		while (node) {
			stk[top++] = node;
			node = node->l;
		}

		node = stk[--top];
		printf(" %d", node->val);
		node = node->r;
	}
	printf("\n");
}

void postorder(Node* root) {
	//  후위 순회
	int visit[13] = { 0 };
	Node* stk[13];
	int top = 0;

	printf("Post-order : ");
	stk[top++] = root;
	while (top > 0) {
		Node* node = stk[--top];
		if (visit[node->val] == 0) {
			visit[node->val] = 1;
			stk[top++] = node;
			if (node->r)
				stk[top++] = node->r;
			if (node->l)
				stk[top++] = node->l;
		}
		else
			printf(" %d", node->val);
	}
	printf("\n");
}

void levelorder(Node* root) {
	//  레벨 순회
	Node* que[13];
	int fr = 0, re = 0;

	printf("Level-order : ");
	que[re++] = root;
	while (fr < re) {
		printf(" %d", que[fr]->val);
		if (que[fr]->l)
			que[re++] = que[fr]->l;
		if (que[fr]->r)
			que[re++] = que[fr]->r;
		fr++;
	}
	printf("\n");
}

int main() {
	// 사용할 노드를 준비
	Node* nodes[13];
	for (int i = 0; i < 13; i++)
		nodes[i] = newnode(i);

	// 트리구성
	Node* root = nodes[0];
	link(nodes[0], nodes[1], nodes[2]);
	link(nodes[1], nodes[3], nodes[4]);
	link(nodes[2], NULL, nodes[5]);
	link(nodes[3], NULL, nodes[6]);
	link(nodes[4], NULL, nodes[7]);
	link(nodes[5], nodes[8], nodes[9]);
	link(nodes[6], nodes[10], nodes[11]);
	link(nodes[7], NULL, NULL);
	link(nodes[8], NULL, nodes[12]);
	link(nodes[9], NULL, NULL);
	link(nodes[10], NULL, NULL);
	link(nodes[11], NULL, NULL);
	link(nodes[12], NULL, NULL);

	// 순회
	preorder(root);
	inorder(root);
	postorder(root);
	levelorder(root);

	// 사용한 노드 정리
	for (int i = 0; i < 13; i++)
		free(nodes[i]);

	return 0;
}