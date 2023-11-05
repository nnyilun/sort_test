#ifndef SORT_FUNCTION
#define SORT_FUNCTION

int _compare_order(const void* a, const void* b);
int _compare_reverse(const void* a, const void* b);

void quicksort(int* arr, int left, int right, int order);
void BubbleSort_Raw(int* arr, int size, int order);
void BubbleSort_Optimized(int* arr, int size, int order);
void selection_sort(int* arr, int size, int order);
void insertion_sort(int* arr, int size, int order);
void shell_sort(int* arr, int size, int order);
void merge_sort(int* arr, int size, int order);
void merge_sort_BU(int* arr, int size, int order);
void quicksort_3way(int* arr, int left, int right, int order);

#endif