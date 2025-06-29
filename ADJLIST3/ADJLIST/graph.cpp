#include "graph.h"
#include <queue>
edge* graph::findE(int srcvid, int dstvid)
{
	vertex* src = vlist.findV(srcvid);
	vertex* dst = vlist.findV(dstvid);
	if (src == NULL || dst == NULL)
		return NULL;
	if (src->deg < dst->deg)
	{
		for (edgeNode* curNode = src->incidentE.getHeaderNext(); curNode != src->incidentE.getTrailer(); curNode = curNode->next)
		{
			if (dst == curNode->edgeInfo->dst)
				return curNode->edgeInfo;
		}
	}
	else
	{
		for (edgeNode* curNode = dst->incidentE.getHeaderNext(); curNode != dst->incidentE.getTrailer(); curNode = curNode->next)
		{
			if (dst == curNode->edgeInfo->src)
				return curNode->edgeInfo;
		}
	}
	return NULL;
}

void graph::insertV(int vid)
{
	if (vlist.findV(vid))
		return;
	vlist.insertV(vid);
}

void graph::eraseV(int vid)
{
	if (!vlist.findV(vid))
		return;
	vertex* delv = vlist.findV(vid);

	for (edgeNode* curNode = delv->incidentE.getHeaderNext(); curNode != delv->incidentE.getTrailer(); curNode = curNode->next)
	{
		elist.eraseE(curNode->edgeInfo->totalE);
		if (delv == curNode->edgeInfo->src)
		{
			curNode->edgeInfo->dst->incidentE.eraseE(curNode->edgeInfo->dstIncidentE);
			curNode->edgeInfo->dst->deg--;
		}
		else
		{
			curNode->edgeInfo->src->incidentE.eraseE(curNode->edgeInfo->srcIncidentE);
			curNode->edgeInfo->src->deg--;
		}
	}
	vlist.eraseV(vid);
}

void graph::insertE(int srcvid, int dstvid)
{
	vertex* src = vlist.findV(srcvid);
	vertex* dst = vlist.findV(dstvid);
	if (src == NULL || dst == NULL)
		return;
	edge* newe = new edge(src, dst);
	elist.insertE(newe);
	src->incidentE.insertE(newe);
	dst->incidentE.insertE(newe);
	newe->totalE = elist.getTrailer()->prev;
	newe->srcIncidentE = src->incidentE.getTrailer()->prev;
	newe->dstIncidentE = dst->incidentE.getTrailer()->prev;
	src->deg++;
	dst->deg++;
}

void graph::eraseE(int srcvid, int dstvid)
{
	vertex* src = vlist.findV(srcvid);
	vertex* dst = vlist.findV(dstvid);
	if (src == NULL || dst == NULL)
		return;
	edge* dele = findE(srcvid, dstvid);
	src->incidentE.eraseE(dele->srcIncidentE);
	dst->incidentE.eraseE(dele->dstIncidentE);
	elist.eraseE(dele->totalE);
	src->deg--;
	dst->deg--;
	delete dele;
}

void graph::DFS(int vid)
{
	if (!vlist.findV(vid))
		return;
	vertex* curV = vlist.findV(vid);
	curV->visit = true;
	for (edgeNode* curNode = curV->incidentE.getHeaderNext(); curNode != curV->incidentE.getTrailer(); curNode = curNode->next)
	{
		if (curV == curNode->edgeInfo->src)
		{
			if (!curNode->edgeInfo->dst->visit)
			{
				DFS(curNode->edgeInfo->dst->vid);
			}
		}
		else
		{
			if (!curNode->edgeInfo->src->visit)
			{
				DFS(curNode->edgeInfo->src->vid);
			}
		}
	}
}

void graph::BFS(int vid)
{
	vertex* curV = vlist.findV(vid);
	if (!curV)
		return;
	std::queue<vertex*> vertexQueue;
	vertexQueue.push(curV);
	curV->visit = true;
	while (!vertexQueue.empty())
	{
		vertex* curVertex = vertexQueue.front();
		std::cout << curVertex->vid << " ";
		vertexQueue.pop();
		for (edgeNode* curNode = curVertex->incidentE.getHeaderNext(); curNode != curVertex->incidentE.getTrailer(); curNode = curNode->next)
		{
			if (curVertex == curNode->edgeInfo->src)
			{
				if (!curNode->edgeInfo->dst->visit)
				{
					vertexQueue.push(curNode->edgeInfo->dst);
					curNode->edgeInfo->dst->visit = true;
				}
			}
			else
			{
				if (!curNode->edgeInfo->src->visit)
				{
					vertexQueue.push(curNode->edgeInfo->src);
					curNode->edgeInfo->src->visit = true;
				}
			}
		}
		std::cout << std::endl;
	}
}