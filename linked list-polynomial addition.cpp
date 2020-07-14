#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node{ 
	int coef; 
	int expo; 
	struct Node* link; 
} Node; 

typedef struct ListHead{ 
	Node* head; 
} ListHead; 
ListHead* createLinkedList(void) {
	ListHead* L; 
	L = (ListHead *)malloc(sizeof(ListHead)); 
	L->head = NULL; 
	return L; 
} 
void addLastNode(ListHead* L, int coef, int expo){ 
	Node* newNode; 
	Node* p; 
	newNode = (Node *)malloc(sizeof(Node)); 
	newNode->coef = coef; 
	newNode->expo = expo; 
	newNode->link = NULL; 
	if(L->head == NULL){
		L->head = newNode; 
		return; 
} 
	else { 
		p = L->head; 
		while(p->link != NULL) { 
			p = p->link; 
		} 
		p->link = newNode; 
	} 
} 
void addPoly(ListHead* A, ListHead* B, ListHead* C){
	Node* pA = A->head; 
	Node* pB = B->head;
	int sum; 
	while(pA && pB){
		if(pA->expo == pB->expo){
			sum = pA->coef + pB->coef;
			addLastNode(C, sum, pA->expo);
			pA=pA->link; pB=pB->link; 
		} 
		else if(pA->expo > pB->expo){ 
			addLastNode(C, pA->coef, pA->expo); 
			pA=pA->link; 
		} 
		else{ addLastNode(C, pB->coef, pB->expo);
				 pB=pB->link; }
	} 
	for( ; pA!=NULL; pA=pA->link)
		addLastNode(C, pA->coef, pA->expo); 
	for( ; pB!=NULL; pB=pB->link) 
		addLastNode(C, pB->coef, pB->expo); 
} 

void printPoly(ListHead* L) { 
	Node* p = L->head; 
	for(;p;p=p->link){ 
		printf("%2dx^%d", p->coef, p->expo);
	} 
} 

int main(void){ 
	
	ListHead *A, *B, *C; 
	A = createLinkedList();
	B = createLinkedList(); 
	C = createLinkedList(); 
	
	addLastNode(A,5,6); 
	addLastNode(A,3,4); 
	addLastNode(A,2,2); 
	printf("A ="); 
	printPoly(A); 
	
	addLastNode(B,2,7); 
	addLastNode(B,2,4);
	addLastNode(B,2,3);
	addLastNode(B,7,1);
	addLastNode(B,1,0);
	printf("\nB ="); 
	printPoly(B);
	
	addPoly(A, B, C);
	printf("\nC = A + B ="); 
	printPoly(C); 
	getchar(); 
}


