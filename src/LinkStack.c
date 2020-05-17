#include "..\include\LinkStack.h"


int pop(Node* head)
{	
	int flag = 0;
	if (!head)
	{
		flag = -1;
	}
	else {
		Node* del = head->next;
		head->next = del->next;

		free(del);
		head->numData--;
	}
	
	return flag;
}

int push(Node* head, int numData, char charData)
{
	int flag = 0;
	if (!head)
	{
		flag = -1;
	}
	else {
		Node* node = (Node*)malloc(LEN);
		fillData(head, numData, charData);

		node->next = head->next;
		head->next = node;

		head->numData++;
	}

	return flag;
}
