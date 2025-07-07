#pragma once
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int data)
	{
		this->data = data;
		left = right = parent  = nullptr;
	}
	Node()
	{
		data = -1;
		left = right = parent = nullptr;
	}
};