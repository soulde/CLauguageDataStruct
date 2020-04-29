#include"Node.h"

typedef union headData
{
	//charData for standrad nodes
	char charData;

	//point to tail node for head node
	Node* tail;

}headData;
typedef struct Node
{
	//data
	int numData;
	headData unionData;

	//Linklist pointer
	Node* next;
}Node;

int fillData(Node* NodePointer, int numData, char charData) {

	if (NodePointer == NULL)
		return 0;

	NodePointer->numData = numData;
	NodePointer->unionData.charData = charData;
	return 1;
}


Node* creatLinklist() {
	//set flag for only one return requirement
	int flag = 1;

	Node* head = (Node*)malloc(sizeof(Node));

	if (head == NULL) {
		flag = 0;
	}
	else {	  //init
		
		head->unionData.tail = head; 

		//head int value means nodes number (head not counted)
		head->numData = 0;

		//init pointer with null
		head->next = NULL;
	}

	
	if (flag)
		return head;
	else
		return NULL;
}

Node* addNode(Node* head, int tag, int numData , char charData) {	//tag is the node tag before new node

	int flag = 1;

	if (tag > head->numData) {
		flag = 0;
	}
	else {
		Node* node = (Node*)malloc(sizeof(Node));

		if (!fillData(node, numData, charData)) {
			flag = 0;
		}
		else {

			Node* p = head;
			if (tag == head->numData) {
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
	if (flag)
		return head;
	else
		return NULL;
}

Node* delete(Node* head, int tag) {	   //tag is the deleted one
	int flag = 1;
	if (tag == 0) {
		free(head);
		printf_s("head node freed\n");
		flag = 0;
	}
	else if (tag < head->numData) {
		flag = 0;
	}
	else {
		Node* p = head;

		for (int i = 1; i < tag; p = p->next, i++);
		Node* del = p->next;
		p->next = p->next->next;

		free(del);
		head->numData--;
	}

	if (flag)
		return head;
	else
		return NULL;
}

int  iter(Node* head, int fun(Node* node)) {	//use the fun to every node from head to tail
	int flag = 1;
	Node* p = head;
	Node* temp =NULL;

	if (p == NULL) {
		flag = 0;
	}
	else {
		//pass head information
		p = p->next;

		for (int i =1; p != NULL; p = temp,i++)
		{
			temp = p->next;

			if (!fun(p)) {
				flag--;

				/*for debug
				printf_s("the loop %d has no return\n",i);
				*/
				
			}

			/*for debug
			printf_s("done\n");
			*/
		}
	}
	
	return flag; 
}

int printData(Node* node)
{
	if (node != NULL)
		return printf_s("%d\t%c\n", node->numData, node->unionData.charData);
	else
		return node;
}

Node* clear(Node* head) {	//free all nodes but remain the head
	//delete all nodes
	iter(head, free);
	head->numData = 0;

	return head;
}