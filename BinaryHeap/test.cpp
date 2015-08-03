#include "binaryHeap.h"
#include <iostream>
#include <stdlib.h>

int main()
{
	PriorityQueue H;
	H = Initialize(60);
	printf("Min element %d",H->Elements[0]);
	printf("\n");


	int i;
	for(i=0; i<30; i++)
		Insert(i*2, H);

	for(i=30; i>=0; i--)
		Insert(i*2-1, H);

	for(i=0;i<15; i++)
		printf("%d  ",DeleteMin(H));

	printf("\n");
	printBHeap(H, 0, 1);
	printf("\n");

}


