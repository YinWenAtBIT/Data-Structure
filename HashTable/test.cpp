#include "HashTable.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	HashTable H;
	H = initializeTable(41);

	int i;
	int key;
	for(i=0; i<100; i++)
	{
		key = i;
		insertKey(key, H);
	}
	PrintHashTable(H);
	std::cout<<std::endl;
}