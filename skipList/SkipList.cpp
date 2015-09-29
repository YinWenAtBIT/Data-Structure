/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/28
description:跳表
********************************************/
#include "SkipList.h"
#include<stdio.h>  
#include<stdlib.h>  
    

 
    

    
//创建节点  
nodeStructure* createNode(int level,int key,int value)  
{  
    nodeStructure *ns=(nodeStructure *)malloc(sizeof(nodeStructure)+level*sizeof(nodeStructure*));    
    ns->key=key;    
    ns->value=value;    
    return ns;    
}  
    
//初始化跳表  
skiplist* createSkiplist()  
{  
    skiplist *sl=(skiplist *)malloc(sizeof(skiplist));    
    sl->level=0;    
    sl->header=createNode(MAX_LEVEL-1,0,0);    
    for(int i=0;i<MAX_LEVEL;i++)    
    {    
        sl->header->forward[i]=NULL;    
    }  
    return sl;  
}  
    
//随机产生层数  
int randomLevel()    
{  
    int k=1;  
    while (rand()%2)    
        k++;    
    k=(k<MAX_LEVEL)?k:MAX_LEVEL;  
    return k;    
}  
    
//插入节点  
bool insert(skiplist *sl,int key,int value)  
{  
    nodeStructure **update = (nodeStructure **)calloc(MAX_LEVEL,sizeof(nodeStructure*));  
    
	search(sl, key, update);
    //不能插入相同的key  
	if(update[0] && update[0]->forward[0] &&update[0]->forward[0]->key == key)  
    {  
		free(update);
        return false;  
    }  
    
    //产生一个随机层数K  
    //新建一个待插入节点q  
    //一层一层插入  
    int k=randomLevel();  
    //更新跳表的level  
    if(k>(sl->level))  
    {  
        for(int i=sl->level; i < k; i++){  
            update[i] = sl->header;  
        }  
        sl->level=k;  
    }  
    
	nodeStructure * q=createNode(k,key,value);  
    //逐层更新节点的指针，和普通列表插入一样  
    for(int i=0;i<k;i++)  
    {  
        q->forward[i]=update[i]->forward[i];  
        update[i]->forward[i]=q;  
    }  
	free(update);
    return true;  
}  
    
//搜索指定key的value  
void search(skiplist *sl,int key, nodeStructure **&update)
{  
    nodeStructure *p,*q=NULL;  
    p=sl->header;  
    //从最高层开始搜  
    int k=sl->level;  
    //从最高层往下查找需要插入的位置  
    //填充update  
    for(int i=k-1; i >= 0; i--){  
        while((q=p->forward[i])&&(q->key<key))  
        {  
            p=q;  
        }  
        update[i]=p;  
    }     
}  
    
//删除指定的key  
bool deleteSL(skiplist *sl,int key)  
{  
    nodeStructure **update = (nodeStructure **)calloc(MAX_LEVEL,sizeof(nodeStructure*));  
	//寻找节点
	search(sl, key, update);

	nodeStructure *target;
    if(update[0])
		target = update[0]->forward[0];
	else
	{
		free(update);
		return false;
	}

	if(target && target->key == key)  
    {  
        //逐层删除，和普通列表删除一样  
        for(int i=0; i<sl->level; i++){    
            if(update[i]->forward[i]==target){    
                update[i]->forward[i]=target->forward[i];    
            }  
        }   
        free(target);  
        //如果删除的是最大层的节点，那么需要重新维护跳表的  
        for(int i=sl->level - 1; i >= 0; i--){    
            if(sl->header->forward[i]==NULL){    
                sl->level--;    
            }    
        }   
		free(update);
        return true;  
    }  
    else  
	{
		free(update);
        return false;
	}
}  
    
void printSL(skiplist *sl)  
{  
    //从最高层开始打印  
    nodeStructure *p,*q=NULL;  
    
    //从最高层开始搜  
    int k=sl->level;  
    for(int i=k-1; i >= 0; i--)  
    {  
        p=sl->header;  
        while(q=p->forward[i])  
        {  
            printf("%d -> ",p->value);  
            p=q;  
        }  
        printf("\n");  
    }  
    printf("\n");  
}  


