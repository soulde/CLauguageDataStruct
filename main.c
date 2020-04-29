#include"Node.h"


int main()
{
	int num[4] = { 1,2,3,4 };
	char string[4] = { 's','t','r','i' };


	/////////////////////
	// error return test
	/////////////////////
	/*
	Node* test = NULL;
	int re = addNode(test, 0, 1, 's');
	printf_s("%d", re);
	*/

	/////////////////////
	// Linklist test
	/////////////////////

	Node* head = creatLinklist();
	for (int i = 0; i < 4; i++)
	{
		//add function test
		addNode(head, i, num[i], string[i]);
	}
	//iter and print test
	iter(head, printData);
	
	//delete function test
	Node* p = head->next;

	//head delete test
	delete(head, 0);

	printf("first node value is %d\n", p->numData);

	//clear test
	clear(head);
	printf_s("%d\n", head->numData);

	free(head);
	
	return 0;
}

