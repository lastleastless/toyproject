#pragma once
#include "vertex.h"

class vertexList
{
public:
	vertexList();
	void insertV(int);
	void eraseV(int);
	vertex* findV(int);
private:
	vertex* header;
	vertex* trailer;
};