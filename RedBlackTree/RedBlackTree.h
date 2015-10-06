/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/4
description:自顶向下的红黑树
			自顶向下插入
			自顶向下删除
********************************************/
#include <cstdlib>

typedef int ElementType;
struct RedBlackNode;
typedef struct RedBlackNode * RedBlackTree;
typedef RedBlackTree Position;

typedef enum ColorType
{
	Red, Black
}ColorType;

struct RedBlackNode
{
	ElementType Elememt;
	RedBlackTree left;
	RedBlackTree right;
	ColorType color;

};

/*打印红黑树*/
void DoPrint(RedBlackTree T, int depth);

/*打印启动函数，右孩子为真正的红黑树*/
inline void PrintTree(RedBlackTree T)
{DoPrint(T->right, 0);}

/*初始化红黑树，如果NullNode未被初始化则给其分配空间*/
RedBlackTree Initialize();

/*需要进行旋转的时候进行旋转，旋转之前应先进行判定*/
static Position Rotate(ElementType item, RedBlackTree Parent);

/*两个孩子都是红色节点时，交换父亲和孩子节点的颜色，有必要的时候进行旋转*/
static void HandleReorient(ElementType item, RedBlackTree T);

/*插入节点，如果节点已经存在，则什么也不做*/
RedBlackTree insert(ElementType item, RedBlackTree T);

/*删除节点*/
RedBlackTree Delete(ElementType item, RedBlackTree T);

/*销毁树*/
void destroyTree(RedBlackTree T);

/*寻找树节点，如果该元素不存在，则返回其最后到达的节点*/
RedBlackTree find(ElementType item, RedBlackTree T);


/*删除只有一个孩子，或者没有孩子的节点*/
RedBlackTree DeleteNode(RedBlackTree target, RedBlackTree T);

/*右旋转*/
RedBlackTree rightSingleRotate(RedBlackTree T);

/*左旋转*/
RedBlackTree leftSingleRotate(RedBlackTree k1);