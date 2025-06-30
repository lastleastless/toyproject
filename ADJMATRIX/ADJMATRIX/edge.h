#pragma once
#include "vertex.h"

struct edge
{
	vertex* src;
	vertex* dst;
	edge* prev;
	edge* next;
	edge()
	{
		src = dst = NULL;
	}
	edge(vertex* src, vertex* dst)
	{
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};