#include "BST.h"

int main()
{
	BST B;
	B.insert(1);
	B.insert(2);
	B.insert(3);
	B.erase(2);
	B.erase(1);
	B.erase(3);
}