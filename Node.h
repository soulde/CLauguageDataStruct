#pragma once
#include<stdlib.h>
#include<stdio.h>

typedef struct Node Node;

Node* creatLinklist();

Node* delete(Node* head, int tag);

Node* addNode(Node* head, int tag, int numData, char charData);

int  iter(Node* head, int fun(Node* node));

int printData(Node* node);

Node* clear(Node* head);