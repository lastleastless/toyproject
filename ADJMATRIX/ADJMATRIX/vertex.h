#pragma once
#include <iostream>

struct vertex
{
	bool visit;
	int vertexId;
	int matrixId;
	vertex* prev;
	vertex* next;
	vertex()
	{
		visit = false;
		vertexId = matrixId = -1;
		prev = next = NULL;
	}
	vertex(int vid)
	{
		visit = false;
		vertexId = vid;
		matrixId = -1;
		prev = next = NULL;
	}
};