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
#define Infinity 0x7FFFFFFF
#define NegInfinity 0x8FFFFFFF

Position NullNode = NULL;

static Position X, P, GP, GGP, BRO;

/*右旋转*/
RedBlackTree rightSingleRotate(RedBlackTree T)
{
	RedBlackTree k1;

	k1 = T->left;
	T->left = k1->right;
	k1->right = T;
	return k1;
}
/*左旋转*/
RedBlackTree leftSingleRotate(RedBlackTree k1)
{
	Position k2;

	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	return k2;
}


/*打印红黑树*/
void DoPrint(RedBlackTree T, int depth)
{
	if(T != NullNode)
	{
		DoPrint(T->left, depth +1);
		for(int i =0; i<depth; i++)
			printf("    ");
		printf("%d,%s\n", T->Elememt, T->color == Red? "Red":"Black");

		DoPrint(T->right, depth+1);
	}
}


/*初始化红黑树，如果NullNode未被初始化则给其分配空间*/
RedBlackTree Initialize()
{
	if(NullNode == NULL)
	{
		NullNode = (RedBlackTree)malloc(sizeof(struct RedBlackNode));
		if(NullNode == NULL)
			exit(1);
		NullNode->color = Black;
		NullNode->left = NullNode->right= NullNode;
		NullNode->Elememt = Infinity;
	}

	RedBlackTree T;
	T = (RedBlackTree)malloc(sizeof(struct RedBlackNode));
	if(T == NULL)
		exit(1);

	T->Elememt = NegInfinity;
	T->left = T->right = NullNode;
	T->color = Black;
	
	return T;
}

/*需要进行旋转的时候进行旋转，旋转之前应先进行判定*/
static Position Rotate(ElementType item, RedBlackTree Parent)
{
	if(item < Parent->Elememt)
		return Parent->left = item<Parent->left->Elememt? 
			rightSingleRotate(Parent->left):
			leftSingleRotate(Parent->left);
	else
		return Parent->right = item <Parent->right->Elememt?
			rightSingleRotate(Parent->right):
			leftSingleRotate(Parent->right);
}

/*两个孩子都是红色节点时，交换父亲和孩子节点的颜色，有必要的时候进行旋转*/
static void HandleReorient(ElementType item, RedBlackTree T)
{
	X->color = Red;
	X->left->color = Black;
	X->right->color = Black;

	if(P->color == Red)
	{
		GP->color = Red;
		if((item< P->Elememt) != (item < GP->Elememt))
			//P = Rotate(item, GP);
			Rotate(item, GP);

		X = Rotate(item, GGP);
		X->color =Black;

	}
	T->right->color = Black;
}

/*插入节点，如果节点已经存在，则什么也不做*/
RedBlackTree insert(ElementType item, RedBlackTree T)
{
	X = P =GP = T;
	NullNode->Elememt = item;
	while(X->Elememt != item)
	{
		GGP = GP; GP = P; P =X;
		if(item<X->Elememt)
			X = X->left;
		else
			X = X->right;
		if(X->left->color == Red && X->right->color == Red)
			HandleReorient(item, T);
	}
	if(X != NullNode)
		return NullNode;

	X = (RedBlackTree)malloc(sizeof(struct RedBlackNode));
	X->Elememt = item;
	X->left = X->right = NullNode;
	
	if(item<P->Elememt)
		P->left = X;
	else
		P->right = X;

	HandleReorient(item, T);
	return T;
}



/*销毁树*/
void destroyTree(RedBlackTree T)
{
	if(T != NullNode)
	{
		destroyTree(T->left);
		destroyTree(T->right);
		free(T);
	}
}


RedBlackTree find(ElementType item, RedBlackTree T)
{
	RedBlackTree Parent;
	while(T != NullNode && T->Elememt != item)
	{
		Parent = T;
		if(item <T->Elememt)
			T =T->left;
		else
			T =T->right;
	}
	if(T == NullNode)
		return Parent;
	else
		return T;
}

ElementType findItem(ElementType item);
void solveStep2A23();
void solve2B();
void normalDown(ElementType item);

