#include<iostream>
using namespace std;
int main(){
	int a[5] = {31,25,54,18,5};
	for(int i=0;i<(sizeof(a)/sizeof(a[0]))-1;i++){ //run the outer loop till last but one element of the array as each inner loop checks for one element ahead
		for(int j=0;j<(sizeof(a)/sizeof(a[0])-i-1);j++){ //run the inner loop till the element which is not yet bubbled up to its position
			if(a[j]>a[j+1]){							 //each iteration bubbles up the highest element of that iteration to the end of array
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}

	//printing the sorted array
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
		cout<<a[i]<<" ";
	}
}