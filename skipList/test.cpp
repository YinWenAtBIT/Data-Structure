/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/28
description:Ìø±í
********************************************/
#include "SkipList.h"
#include <iostream>

int main()  
{  
    skiplist *sl=createSkiplist();  
    for(int i=1;i<=19;i++)  
    {  
        insert(sl,i,i*2);  
    }  
    printSL(sl);  
    //ËÑË÷  
    nodeStructure **update = (nodeStructure **)calloc(MAX_LEVEL,sizeof(nodeStructure*));  
	search(sl, 4, update);
	printf("i=%d\n",update[0]->forward[0]->value);  
    //É¾³ý  
    bool b=deleteSL(sl,4);  
    if(b)  
        printf("É¾³ý³É¹¦\n");  
    printSL(sl);  
	free(update);
    system("pause");  

    return 0;  
}  