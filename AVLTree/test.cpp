#include "AVLTree.h"
#include <stdlib.h>
#include <iostream>

int main()
{

#pragma region AVLTree
	int i;
	AVLTree One;
	One = NULL;
	One = Insert(10, One);

	for(i = 0; i<10; i++)
	{
		One = Insert(2*i, One);
	}
	for(i = 0; i<10; i++)
	{
		One = Insert(2*i+1, One);
	}
	
	PrintTree(One,0);
	One = Delete(20, One);

	//printf("\n\nDelete 11 \n");
	//Delete(11, One);
	//PrintTree(One,0);

	//printf("\n\nDelete 3 \n");
	//One =Delete(3, One);
	//PrintTree(One,0);

	//printf("\n\nDelete 1 \n");
	//One =Delete(1, One);
	//PrintTree(One,0);

	//printf("\n\nDelete 0 \n");
	//One =Delete(0, One);
	//PrintTree(One,0);

	//printf("6's height = %d\n",One->Lchild->Hight);
	//printf("14's height = %d\n",One->Hight);

	//printf("\n\nDelete 16 \n");
	//One =Delete(16, One);
	//PrintTree(One,0);

	//printf("\n\nDelete 6 \n");
	//One =Delete(6, One);
	//PrintTree(One,0);

	AVLTree temp10;


	printf("\n\nDelete 7,9,11,13,8,12 \n");
	/*删除时需要保持赋值的，不能让返回值滞空，因为旋转之后可能根节点改变*/
	One =Delete(7, One);
	One =Delete(9, One);
	One =Delete(11, One);
	One =Delete(13, One);

	temp10 = Find(10,One);
	printf("10's height = %d\n",temp10->Hight);

	One =Delete(8, One);
	temp10 = Find(10,One);
	printf("10's height = %d\n",temp10->Hight);

	One =Delete(12, One);
	temp10 = Find(10,One);
	printf("10's height = %d\n",temp10->Hight);

	PrintTree(One,0);


	std::cout<<std::endl;

#pragma endregion  

}