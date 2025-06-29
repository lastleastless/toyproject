#pragma once
#include "edgelist.h"
#include "vertexlist.h"
#include "vertex.h"
#include "edge.h"
#include "edgeNode.h"

struct edgeNode
{
	edge* edgeInfo;
	edgeNode* next;
	edgeNode* prev;
	edgeNode(edge* e)
	{
		this->edgeInfo = e;
		prev = next = NULL;

	}
	edgeNode()
	{
		prev = next = NULL;
	}
};