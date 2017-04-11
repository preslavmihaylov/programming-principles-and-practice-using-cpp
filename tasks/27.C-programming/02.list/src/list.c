#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void init(List* lst)
{
	assert(lst);
	lst->first = lst->last = NULL;
}

List* create()
{
	List* lst = (List*)malloc(sizeof(*lst));
	init(lst);
	return lst;
}

void clear(List* lst)
{
	assert(lst);
	Link* curr = lst->first;
	while (curr)
	{
		Link* next = curr->next;
		free(curr);
		curr = next;
	}

	lst->first = lst->last = NULL;
}

void destroy(List* lst)
{
	assert(lst);
	clear(lst);
	free(lst);
}

void push_back(List* lst, Link* p)
{
	assert(lst);
	assert(p);

	Link* last = lst->last;
	if (last)
	{
		last->next = p;
		p->prev = last;
	}
	else
	{
		lst->first = p;
		p->prev = NULL;
	}

	lst->last = p;
	p->next = NULL;
}

void push_front(List* lst, Link* p)
{
	assert(lst);
	assert(p);
	
	Link* first = lst->first;
	if (first)
	{
		first->prev = p;
		p->next = first;
	}
	else
	{
		lst->last = p;
		p->next = NULL;
	}

	lst->first = p;
	p->prev = NULL;
}

/* insert p before q in lst: */
void insert(List* lst, Link* p, Link* q)
{
	assert(lst);
	if (p == NULL) return;

	if (q)
	{
		if (q == lst->first)
		{
			q->prev = p;
			p->next = q;
			lst->first = p;
		}
		else
		{
			q->prev->next = p;
			p->prev = q->prev;
			p->next = q;
			q->prev = p;
		}
	}
}

Link* erase(List* lst, Link* p)
{
	assert(lst);
	if (!p) return NULL;

	if (p == lst->first)
	{
		if (p->next)
		{
			lst->first = p->next;
			p->next->prev = NULL;
			return p->next;
		}
		else
		{
			lst->first = lst->last = NULL;
			return NULL;
		}
	}
	else if (p == lst->last)
	{
		if (p->prev)
		{
			lst->last = p->prev;
			p->prev->next = NULL;
			return p->prev;
		}
		else
		{
			lst->first = lst->last = NULL;
			return NULL;
		}
	}
	else
	{
		if (p->next)
		{
			p->next->prev = p->prev;
		}

		if (p->prev)
		{
			p->prev->next = p->next;
		}

		return p->next;
	}
}

/* return link n hops before or after p: */
Link* advance(Link* p, int n)
{
	Link* curr = p;
	while (curr && n != 0)
	{
		if (n < 0)
		{
			curr = curr->prev;
			++n;
		}
		else // if (n > 0)
		{
			curr = curr->next;
			--n;
		}
	}
}

