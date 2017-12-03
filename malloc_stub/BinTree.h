#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <stack>

typedef struct BinNode
{
    int data;
	struct BinNode *lchild, *rchild;
	char flag;
}BinNode, *BinTree;

int PreOrder_NonRecursive(BinTree root);
int PostOrder_NonRecursive(BinTree root);
#endif
