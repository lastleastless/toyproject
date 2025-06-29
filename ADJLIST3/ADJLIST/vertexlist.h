#pragma once
#include "edgelist.h"
#include "vertexlist.h"
#include "vertex.h"
#include "edge.h"
#include "edgeNode.h"

class vertexlist
{
public:
	vertexlist();
	void insertV(int);
	void eraseV(int);
	vertex* findV(int);
private:
	vertex* header;
	vertex* trailer;
};