////创建节点  
//nodeStructure* createNode(int level,int key,int value)  
//{  
//    nodeStructure *ns=(nodeStructure *)malloc(sizeof(nodeStructure)+level*sizeof(nodeStructure*));    
//    ns->key=key;    
//    ns->value=value;    
//    return ns;    
//}  
//    
////初始化跳表  
//skiplist* createSkiplist()  
//{  
//    skiplist *sl=(skiplist *)malloc(sizeof(skiplist));    
//    sl->level=0;    
//    sl->header=createNode(MAX_LEVEL-1,0,0);    
//    for(int i=0;i<MAX_LEVEL;i++)    
//    {    
//        sl->header->forward[i]=NULL;    
//    }  
//    return sl;  
//}  
//    
////随机产生层数  
//int randomLevel()    
//{  
//    int k=1;  
//    while (rand()%2)    
//        k++;    
//    k=(k<MAX_LEVEL)?k:MAX_LEVEL;  
//    return k;    
//}  
//    
////插入节点  
//bool insert(skiplist *sl,int key,int value)  
//{  
//    nodeStructure *update[MAX_LEVEL];  
//    nodeStructure *p, *q = NULL;  
//    p=sl->header;  
//    int k=sl->level;  
//    //从最高层往下查找需要插入的位置  
//    //填充update  
//    for(int i=k-1; i >= 0; i--){  
//        while((q=p->forward[i])&&(q->key<key))  
//        {  
//            p=q;  
//        }  
//        update[i]=p;  
//    }  
//    //不能插入相同的key  
//    if(q&&q->key==key)  
//    {  
//        return false;  
//    }  
//    
//    //产生一个随机层数K  
//    //新建一个待插入节点q  
//    //一层一层插入  
//    k=randomLevel();  
//    //更新跳表的level  
//    if(k>(sl->level))  
//    {  
//        for(int i=sl->level; i < k; i++){  
//            update[i] = sl->header;  
//        }  
//        sl->level=k;  
//    }  
//    
//    q=createNode(k,key,value);  
//    //逐层更新节点的指针，和普通列表插入一样  
//    for(int i=0;i<k;i++)  
//    {  
//        q->forward[i]=update[i]->forward[i];  
//        update[i]->forward[i]=q;  
//    }  
//    return true;  
//}  
//    
////搜索指定key的value  
//int search(skiplist *sl,int key)  
//{  
//    nodeStructure *p,*q=NULL;  
//    p=sl->header;  
//    //从最高层开始搜  
//    int k=sl->level;  
//    for(int i=k-1; i >= 0; i--){  
//        while((q=p->forward[i])&&(q->key<=key))  
//        {  
//            if(q->key == key)  
//            {  
//                return q->value;  
//            }  
//            p=q;  
//        }  
//    }  
//    return NULL;  
//}  
//    
////删除指定的key  
//bool deleteSL(skiplist *sl,int key)  
//{  
//    nodeStructure *update[MAX_LEVEL];  
//    nodeStructure *p,*q=NULL;  
//    p=sl->header;  
//    //从最高层开始搜  
//    int k=sl->level;  
//    for(int i=k-1; i >= 0; i--){  
//        while((q=p->forward[i])&&(q->key<key))  
//        {  
//            p=q;  
//        }  
//        update[i]=p;  
//    }  
//    if(q&&q->key==key)  
//    {  
//        //逐层删除，和普通列表删除一样  
//        for(int i=0; i<sl->level; i++){    
//            if(update[i]->forward[i]==q){    
//                update[i]->forward[i]=q->forward[i];    
//            }  
//        }   
//        free(q);  
//        //如果删除的是最大层的节点，那么需要重新维护跳表的  
//        for(int i=sl->level - 1; i >= 0; i--){    
//            if(sl->header->forward[i]==NULL){    
//                sl->level--;    
//            }    
//        }    
//        return true;  
//    }  
//    else  
//        return false;  
//}  
//    
//void printSL(skiplist *sl)  
//{  
//    //从最高层开始打印  
//    nodeStructure *p,*q=NULL;  
//    
//    //从最高层开始搜  
//    int k=sl->level;  
//    for(int i=k-1; i >= 0; i--)  
//    {  
//        p=sl->header;  
//        while(q=p->forward[i])  
//        {  
//            printf("%d -> ",p->value);  
//            p=q;  
//        }  
//        printf("\n");  
//    }  
//    printf("\n");  
//}  