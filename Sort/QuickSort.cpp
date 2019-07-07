#include<iostream>
using namespace std;

int Partition(int a[], int low, int high){
	int pivot = a[low];
	int i=low;
	int j=high;
	while(i<j){
		while(a[i]<=pivot){
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	return j;
}

void QuickSort(int a[], int low, int high){
	if(low<high){
		int pivotIndex = Partition(a, low, high);
		QuickSort(a, low, pivotIndex);
		QuickSort(a, pivotIndex+1, high);
	}
}

int main(){
	int a[5] = {31,25,54,18,5};
	QuickSort(a,0,(int)sizeof(a)/sizeof(a[0])-1);
	//printing the sorted array
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
		cout<<a[i]<<" ";
	}
}