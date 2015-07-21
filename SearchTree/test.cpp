#include "searchTree.h"


int main()
{

#pragma region searchtree
	int i;
	SearchTree One;
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
	Delete(20, One);

	Delete(11, One);

	Delete(3, One);

	PrintTree(One,0);



	std::cout<<std::endl;

#pragma endregion  

}