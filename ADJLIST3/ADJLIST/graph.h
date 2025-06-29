#pragma once
#include "edgelist.h"
#include "vertexlist.h"
#include "vertex.h"
#include "edge.h"
#include "edgeNode.h"
class graph
{
public:
	edge* findE(int, int);
	void insertV(int);
	void eraseV(int);
	void insertE(int, int);
	void eraseE(int, int);
	void DFS(int);
	void BFS(int);
private:
	vertexlist vlist;
	edgelist elist;
};