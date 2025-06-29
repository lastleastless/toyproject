#pragma once
#include <iostream>
#include "edgelist.h"

struct vertex
{
	int vid;
	int deg;
	bool visit;
	vertex* next;
	vertex* prev;
	edgelist incidentE;
	vertex()
	{
		deg = -1;
		vid = -1;
		visit = false;
		prev = next = NULL;
	}
	vertex(int vid)
	{
		deg = -1;
		this->vid = vid;
		visit = false;
		prev = next = NULL;
	}
};