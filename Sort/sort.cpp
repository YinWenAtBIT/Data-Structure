#include "sort.h"
#include "binaryHeap.h"
#include <stdlib.h>
#include <iostream>

/*插入排序*/
void InsertionSort(ElementType A[], int N)
{
	int i,j;
	ElementType temp;

	for(i=1; i<N; i++)
	{
		temp = A[i];

		for(j=i; j>0; j--)
		{
			if(temp <A[j-1])
				A[j] = A[j-1];
			else
				break;
		}
		A[j] = temp;
	}
}

/*希尔排序*/
void ShellSort(ElementType A[], int N)
{
	/*Sedgewick序列*/
	int Sedgewick[5] = {109, 41, 19, 5, 1};
	
	int i, j;
	int Index, Increament;
	ElementType temp;

	for(Index=0; Index<5; Index++)
		if(Sedgewick[Index] < N)
			break;
	if(Index == 5)
		return;

	for(; Index<5; Index++)
	{
		Increament = Sedgewick[Index];
		for(i=Increament; i<N; i++)
		{
			temp = A[i];
			for(j = i; j>Increament-1; j--)
			{
				if(temp < A[j-Increament])
					A[j] = A[j-Increament];
				else
					break;
			}
			A[j] = temp;
		}
	}
}

/*堆排序，直接调用了之前编写的二叉堆代码*/
void HeapSort(ElementType A[], int N)
{
	int i;
	PriorityQueue H = BuildHeap(A, N);
	for(i=0; i<N; i++)
		A[i] = DeleteMin(H);

	Destroy(H);
}


/*归并排序*/
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, Num, TmpPos;
	LeftEnd = Rpos -1;
	Num = RightEnd - Lpos +1;
	TmpPos = Lpos;

	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(A[Lpos] < A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	}

	/*复制剩下的数据*/
	while(Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];

	while(Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	/*拷贝回原来的数组*/
	for(i =0; i<Num; i++, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}



void Msort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center;
	if(Left < Right)
	{
		Center = (Left+Right)/2;
		Msort(A, TmpArray, Left, Center);
		Msort(A, TmpArray, Center+1, Right);
		Merge(A, TmpArray, Left, Center+1, Right);
	}
}



void MergeSort(ElementType A[], int N)
{
	ElementType * TmpArray = (ElementType *)malloc(N*sizeof(ElementType));
	if(TmpArray == NULL)
	{
		fprintf(stderr, "not enough memory\n");
		exit(1);
	}

	Msort(A, TmpArray, 0, N-1);
	free(TmpArray);
}

/*快速排序*/

void Swap(ElementType *A, ElementType *B)
{
	ElementType temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;

	/*从左到右，从小到大排列*/
	if(A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if(A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if(A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);

	Swap(&A[Center], &A[Right-1]);
	return A[Right-1];
}

#define Cutoff (3)

void Qsort(ElementType A[], int Left, int Right)
{
	int i,j;
	ElementType Pivot;
	
	Pivot = Median3(A, Left, Right);

	if(Left + Cutoff <Right)
	{
		i = Left;
		j = Right-1;
		while(1)
		{
			while(A[++i] < Pivot);
			while(A[--j] > Pivot);
			if(i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		/*将枢纽元放回中间,此时枢纽元左边的数据都比它小
		右边的数据都比它大，再对左右数据排序即可*/
		Swap(&A[i], &A[Right-1]);

		Qsort(A, Left, i-1);
		Qsort(A, i+1, Right);
	}
	else
		/*少于3个数据就直接使用插入排序更快*/
		InsertionSort(A+Left, Right-Left+1);
}

void QuickSort(ElementType A[], int N)
{
	Qsort(A, 0, N-1);
}



/*快速选择,选择完成之后，要求的第K小的数在数组下标为k-1上*/
void QSelect(ElementType A[], int k, int Left, int Right)
{
	int i,j;
	ElementType Pivot;
	
	Pivot = Median3(A, Left, Right);

	if(Left + Cutoff <Right)
	{
		i = Left;
		j = Right-1;
		while(1)
		{
			while(A[++i] < Pivot);
			while(A[--j] > Pivot);
			if(i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		/*将枢纽元放回中间,此时枢纽元左边的数据都比它小
		右边的数据都比它大，再对左右数据排序即可*/
		Swap(&A[i], &A[Right-1]);

		/*k=i+1的时候，即是i=k-1的时候，代表枢纽元就已经是要求的结果了，
		正好处在k-1上，这里不使用k-1进行判断是为了避免k=0的情况*/
		if(k <=i)
			QSelect(A, k, Left, i-1);
		else if(k>i+1)
			QSelect(A, k, i+1, Right);
	}
	else/*少于3个数据就直接使用插入排序更快*/
		InsertionSort(A+Left, Right-Left+1);
}


void QuickSelect(ElementType A[], int k, int N)
{
	QSelect(A, k, 0, N-1);
}