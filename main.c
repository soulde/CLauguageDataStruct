#include"Node.h"


int main()
{
	int num[4] = { 1,2,3,4 };
	char string[4] = { 's','t','r','i' };

	Node* head = creatLinklist();
	for (int i = 0; i < 4; i++)
	{
		addNode(head, i, num[i], string[i]);
	}
	iter(head, printData);

	clear(head);
	free(head);
	return 0;
}

