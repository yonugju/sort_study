#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#define N 50
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void merge(int*a, int a_size, int*b, int b_size, int* dst){
	int i = 0, j = 0, k = 0;
	while (i < a_size&& j < b_size){
		if (a[i] < b[j]) dst[k++] = a[i++];
		else dst[k++] = b[j++];
	}
	while (i < a_size)dst[k++] = a[i++];
	while (j < b_size)dst[k++] = b[j++];
}

void merge_sort(int* base, int size){
	int* temp = (int*)malloc(sizeof(int)*size);
	int* p = base;
	int* q = temp;
	int i, m = 1;
	while (m < size){
		for (i = 0; i < size; i += m * 2){
			int fs = m, ss = m;
			if (size - i < m * 2){
				ss = size - (i + m);
				if (size - i < m){
					fs = size - i;
					ss = 0;
				}
			}
			merge(p + i, fs, p + i + m, ss, q + i);
		}
		m *= 2;
		int* pt = p;
		p = q;
		q = pt;
	}
	if (p != base)
		memcpy(base, p, size*sizeof(int));
}
void sort3(int* a, int* b, int* c){
	if (*a > *b) swap(a, b);
	if (*a > *c) swap(a, c);
	if (*b > *c) swap(b, c);
}
int partition(int* base, int size){
	sort3(base + size / 2, base, base + size - 1);
	int* p = base;
	int L = 0, R = size;
	while (1){
		while (base[++L] < *p);
		while (base[--R]> *p);
		if (L > R)break;
		swap(base + L, base + R);
	}
	swap(p, base + R);
	return R;
}
void quick_sort(int* base, int size){
	if (size > 1){
		int p = partition(base, size);
		quick_sort(base, p);
		quick_sort(base + p + 1, size - p - 1);
	}
}
//void pivot(int *base, int left, int right){
//
//	int L = left, R = right;
//	base[(left + right) / 2];
//	while (L <= R) {
//		while (base[L] < pivot){
//			L++;
//		}
//		while (base[R] > pivot){
//			R--;
//		}
//		if (L <= R) {
//			if (L != R) {
//				swap(base + L, base + R);
//			}
//			L++; R--;
//		}
//	}
//}
//void quick_sort(int *base, int size){
//	
//	pivot(base, 0, size);
//	if (left < R)
//		quick_sort(base, left, R);
//	if (L < right)
//		quick_sort(base, L, right);
//}

void insertion_sort(int *base, int size){
	int temp;
	int j;
	for (int i = 0; i < size; i++){
		temp = base[i];
		j = i - 1;
		while (j >= 0 && temp < base[j])
		{
			base[j + 1] = base[j];
			j = j - 1;
		}
		base[j + 1] = temp;
	}
}

//31 2 44 56 3
//2 31 44 56 3

void bubble_sort(int* base, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - 1; j++){
			if (base[j]>base[j + 1]){
				swap(base + j, base + j + 1);
			}
		}
	}
}
void selection_sort(int* base, int size){
	int temp;
	for (int j = 0; j < size; j++){
		int min;
		min = j;
		for (int i = j; i < size; i++){
			if (base[min]>base[i]){
				min = i;
			}
		}
		swap(base + min, base + j);
	}
}
int main(){
	int arr[N];
	for (int i = 0; i < N; i++){
		arr[i] = i;
	}
	for (int i = 0; i < 50; i++){
		int temp = arr[i];
		int r = rand() % 50;
		arr[i] = arr[r];
		arr[r] = temp;
	}
	//	selection_sort(arr, 50);
	//	bubble_sort(arr, 50);
	//	insertion_sort(arr, N);
	//quick_sort(arr, N);
	merge_sort(arr, N);
	for (int i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
}
//merge_sort