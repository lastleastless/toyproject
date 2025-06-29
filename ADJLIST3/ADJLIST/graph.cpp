
#include <queue>
#include <iostream>

struct vertex;
struct edge;
struct edgeNode;
class edgelist
{
public:
	edgelist();
	void insertE(edge*);
	void eraseE(edgeNode*);
	edgeNode* header;
	edgeNode* trailer;
};

class vertexlist
{
public:
	vertexlist();
	void insertV(int);
	void eraseV(int);
	vertex* findV(int);
private:
	vertex* header;
	vertex* trailer;
};

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
		deg = 0;
		vid = -1;
		visit = false;
		prev = next = NULL;
	}
	vertex(int vid)
	{
		deg = 0;
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
	}
	edge(vertex* src, vertex* dst)
	{
		this->src = src;
		this->dst = dst;
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
		edgeInfo = NULL;
		prev = next = NULL;
	}
};


edgelist::edgelist()
{
	header = new edgeNode();
	trailer = new edgeNode();
	header->next = trailer;
	trailer->prev = header;
}

void edgelist::insertE(edge* e)
{
	edgeNode* newe = new edgeNode(e);
	newe->next = trailer;
	newe->prev = trailer->prev;
	trailer->prev->next = newe;
	trailer->prev = newe;
}

void edgelist::eraseE(edgeNode* e)
{
	e->prev->next = e->next;
	e->next->prev = e->prev;
	delete e;
}


vertexlist::vertexlist()
{
	header = new vertex();
	trailer = new vertex();
	header->next = trailer;
	trailer->prev = header;
}

void vertexlist::insertV(int vid)
{
	if (findV(vid))
		return;
	vertex* newv = new vertex(vid);
	newv->prev = trailer->prev;
	newv->next = trailer;
	trailer->prev->next = newv;
	trailer->prev = newv;

}

void vertexlist::eraseV(int vid)
{
	vertex* delV = findV(vid);
	if (!delV)
		return;
	delV->prev->next = delV->next;
	delV->next->prev = delV->prev;
	delete delV;
}

vertex* vertexlist::findV(int vid)
{
	for (vertex* curv = header->next;curv != trailer;curv = curv->next)
	{
		if (curv->vid = vid)
		{
			return curv;
		}
	}
	return NULL;
}




edge* graph::findE(int srcvid, int dstvid)
{
	vertex* src = vlist.findV(srcvid);
	vertex* dst = vlist.findV(dstvid);
	if (src == NULL || dst == NULL)
		return NULL;
	if (src->deg < dst->deg)
	{
		for (edgeNode* curNode = src->incidentE.header->next; curNode != src->incidentE.trailer; curNode = curNode->next)
		{
			if (dst == curNode->edgeInfo->dst)
				return curNode->edgeInfo;
		}
	}
	else
	{
		for (edgeNode* curNode = dst->incidentE.header->next; curNode != dst->incidentE.trailer; curNode = curNode->next)
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

	for (edgeNode* curNode = delv->incidentE.header->next; curNode != delv->incidentE.trailer; curNode = curNode->next)
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
	if (findE(srcvid, dstvid))
	{
		return;
	}
	edge* newe = new edge(src, dst);
	elist.insertE(newe);
	src->incidentE.insertE(newe);
	dst->incidentE.insertE(newe);
	newe->totalE = elist.trailer->prev;
	newe->srcIncidentE = src->incidentE.trailer->prev;
	newe->dstIncidentE = dst->incidentE.trailer->prev;
	src->deg++;
	dst->deg++;
}

void graph::eraseE(int srcvid, int dstvid)
{
	vertex* src = vlist.findV(srcvid);
	vertex* dst = vlist.findV(dstvid);
	if (src == NULL || dst == NULL)
		return;
	if (!findE(srcvid, dstvid))
	{
		return;
	}
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
	for (edgeNode* curNode = curV->incidentE.header->next; curNode != curV->incidentE.trailer; curNode = curNode->next)
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
		for (edgeNode* curNode = curVertex->incidentE.header->next; curNode != curVertex->incidentE.trailer; curNode = curNode->next)
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

int main()
{
	graph g;
	g.insertV(1);
	g.insertV(2);
	g.insertE(1, 2);
	g.BFS(1);
}