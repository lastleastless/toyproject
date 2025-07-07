#pragma once
#include "Node.h"
class BST
{
public:
	BST();
	void insert(int);
	void erase(int);
	Node* find(Node*, int);
private:
	Node* root;
};