#pragma once
#include<stdlib.h>

#define BTLEN sizeof(BT)


typedef struct BinaryTree BT;

struct BinaryTree 
{
    //Data
    int numData;
    char charData;

    //Pointer
    BT* left;
    BT* right;
};


BT* BTinit(int num ,char letter);

int fillBTData(BT* BTPointer, int numData, char charData);
