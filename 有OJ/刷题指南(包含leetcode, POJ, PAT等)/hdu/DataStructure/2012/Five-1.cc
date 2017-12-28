// 2012 HDU Data Structure
// Five-1

typedef struct LNode {
	ElemType		data;
	struct LNode *next;
} LNode, *LinkList;

bool Delete_x(LinkList &L, ElemType x) {
	LNode *r, *p;
	if (L->data == x) {
		r = L;
		L = L->next;
		free(r);
		return true;
	}
	p = L;
	while (p->next != NULL) {
		if (p->next->data == x) {
			r = p->next;
			p->next = p->next->next;
			free(r);
			return true;
		}
	}
	return false;
}
