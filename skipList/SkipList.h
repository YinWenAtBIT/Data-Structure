/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/28
description:跳表
********************************************/


#define MAX_LEVEL 10 //最大层数 
//节点  
typedef  struct nodeStructure  
{  
    int key;  
    int value;  
    struct nodeStructure *forward[1];  
}nodeStructure;  
    
//跳表  
typedef  struct skiplist  
{  
    int level;  
    nodeStructure *header;  
}skiplist;  

//创建节点  
nodeStructure* createNode(int level,int key,int value);

//初始化跳表  
skiplist* createSkiplist();

//随机产生层数  
int randomLevel();
	
//插入节点  
bool insert(skiplist *sl,int key,int value);

//搜索指定key的value  
void search(skiplist *sl,int key, nodeStructure **&update); 

//删除指定的key  
bool deleteSL(skiplist *sl,int key);

void printSL(skiplist *sl);