#include<iostream>
using namespace std;

//Function to merge the sorted subarrays in the main array
void Merge(int a[], int first, int middle, int last){
	int sizeOfLeft = middle - first +1; //calculating the size of the left array +1 is added as the arrays are 0 based.
	int sizeOfRight = last - (middle);  
	int left[sizeOfLeft];
	int right[sizeOfRight];
	for(int i=0;i<sizeOfLeft;i++){      //filling the left array
		left[i] = a[first+i];
	}
	for(int i=0;i<sizeOfRight;i++){     //filling the right array
		right[i] = a[middle+i+1];
	}
	int indexForLeft = 0;
	int indexForRight = 0;
	int indexForMain = first;
	while(indexForRight<sizeOfRight && indexForLeft<sizeOfLeft){
		if(left[indexForLeft]<right[indexForRight]){
			a[indexForMain] = left[indexForLeft];
			indexForLeft++;
		}else{
			a[indexForMain] = right[indexForRight];
			indexForRight++;
		}
		indexForMain++;
	}

	//incase one of the arrays gets empty in that case fill the main one with the rest of the elements of the remaining array
	while(indexForRight<sizeOfRight){
		a[indexForMain] = right[indexForRight];
		indexForRight++;
		indexForMain++;
	}
	while(indexForLeft<sizeOfLeft){
		a[indexForMain] = left[indexForLeft];
		indexForLeft++;
		indexForMain++;
	}
}

//finction to divide the array in subarrays recursively
//hence reducing the size of the problem which is the essence of divide and conquer
void MergeSort(int a[], int first, int last){
	if(first<last){
		int middle = (first+last)/2;
		MergeSort(a,first,middle);
		MergeSort(a,middle+1,last);
		Merge(a,first,middle,last);
	}
}

//main fuction to initialize the unsorted array call the MergeSort and print the sorted array
int main(){
	int a[5] = {31,25,54,18,5};
	MergeSort(a,0,(int)sizeof(a)/sizeof(a[0])-1);
	//printing the sorted array
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
		cout<<a[i]<<" ";
	}
}