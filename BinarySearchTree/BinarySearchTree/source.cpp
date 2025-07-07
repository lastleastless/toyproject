#include "BST.h"
#include <iostream>
BST::BST()
{
	root = NULL;
}

void BST::erase(int data)
{
	Node* delNode = find(root, data);
	if (delNode == NULL)
		return;
	Node* parNode;
	Node* child;
	parNode = delNode->parent;
	if (delNode->left == NULL && delNode->right == NULL)
		child = NULL;
	else if (delNode->left == NULL && delNode->right != NULL)
	{
		child = delNode->right;
	}
	else if (delNode->left != NULL && delNode->right == NULL)
	{
		child = delNode->left;
	}
	else
	{
		child = delNode->right;
		while (child->left != NULL)
		{
			child = child->left;
		}
		delNode->data = child->data;

		delNode = child;
		parNode = delNode->parent;
		child = delNode->right;
	}
	if (parNode == NULL)
	{
		root = child;
		if (child != NULL)
		{
			root->parent = NULL;
		}
	}
	else if (parNode->left == delNode)
	{
		parNode->left = child;
		if (child != NULL)
		{
			child->parent = parNode;
		}
	}
	else
	{
		parNode->right = child;
		if (child != NULL)
		{
			child->parent = parNode;
		}
	}
	delete delNode;
}

Node* BST::find(Node* node, int data)
{
	Node* curNode = root;
	while (curNode != NULL)
	{
		if (curNode->data == data)
		{
			return curNode;
		}
		else if (curNode->data < data)
		{
			curNode = curNode->right;
		}
		else
		{
			curNode = curNode->left;
		}
	}
	return curNode;
}

void BST::insert(int data)
{
	if (find(root, data))
		return;
	Node* newNode = new Node(data);
	if (root == NULL)
	{
		root = newNode;
		return;
	}
	Node* curnode = root;
	Node* parnode = NULL;
	while (curnode != NULL)
	{
		parnode = curnode;
		if (curnode->data > data)
		{
			curnode = curnode->left;
		}
		else
		{
			curnode = curnode->right;
		}
	}
	newNode->parent = parnode;
	if (parnode->data < newNode->data)
	{
		parnode->right = newNode;
	}
	else
	{
		parnode->left = newNode;
	}
}