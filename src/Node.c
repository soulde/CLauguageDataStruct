#include"..\include\Node.h"


int fillData(Node* NodePointer, int numData, char charData) 
{
	if (!NodePointer)
	{
		return -1;
	}
		
	NodePointer->numData = numData;
	NodePointer->unionData.charData = charData;

	return 0;
}

int  iter(Node* head, int fun(Node* node),int delTag) //use the fun to every node from head to tail
{	
	int flag = 0;
	Node* p = head;
	Node* temp = NULL;

	if (!p) {
		flag = -1;
	}
	else {
		//pass head information
		p = p->next;

		for (; p != NULL;)
		{
			if (delTag)
			{
				temp = p->next;
			}
			if (!fun(p)) {
				flag++;

				/*for debug
				printf_s("the loop %d has no return\n",i);
				*/

			}

			/*for debug
			printf_s("done\n");
			*/
			if (delTag)
				p = temp;
			else
				p = p->next;
		}
	}

	//the function has no return times
	return flag; 
}

int printData(Node* node)
{
	if (!node)
		return -1;
	else 
		return printf_s("%d\t%c\n", node->numData, node->unionData.charData);
}

int printNum(Node* node)
{
	if (!node)
		return -1;
	else
		return printf_s("%d\n", node->numData);
}

Node* creatLinklist() 
{
	//set flag for only one return requirement
	int flag = 0;

	Node* head = (Node*)malloc(NLEN);

	if (!head) 
	{
		return NULL;
	}
	else {	  //init
		
		head->unionData.tail = head; 

		//head int value means nodes number (head not counted)
		head->numData = 0;

		//init pointer with null
		head->next = NULL;
	}
	
	return head;
}

int addNode(Node* head, int tag, int numData , char charData)	//tag is the node tag before new node
{	
	
	int flag = 0;

	if (!head)
	{
		flag = -1;
	}
	else if (tag > head->numData) {
		flag = -1;
	}
	else {
		Node* node = (Node*)malloc(NLEN);

		if (fillData(node, numData, charData)) 
		{
			flag = -1;
		}
		else {
			Node* p = head;

			if (tag == head->numData) 
			{
				p = p->unionData.tail;

				p->next = node;
				head->unionData.tail = node;
				node->next = NULL;

				head->numData++;
			}
			else {
				for (int i = 0; i < tag; p = p->next, i++);

				node->next = p->next;
				p->next = node;

				head->numData++;
			}			
		}
	}
	return flag;
}

int delete(Node* head, int tag)		//tag is the deleted one,when tag = 0 whole linklist will be deleted
{	   
	int flag = 0;

	if (!head)
	{
		flag = -1;
	}
	else if (tag == 0) {
		if (!head->numData)
		{
			free(head);
		}
		else {
			//before delete the head,clear the content node
			clear(head);
			free(head);
		}
		printf_s("whole linklist freed\n");
	}
	else if (tag > head->numData) {
		flag = -1;
	}
	else {
		Node* p = head;

		for (int i = 1; i < tag; p = p->next, i++);

		Node* del = p->next;
		p->next = p->next->next;

		free(del);

		head->numData--;
	}

	return flag;
}

int delNext(Node* del) //remove the Node after del
{

	Node* p = del->next;
	if (!p)
		return -1;

	del->next = p->next;
	free(p);

	return 0;
}
int clear(Node* head)	//free all nodes but remain the head
{	

	if (!head)
	{
		return -1;
	}

	//delete all nodes
	iter(head, free,1);

	head->numData = 0;

	return 0;
}