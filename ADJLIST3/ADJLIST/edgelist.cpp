#include "edgelist.h"

edgeNode* edgelist::getHeaderNext()
{
	if (header->next == trailer)
		return NULL;
	return header->next;
}

edgeNode* edgelist::getTrailer()
{
	if (trailer == NULL)
		return NULL;
	return trailer;
}

edgelist::edgelist()
{
	header = new edgeNode();
	trailer = new edgeNode();
	header->next = trailer;
	trailer->prev = header;
}

void edgelist::insertE(edge* e)
{
	edgeNode* newe = new edgeNode(e);
	newe->next = trailer;
	newe->prev = trailer->prev;
	trailer->prev->next = newe;
	trailer->prev = newe;
}

void edgelist::eraseE(edgeNode* e)
{
	e->prev->next = e->next;
	e->next->prev = e->prev;
	delete e;
}