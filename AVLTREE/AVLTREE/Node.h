#pragma once
template <typename T>
class AVLNode {
public:
	T key;
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode(T k) :key(k), left(nullptr), right(nullptr), height(1) {};
};