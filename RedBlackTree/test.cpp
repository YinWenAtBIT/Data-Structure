/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/4
description:自顶向下的红黑树
			自顶向下插入
			自顶向下删除
********************************************/

#include "RedBlackTree.h"
#include <iostream>


int main()
{
	RedBlackTree T  = Initialize();

	T = insert(10, T);
	T = insert(85, T);
	T = insert(15, T);
	T = insert(70, T);
	T = insert(20, T);	
	T = insert(60, T);
	T = insert(30, T);
	T = insert(50, T);
	T = insert(65, T);
	T = insert(80, T);
	T = insert(90, T);
	T = insert(40, T);
	T = insert(5, T);
	T = insert(55, T);
	T = insert(45, T);


	PrintTree(T);
	
	//RedBlackTree parent = find(50, T);
	//
	//RedBlackTree child = find(40, T);
	//
	//parent -> left = DeleteNode(child, parent->left);

	T = Delete(30, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(40, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(5, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(70, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(90, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(85, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(20, T);
	printf("\n\n\n");
	PrintTree(T);


	T = Delete(45, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(50, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(55, T);
	printf("\n\n\n");
	PrintTree(T);


	T = Delete(60, T);
	printf("\n\n\n");
	PrintTree(T);


	T = Delete(65, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(80, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(10, T);
	printf("\n\n\n");
	PrintTree(T);

	T = Delete(15, T);
	printf("\n\n\n");
	PrintTree(T);


	destroyTree(T);

}
