#ifndef LIST_H
#define LIST_H

typedef struct Link_ Link;
typedef struct List_ List;

struct Link_ {
	Link* prev;
	Link* next;
};

struct List_ {
	Link* first;
	Link* last;
};

extern void init(List* lst);
extern List* create();
extern void clear(List* lst);
extern void destroy(List* lst);

extern void push_back(List* lst, Link* p);
extern void push_front(List* lst, Link* p);

/* insert p before q in lst: */
extern void insert(List* lst, Link* p, Link* q);
extern Link* erase(List* lst, Link* p);

/* return link n hops before or after p: */
extern Link* advance(Link* p, int n);

#endif //LIST_H
