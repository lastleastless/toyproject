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
	void insert(T);
	void remove(T);
	AVLNode* find(T);
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
