#include "edgelist.h"

edgeList::edgeList()
{
	header = new edge();
	trailer = new edge();
	header->next = trailer;
	trailer->prev = header;

}

void edgeList::insertE(edge* newe)
{
	newe->prev = trailer->prev;
	newe->next = trailer;
	trailer->prev->next = newe;
	trailer->prev = newe;
}

void edgeList::eraseE(edge* dele)
{
	dele->next->prev = dele->prev;
	dele->prev->next = dele->next;
	delete dele;
}