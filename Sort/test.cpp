#include "sort.h"
#include <iostream>
#include <stdlib.h>

#define random(x) (rand()%x)


int main()
{
	int randData[6][5000];
	int i,j;
	for(i=0; i<6; i++)
		for(j=0; j<5000; j++)
			randData[i][j] = random(5000);
		

	InsertionSort(randData[0], 5000);

	ShellSort(randData[1], 5000);

	HeapSort(randData[2], 5000);

	MergeSort(randData[3], 5000);

	QuickSort(randData[4], 5000);

	QuickSelect(randData[5], 10, 5000);
}