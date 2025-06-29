#pragma once
#include <iostream>
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