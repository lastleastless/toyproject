#pragma once
#include <vector>
#include "edge.h"
#include "vertexlist.h"
#include "edgelist.h"

class graph
{
public:
	void insertV(int);
	void eraseV(int);
	void insertE(int,int);
	void eraseE(int,int);
	void DFS(int);
private:
	std::vector<std::vector<edge*>> edgeMatrix;
	vertexList vlist;
	edgeList elist;
};