/*删除节点*/
RedBlackTree Delete(ElementType item, RedBlackTree T)
{
	T->color =Red;
	X= T->right; 
	BRO = T->left;
	GP = GGP = P = T;

	while(X != NullNode)
	{
		/*Setp2，又分成2A或者2B*/
		/*Step 2A*/
		if(X->left->color == Black && X->right->color == Black)
		{
			if(BRO->left->color == Black && BRO->right->color == Black)
			{
				/*step 2A1*/
				P->color =Black;
				X->color = Red;
				if(BRO != NullNode)
					BRO->color = Red;
			}
			else 
				/*step 2A23*/
				solveStep2A23(); 
			
			/*完成X染色为红色，父亲节点变为黑色*/
			if(X->Elememt == item)
				/*完成前进工作，或者完成删除,以X是否为NullNode区分*/
				item = findItem(item);
			else	
				/*没有找到节点时前进，然后进入step2*/
				normalDown(item);

		}
		/*step 2B*/
		else
		{	
			if(X->Elememt != item)
				/*step 2B,正常下降*/
				normalDown(item);
			
			else
				item = findItem(item);
			
			/*如果已经完成了删除，则X变成了NullNode*/
			if(X == NullNode)
				break;

			/*没有完成删除，则此时已经完成了下降*/
			if(X->color == Black)
				/*兄弟节点必然是红色，进行旋转，旋转之后X变成黑色，BRO变成黑色，P变成红色，
				回到Step2，再对X进行变换成红色，变成红色之后，再进行判断X是否是要找的节点*/
				solve2B();
			else if(X->Elememt != item)
				/*红色继续下降，X与BRO将都会是黑色*/
				normalDown(item);
			else
				item = findItem(item);
		}
	}

	/*Step4， 3已经在上面完成完成*/
	T->color = Black;
	T->right ->color = Black;

	return T;
}


RedBlackTree DeleteNode(RedBlackTree target, RedBlackTree T)
{
	RedBlackTree origin = T;
	RedBlackTree Parent 
		;
	while(T != target)
	{
		Parent = T;
		if(target->Elememt < T->Elememt)
			T= T->left;
		else
			T = T->right;
	}

	if(T == origin)
	{
		RedBlackTree temp;
		if(T->right != NullNode)	
			temp =T->right;
		else
			temp = T->left;

		free(T);	
		return temp;
	}

	if(Parent->right == T)
	{
		if(T->right != NullNode)
			Parent->right = T->right;
		else
			Parent->right = T->left;
	}
	else
	{
		if(T->right != NullNode)
			Parent->left = T->right;
		else
			Parent->left = T->left;
	}
	free(T);
	return origin;

}

ElementType findItem(ElementType item)
{
	ElementType temp;
	RedBlackTree ToDelete;
	/*如果是要寻找的点，先判断是否是叶子节点，不是再通过替换节点删除*/
	if(X->left == NullNode && X->right == NullNode)
	{
		if(P->right == X)
			P->right = NullNode;
		else
			P->left = NullNode;

		free(X);
		X = NullNode;
		temp = item;
	}
	else
	{
		/*不是叶子节点*/
		if(X->right != NullNode)
		{
			/*从右边寻找一个最小的节点放在X的位置上*/
			ToDelete = find(item, X->right);
			X->Elememt = ToDelete->Elememt;
			temp = ToDelete->Elememt;
			if(ToDelete ->color == Red)
			{
				/*如果找的节点是红色，可以直接删去该节点*/
				X->right = DeleteNode(ToDelete, X->right);
				X = NullNode;
			}
			else
			{
				/*A2中：往右前进,此时新的X，一定是黑色，兄弟BRO也一定是黑色，此时就回到了step2
				  B2中：右前进,此时新的X，可能是红色也可能是黑色，如果是红色的话，一定不是ToDelete节点，因为在上面已经排除过了*/
				GP = P; P= X; BRO = P->left;	
				X = X->right;
			}
		}
		else
		{
			/*从左边寻找一个最大的节点放在X的位置上*/
			ToDelete = find(item, X->left);
			X->Elememt = ToDelete->Elememt;
			temp = ToDelete->Elememt;
			if(ToDelete ->color == Red)
			{
				/*如果找的节点是红色，可以直接删去该节点*/
				X->left = DeleteNode(ToDelete, X->left);
				X = NullNode;
			}
			else
			{
				/*往左前进,此时新的X，一定是黑色，兄弟BRO也一定是黑色，此时就回到了step2
				B2中：右前进,此时新的X，可能是红色也可能是黑色，如果是红色的话，一定不是ToDelete节点，因为在上面已经排除过了*/
				GP = P; P= X; BRO = P->right;
				X = X->left;
			}
						
		}

	}

	return temp;
}


