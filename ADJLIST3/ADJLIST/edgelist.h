#pragma once
#include "edgelist.h"
#include "vertexlist.h"
#include "vertex.h"
#include "edge.h"
#include "edgeNode.h"
class edgelist
{
public:
	edgelist();
	void insertE(edge*);
	void eraseE(edgeNode*);
	edgeNode* getHeaderNext();
	edgeNode* getTrailer();
private:
	edgeNode* header;
	edgeNode* trailer;
};