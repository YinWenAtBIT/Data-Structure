/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/13
description:各种排序方法
********************************************/



typedef int ElementType;



/*插入排序*/
void InsertionSort(ElementType A[], int N);

/*希尔排序*/
void ShellSort(ElementType A[], int N);

/*堆排序，直接调用了之前编写的二叉堆代码*/
void HeapSort(ElementType A[], int N);

/*归并排序*/
void MergeSort(ElementType A[], int N);

/*快速排序*/
void QuickSort(ElementType A[], int N);

/*快速选择,选择完成之后，要求的第K小的数在数组下标为k-1上*/
void QuickSelect(ElementType A[], int k, int N);