void solveStep2A23()
{
	/*兄弟在右边*/
	if(P->left == X)
	{
					
		if(BRO->left->color == Red)
		{
			/*step 2A2*/
			P->color = Black;
			X->color = Red;
			P->right =  rightSingleRotate(BRO);
			if(GP->left == P)
				GP->left = leftSingleRotate(P);
			else
				GP->right = leftSingleRotate(P);
		}
		else
		{
			/*step 2A3*/
			X->color = Red;
			P->color = Black;
			BRO->color = Red;
			BRO->right->color = Black;

			if(GP->right == P)
				GP->right = leftSingleRotate(P);
			else
				GP->left = leftSingleRotate(P);
		}
	}
	/*兄弟在左边*/
	else
	{
		if(BRO->right->color == Red)
		{
			/*step 2A2*/
			X->color = Red;
			P->color = Black;
			P->left = leftSingleRotate(BRO);
			if(GP->left == P)
				GP->left = rightSingleRotate(P);
			else
				GP->right = rightSingleRotate(P);
		}
		else
		{
			/*step 2A3*/
			X->color = Red;
			P->color = Black;
			BRO->color = Red;
			BRO->left->color = Black;

			if(GP->right == P)
				GP->right = rightSingleRotate(P);
			else
				GP->left = rightSingleRotate(P);
		}
	}

}

void solve2B()
{
	BRO->color = Black;
	P->color = Red;
	if(P->left == X)
	{
		if(GP->left == P)
			GP->left = leftSingleRotate(P);
		else
			GP->right = leftSingleRotate(P);
		BRO = P->right;
	}
	else
	{
		if(GP->left == P)
			GP->left = rightSingleRotate(P);
		else
			GP->right = rightSingleRotate(P);

		BRO = P->left;
	}

	
}


void normalDown(ElementType item)
{
	if(item<X->Elememt)
	{
		GP = P; P= X; BRO = P->right;
		X= X->left;
	}
	else
	{
		GP = P; P= X; BRO = P->left;
		X = X->right;
	}
}







///*因为X至少有一个红色节点，所以不会是叶子节点，一定有孩子，并且此时X是黑色的节点*/
//				if(X->right != NullNode)
//				{
//					/*从右边寻找一个最小的节点放在X的位置上*/
//					ToDelete = find(item, X->right);
//					X->Elememt = ToDelete->Elememt;
//					if(ToDelete ->color == Red)
//					{
//						/*如果找的节点是红色，可以直接删去该节点*/
//						X->right = DeleteNode(ToDelete, X->right);
//						break;
//					}
//					else
//					{
//						/*往右前进,此时新的X，可能是红色也可能是黑色，如果是红色的话，
//						一定不是ToDelete节点，因为在上面已经排除过了*/
//						X = X->right;
//						/*要删除的点值变化成新的*/
//						item = ToDelete->Elememt;
//					}
//					
//				}
//				else
//				{
//					/*从左边寻找一个最大的节点放在X的位置上*/
//					ToDelete = find(item, X->left);
//					X->Elememt = ToDelete->Elememt;
//					if(ToDelete ->color == Red)
//					{
//						/*如果找的节点是红色，可以直接删去该节点*/
//						X->left = DeleteNode(ToDelete, X->left);
//						break;
//					}
//					else
//					{
//						/*往左前进,此时新的X，可能是红色也可能是黑色，如果是红色的话，
//						一定不是ToDelete节点，因为在上面已经排除过了*/
//						X = X->left;
//						item = ToDelete->Elememt;
//					}
//				}


///*X是红色，先判断是否是要寻找的点,不是下降，进入Step2， 因为此时P变成红色，X和T都变成黑色*/
//				if(X->Elememt == item)
//				{
//					/*如果是要寻找的点，先判断是否是叶子节点，不是再通过替换节点删除*/
//					if(X->left == NullNode && X->right == NullNode)
//					{
//						if(P->right == X)
//							P->right = NullNode;
//						else
//							P->left = NullNode;
//
//						free(X);
//					}
//					else
//					{
//						/*不是叶子节点*/
//						if(X->right != NullNode)
//						{
//							/*从右边寻找一个最小的节点放在X的位置上*/
//							ToDelete = find(item, X->right);
//							X->Elememt = ToDelete->Elememt;
//							if(ToDelete ->color == Red)
//							{
//								/*如果找的节点是红色，可以直接删去该节点*/
//								X->right = DeleteNode(ToDelete, X->right);
//								break;
//							}
//							else
//							{
//								/*往右前进,此时新的X，一定是黑色，兄弟BRO也一定是黑色，此时就回到了step2*/
//								X = X->right;
//								/*要删除的点值变化成新的*/
//								item = ToDelete->Elememt;
//							}
//						}
//						else
//						{
//							/*从左边寻找一个最大的节点放在X的位置上*/
//							ToDelete = find(item, X->left);
//							X->Elememt = ToDelete->Elememt;
//							if(ToDelete ->color == Red)
//							{
//								/*如果找的节点是红色，可以直接删去该节点*/
//								X->left = DeleteNode(ToDelete, X->left);
//								break;
//							}
//							else
//							{
//								/*往左前进,此时新的X，一定是黑色，兄弟BRO也一定是黑色，此时就回到了step2*/
//								X = X->left;
//								item = ToDelete->Elememt;
//							}
//						
//						}