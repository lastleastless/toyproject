#pragma once
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