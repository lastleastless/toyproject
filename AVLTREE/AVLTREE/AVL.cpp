//implementation of AVL tree.
//Definition of AVL tree: maintains balance by performing rotations during insertions and deletions to ensure the height difference
//between the left and right subtrees of any node is no more than one.
//this propery guarantees that the tree;s height remains O(log n),ensuring efficient operations.
// 
//Property 1: The heights of the left and right subtrees of every node fiffer by at most one.
//Property 2: Every subtree is an AVL tree.
//Property 3: For every node,its balance factor is -1,0,1
// 
//Rotation: RR,LL,LR,RL
// RR rotation: when node becomaes unblanced due to an insertion into the right subtree of its right child.
// leading to a Left imbalnace.
// LL Rotation: when node becomes unbalanced due to an insertion into the right subtree of its left child.
// leading to a right imbalance.
// LR Rotation: when the left child of a node is right-heavy.creating double imbalance.
// left rotation on the left child, followed by a right rotation on the original node.
// RL Rotation: when the right child of a node is left-heavy.creating double imbalnce.
// right rotation on the right child,followed by a left rotation on the original node.


#include <iostream>
#include "Node.h"
using namespace std;

template <typename T> class AVLTree
{
public:

private:
	AVLNode<T>* root;
	AVLNode<T>* left_rotation(AVLNode<T>*);
	AVLNode<T>* right_rotation(AVLNode<T>*);
	int height(AVLNode<T>*);
	int balanceFactor(AVLNode<T>*);
	AVLNode<T>* insert(AVLNode<T>*,T);
	AVLNode<T>* remove(AVLNode<T>*,T);
	AVLNode* minValue(AVLNode<T>*);
};

template <typename T>
int AVLTree<T> ::height(AVLNode<T>* Node)
{
	if (Node == nullptr)
		return 0;
	return Node->height;
}
template <typename T>
int AVLTree<T>::balanceFactor(AVLNode<T>* Node)
{
	if (node == nullptr)
		return 0;
	return height(Node->left) - height(Node->right);
}
template <typename T>
AVLNode<T>* AVLTree<T>::left_rotation(AVLNode<T>* Node)
{
	AVLNode<T>* rightChild = Node->right;
	AVLNode<T>* rightChild_remainder = rightChild->left;
	rightChild->left = Node;
	Node->right = rightChild_remainder;
	Node->height = max(Node->left->height, Node->right->height) + 1;
	rightChild->height = max(Node->height, rightChild->right->height) + 1;
	return rightChild;
}
template<typename T>
AVLNode<T>* AVLTree<T>::right_rotation(AVLNode<T>* Node)
{
	AVLNode<T>* leftChild = Node->left;
	AVLNode<T>* leftChild_remainder = leftChild->right;
	leftChild->right = Node;
	Node->left = leftChild_remainder;
	Node->height = max(Node->left->height, Node->right->height) + 1;
	leftChild->height = max(Node->height, leftChild->left->height) + 1;
	return leftChild;
}
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* Node, T key)
{
	if (node == nullptr)
		return new AVLNode<T>(key);
	if (key < Node->key)
		Node->left = insert(Node->left, key);
	else if (key > node->key)
		Node->right = insert(Node->right, key);
	else
		return Node;
	Node->height = 1 + max(height(Node->left), height(Node->right));
	int balance = balanceFactor(Node);
	//RR CASE
	// imbalance case :   3
	//                   /
	//                  2
	//                 /
	//                1
	// at root Node, left imbalance occured. inserted key < parent key = left Node insertion.
	if (balance > 1 && key < Node->left->key)
	{
		return right_rotation(Node);
	}
	//LL CASE
	// imbalance case : 3
	//                   |
	//                    2
	//                     |
	//                      1
	//at root Node, right imbalance occured. inserted key > parent key = right Node insertion.
	if (balance < -1 && key > Node->right->key)
	{
		return left_rotation(Node);
	}
	//RL CASE
	// imbalance case: 4
	//                /
	//               2
	//                |
	//                 3
	//at root Node, left imbalance occured. inserted key > parent key -> perfrom Left Rotation on the root->left, and Right rotation on the root Node.
	if (balance > 1 && key > Node->left->key)
	{
		Node->left = left_rotation(Node->left);
		return right_rotation(Node);
	}
	//LR CASE
	// imbalance case: 10
	//                   |
	//                    13
	//                    /
	//                   12
	//ar root Node, right imbalance occured. inserted key < parent key -> perform Right Rotation on root->right Node, and Left Rotation on root Node
	if (balance < -1 && key < Node->right->key)
	{
		Node->right = right_rotation(Node->right);
		return left_rotation(Node);
	}
	return Node;
}
template <typename T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* Node, T key)
{
	if (Node == nullptr)
		return nullptr;
	if (key < Node->key)
		remove(Node->left, key);
	else if (key > Node->key)
		remove(Node->right, key);
	else
	{
		if ((Node->left == nullptr) || (Node->right == nullptr))
		{
			AVLNode<T>* temp = Node->left ? Node->left : Node->right;

			if (temp == nullptr)
			{
				temp = Node;
				Node = nullptr;
			}
			else
				*Node = *temp;
			delete temp;
		}
		else
		{
			//find successor.
			AVLNode<T>* temp = minValue(root->right);
			root->key = temp->key;
			root->right = remove(root->right, temp->key);
		}
	}
	if (Node == nullptr)
		return Node;
	Node->height = 1 + max(height(Node->left), height(Node->right));
	int balance = balanceFactor(Node);
	if (balance > 1 && balanceFactor(root->left) >= 0)
	{
		return right_rotation(Node);
	}
	if (balance < -1 && balanceFactor(Node->right) <= 0)
	{
		return left_rotation(Node);
	}
	if (balance < -1 && balanceFactor(Node->right) > 0)
	{
		Node->right = right_rotation(Node->right);
		return left_rotation(Node);
	}
	if (balance > 1 && balanceFactor(Node->left) < 0)
	{
		Node->left = left_rotation(Node->left);
		return right_rotation(Node);
	}
	return Node;
}