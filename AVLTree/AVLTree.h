#ifndef _AVLTREE_H
#define _AVLTREE_H

struct AVLNode;
typedef struct AVLNode * Position;
typedef struct AVLNode * AVLTree;

typedef int ElementType;

AVLTree MakeEmpty(AVLTree T);
Position Find(ElementType X, AVLTree T);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);
AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);
ElementType Retrieve(Position P);

AVLTree SingleRotateLeft(AVLTree T);
AVLTree SingleRotateRight(AVLTree T);
AVLTree DoubleRotateLeft(AVLTree T);
AVLTree DoubleRotateRight(AVLTree T);


void PrintTree(AVLTree T, int depth);
void PrintTree(AVLTree T);
void PrintDepth(ElementType A, int depth);



struct AVLNode
{
	ElementType Element;
	AVLTree Lchild;
	AVLTree Rchild;
	int Hight;
};

#endif