#include "Queue.h"

int EnQueue(Node* head, int numData, char charData)
{
	int flag = 0;

	if (!head)
	{
		flag = -1;
	}
	else {
		Node* node = (Node*)malloc(LEN);
		fillData(head, numData, charData);

		head->unionData.tail->next = node;
		head->unionData.tail = node;

		head->numData++;
	}
	return flag;
}

int DeQueue(Node* head)
{
	int flag = 0;

	if (!head)
	{
		flag = -1;
	}
	else {
		Node* del = head->next;
		head->next = head->next->next;

		free(del);

		head->numData--;
	}
	return flag;
}
