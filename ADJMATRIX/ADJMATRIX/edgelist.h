#pragma once
#include "edge.h"

class edgeList {
public:
	edgeList();
	void insertE(edge*);
	void eraseE(edge*);
private:
	edge* header;
	edge* trailer;
};