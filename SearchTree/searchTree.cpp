#include "searchTree.h"


SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->lchild);
		MakeEmpty(T->rchild);
		free(T);
	}

	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if(T == NULL)
		return NULL;

	if(T->Element == X)
		return T;
	else if(X <T->Element)
		return Find(X, T->lchild);
	else
		return Find(X, T->rchild);
}

Position FindMin(SearchTree T)
{
	if(T!=NULL)
	{
		while(T->lchild !=NULL)
			T = T->lchild;

		return T;
	}
	return NULL;
}

Position FindMax(SearchTree T)
{
	if(T!= NULL)
	{
		while(T->rchild !=NULL)
			T= T->rchild;

		return T;
	}
	return NULL;
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if(T ==NULL)
	{
		T = (SearchTree)malloc(sizeof(TreeNode));
		T->Element = X;
		T->lchild = T->rchild = NULL;

	}
	else if(X< T->Element)
	{
		T->lchild = Insert(X, T->lchild);
	}
	else if(X>T->Element)
	{
		T->rchild = Insert(X, T->rchild);
	}
	return T;

}

SearchTree Delete(ElementType X, SearchTree T)
{
	Position tempCell;
	if(T ==NULL)
	{
		perror("Element not Found");
		return NULL;
	}
	if(X< T->Element)
		T->lchild = Delete(X, T->lchild);
	else if(X> T->Element)
		T->rchild = Delete(X, T->rchild);
	else
	{
		if(T->lchild && T->rchild)
		{
			tempCell = FindMin(T->rchild);
			T->Element = tempCell ->Element;
			T->rchild = Delete(T->Element, T->rchild);
		}
		else 
		{
			tempCell = T;
			if(T->lchild ==NULL)
				T = T->rchild;
			else
				T = T->lchild;
			free(tempCell);
		}
	}
	return T;

}

void PrintDepth(ElementType A, int depth)
{
	while(depth !=0)
	{
		printf("	");
		depth --;
	}
	printf("%d\n", A);
}

void PrintTree(SearchTree T, int depth)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->lchild != NULL)
		PrintTree(T->lchild, depth+1);

	PrintDepth(T->Element, depth);
	if(T->rchild !=NULL)
		PrintTree(T->rchild, depth+1);
}

void PrintTree(SearchTree T)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->lchild != NULL)
		PrintTree(T->lchild);

	printf("%d\n",T->Element);
	if(T->rchild !=NULL)
		PrintTree(T->rchild);
}