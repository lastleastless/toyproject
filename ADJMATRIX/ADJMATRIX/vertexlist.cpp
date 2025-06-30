#include "vertexlist.h"

vertexList::vertexList()
{
	header = new vertex();
	trailer = new vertex();
	header->next = trailer;
	trailer->prev = header;
}

void vertexList::insertV(int vid)
{
	if (findV(vid))
		return;
	vertex* newV = new vertex(vid);
	newV->next = trailer;
	newV->prev = trailer->prev;
	newV->matrixId = trailer->prev->matrixId + 1;
	trailer->prev->next = newV;
	trailer->prev = newV;
}

vertex* vertexList::findV(int vid)
{
	for (vertex* curV = header->next; curV != trailer; curV = curV->next)
	{
		if (curV->vertexId == vid)
		{
			return curV;
		}
	}
	return NULL;
}

void vertexList::eraseV(int vid)
{
	vertex* delv = findV(vid);
	if (delv == NULL)
		return;
	delv->next->prev = delv->prev;
	delv->prev->next = delv->next;
	for (vertex* curV = delv->next; curV != trailer; curV = curV->next)
	{
		curV->matrixId--;
	}
	delete delv;
}