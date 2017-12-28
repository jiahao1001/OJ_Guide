typedef struct CTNode {
	int child;
	struct CTNode *next;
} *ChildPtr;

typedef struct {
	ElemType data;
	ChildPtr firstchild;
} CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;
} CTree;

void POTT(CTree &T, int v, void(*visit)(ElemType e)) {
	ChildPtr p = T.nodes[v].firstchild;
	visit(T.nodes[v].data);
	while (p != NULL) {
		POTT(T, p->child, visit);
		p = p->next;
	}
}

