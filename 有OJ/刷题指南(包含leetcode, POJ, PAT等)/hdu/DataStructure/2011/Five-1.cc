typedef struct LNode {
	int data;
	struct LNode *next;
} *LinkList;

void A7(LinkList  L) {
	LNode *p, *q, *r, *u;
	p = L->next;
	L->next = NULL;
	while (p != NULL) {
		r = L;
		q = L->next;
		while (q != NULL && q->data <= p->data) {
			r = q; 
			q = q->next;
		}
		u = p->next;
		p = p->next; 
		r->next = p;
		p = u;
	}

}