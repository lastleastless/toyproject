#pragma once
#include "edgelist.h"
#include "vertexlist.h"
#include "vertex.h"
#include "edge.h"
#include "edgeNode.h"

struct edge
{
	vertex* src;
	vertex* dst;
	edgeNode* srcIncidentE;
	edgeNode* dstIncidentE;
	edgeNode* totalE;
	edge()
	{
		src = dst = NULL;
		srcIncidentE = dstIncidentE = totalE = NULL;
	}
	edge(vertex* src, vertex* dst)
	{
		this->src = src;
		this->dst = dst;
		srcIncidentE = dstIncidentE = totalE = NULL;
	}
};