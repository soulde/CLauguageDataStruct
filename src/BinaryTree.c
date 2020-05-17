#include"..\include\BinaryTree.h"

BT* BTinit(int num, char letter )
{
	BT* head = malloc(BTLEN);

	head->charData = letter;
	head->numData = num;
	head->left = NULL;
	head->right = NULL;

	return head;
}

int fillBTData(BT* BTPointer, int numData, char charData)
{
	if (!BTPointer)
	{
		return -1;
	}

	BTPointer->numData = numData;
	BTPointer->charData = charData;

	return 0;
}