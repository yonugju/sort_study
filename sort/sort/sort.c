#include<stdlib.h>
#include<stdio.h>
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int* base, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - 1; j++){
			if (base[j]>base[j + 1]){
				swap(base+j, base+j + 1);
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
		swap(base+min, base+j);
	}
}
int main(){
	int arr[50];
	for (int i = 0; i < 50; i++){
		arr[i] = i;
	}
	for (int i = 0; i < 50; i++){
		int temp = arr[i];
		int r = rand() % 50;
		arr[i] = arr[r];
		arr[r] = temp;
	}
	selection_sort(arr, 50);
//	bubble_sort(arr, 50);
	for (int i = 0; i < 50; i++){
		printf("%d ", arr[i]);
	}
}
//insertion_sort
//merge_sort
//quick_sort