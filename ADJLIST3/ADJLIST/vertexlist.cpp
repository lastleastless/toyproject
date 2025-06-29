#include "vertexlist.h"
vertexlist::vertexlist()
{
	header = new vertex();
	trailer = new vertex();
	header->next = trailer;
	trailer->prev = header;
}

void vertexlist::insertV(int vid)
{
	if (findV(vid))
		return;
	vertex* newv = new vertex(vid);
	newv->prev = trailer->prev;
	newv->next = trailer;
	trailer->prev->next = newv;
	trailer->prev = newv;

}

void vertexlist::eraseV(int vid)
{
	vertex* delV = findV(vid);
	if (!delV)
		return;
	delV->prev->next = delV->next;
	delV->next->prev = delV->prev;
	delete delV;
}

vertex* vertexlist::findV(int vid)
{
	for (vertex* curv = header->next;curv != trailer;curv = curv->next)
	{
		if (curv->vid = vid)
		{
			return curv;
		}
	}
	return NULL;
}