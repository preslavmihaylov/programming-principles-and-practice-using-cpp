#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct Name_ {
	Link lnk;
	char* p;
} Name;

Name* make_name(char * n)
{
	Name* p = malloc(sizeof(Name));
	p->p = n;
	return p;
}

int main()
{
	List names;
	Link* curr;
	init(&names);

	push_back(&names, (Link*)make_name("Norah"));
	push_back(&names, (Link*)make_name("Annemarie"));
	push_back(&names, (Link*)make_name("Kris"));

	erase(&names, advance(names.first, 1));
	push_front(&names, (Link*)make_name("Pres"));
	Link* third = advance(names.first, 2);
	insert(&names, (Link*)make_name("Third name"), third); 

	curr = names.first;
	int cnt = 0;
	for (; curr; curr = curr->next)
	{
		++cnt;
		printf("element %d: %s\n", cnt, ((Name*)curr)->p);
	}

	return 0;
}
