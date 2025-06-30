#include "graph.h"

void graph::insertV(int vid)
{
	if (vlist.findV(vid))
		return;
	vertex* newV = new vertex(vid);
	for (int i = 0; i < edgeMatrix.size(); i++)
	{
		edgeMatrix[i].push_back(NULL);
	}
	edgeMatrix.push_back(std::vector<edge*>(edgeMatrix.size() + 1, NULL));
}

void graph::eraseV(int vid)
{
	vertex* delv = vlist.findV(vid);
	if (delv == NULL)
		return;
	for (int i = 0; i < edgeMatrix.size(); i++)
	{
		if (i != delv->matrixId)
		{
			elist.eraseE(edgeMatrix[i][delv->matrixId]);
		}
		edgeMatrix[i].erase(edgeMatrix[i].begin() + delv->matrixId);
	}
	edgeMatrix.erase(edgeMatrix.begin() + delv->matrixId);
	vlist.eraseV(vid);
}

void graph::insertE(int srcVid, int dstVid)
{
	vertex* src = vlist.findV(srcVid);
	vertex* dst = vlist.findV(dstVid);
	if (src == NULL || dst == NULL)
		return;
	if (edgeMatrix[srcVid][dstVid] != NULL || edgeMatrix[dstVid][srcVid] != NULL)
		return;
	edge* newE = new edge(src, dst);
	edgeMatrix[srcVid][dstVid] = edgeMatrix[dstVid][srcVid] = newE;
}

void graph::eraseE(int srcVid, int dstVid)
{
	vertex* src = vlist.findV(srcVid);
	vertex* dst = vlist.findV(dstVid);
	if (src == NULL || dst == NULL)
		return;
	if (edgeMatrix[srcVid][dstVid] == NULL || edgeMatrix[dstVid][srcVid] == NULL)
		return;
	edgeMatrix[srcVid][dstVid] = edgeMatrix[dstVid][srcVid] = NULL;
}

void graph::DFS(int vid)
{
	vertex* curV = vlist.findV(vid);
	curV->visit = true;
	if (!curV)
		return;
	for (int i = 0; i < edgeMatrix[vid].size(); i++)
	{
		if (i != vid)
		{
			if (curV == edgeMatrix[vid][i]->src)
			{
				DFS(edgeMatrix[vid][i]->dst->matrixId);
			}
			else
			{
				DFS(edgeMatrix[vid][i]->src->matrixId);
			}
		}
	}
}