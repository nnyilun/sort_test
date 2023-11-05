#include <stdlib.h>
#include <time.h>
#include "sort_function.h"

int _compare_order(const void* a, const void* b);
int _compare_reverse(const void* a, const void* b);
int (*compare_order[2])(const void*, const void*) = { &_compare_order, &_compare_reverse };
void swap(int* a, int* b);

void quicksort(int* arr, int left, int right, int order);
void BubbleSort_Raw(int* arr, int size, int order);
void BubbleSort_Optimized(int* arr, int size, int order);
void selection_sort(int* arr, int size, int order);
void insertion_sort(int* arr, int size, int order);
void shell_sort(int* arr, int size, int order);
void merge_sort(int* arr, int size, int order);
void merge_sort_BU(int* arr, int size, int order);
void quicksort_3way(int* arr, int left, int right, int order);

int _compare_order(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int _compare_reverse(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int* arr, int left, int right, int order) {
    if (left > right)return;
    int mid = (*(arr + left) + *(arr + right)) / 2, l = left, r = right;
    do {
        while ((*compare_order[order])(arr + l, &mid) < 0) l++;
        while ((*compare_order[order])(arr + r, &mid) > 0) r--;
        if (l <= r) {
            swap(arr + l, arr + r);
            l++;
            r--;
        }
    } while (l <= r);
    quicksort(arr, left, r, order);
    quicksort(arr, l, right, order);
}

void BubbleSort_Raw(int* arr, int size, int order) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if ((*compare_order[order])(arr + j, arr + j + 1) > 0) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

void BubbleSort_Optimized(int* arr, int size, int order) {
    for (int i = 0; i < size - 1; i++) {
        int flag = 0;
        for (int j = 0; j < size - 1 - i; j++) {
            if ((*compare_order[order])(arr + j, arr + j + 1) > 0) {
                swap(arr + j, arr + j + 1);
                flag = 1;
            }
        }
        if (flag == 0)break;
    }
}

void selection_sort(int* arr, int size, int order) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if ((*compare_order[order])(arr + j, arr + min) < 0) min = j;
        }
		if(min != i){
			swap(arr + min, arr + i);
		}
    }
}

void insertion_sort(int* arr, int size, int order) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0 && (*compare_order[order])(arr + j, arr + j - 1) < 0; j--) {
            swap(arr + j, arr + j - 1);
        }
    }
}

void shell_sort(int* arr, int size, int order) {
    int h = 1;
    while (h < size / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < size; i++) {
            for (int j = i; j >= h && (*compare_order[order])(arr + j, arr + j - h) < 0; j -= h) {
                swap(arr + j, arr + j - h);
            }
        }
        h = h / 3;
    }
}

void merge_sort(int* arr, int size, int order) {
    int* aux = (int*)malloc(sizeof(int) * size);
    void __merge_sort(int* arr, int left, int right, int* aux, int order);
    __merge_sort(arr, 0, size - 1, aux, order);
}

void merge_sort_BU(int* arr, int size, int order) {
    int* aux = (int*)malloc(sizeof(int) * size);
    void __merge(int* arr, int left, int mid, int right, int* aux, int order);
    for (int sz = 1; sz < size; sz = sz + sz) {
        for (int lo = 0; lo < size - sz; lo += sz + sz) {
            int temp = ((lo + sz + sz - 1) < (size - 1)) ? (lo + sz + sz - 1) : (size - 1);
            __merge(arr, lo, lo + sz - 1, temp, aux, order);
        }
    }
}

void __merge_sort(int* arr, int left, int right, int* aux, int order) {
    if (right <= left) return;
    int mid = left + (right - left) / 2;
    __merge_sort(arr, left, mid, aux, order);
    __merge_sort(arr, mid + 1, right, aux, order);
    void __merge(int* arr, int left, int mid, int right, int* aux, int order);
    __merge(arr, left, mid, right, aux, order);
}
void __merge(int* arr, int left, int mid, int right, int* aux, int order) {
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++)*(aux + k) = *(arr + k);
    for (int k = left; k <= right; k++) {
        if (i > mid) *(arr + k) = *(aux + j++);
        else if (j > right) *(arr + k) = *(aux + i++);
        else if ((*compare_order[order])(aux + j, aux + i) < 0) *(arr + k) = *(aux + j++);
        else *(arr + k) = *(aux + i++);
    }
}

void quicksort_3way(int* arr, int left, int right, int order) {
    if (right <= left) return;
    int lt = left, i = left + 1, gt = right;
    int v = *(arr + left);
    while (i <= gt) {
        int cmp = (*compare_order[order])(arr + i, &v);
        if (cmp < 0)swap(arr + lt++, arr + i++);
        else if (cmp > 0)swap(arr + i, arr + gt--);
        else i++;
    }
    quicksort_3way(arr, left, lt - 1, order);
    quicksort_3way(arr, gt + 1, right, order);
}
