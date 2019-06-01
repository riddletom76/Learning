#include<iostream>
using namespace std;
int main(){
	int a[5] = {31,25,54,18,5};
	for(int i=0;(i<(sizeof(a)/sizeof(a[0]))); i++){ //run the outer loop till the end of the array
		bool swap = false;
		int min = a[i];
		int index = i;
		for(int j=i+1;j<(sizeof(a)/sizeof(a[0])); j++){ //run the inner loop starting from the next element from which the outer loop is pointing 
			if(min>a[j]){								//as all the elements before the outer loop are sorted in the array
				min = a[j];
				index = j;
				swap = true;//if there is a swap required which means there is one more iteration of the outer loop required
			}				//incase no swap is required the array can be treated as sorted
		}
		if(swap){
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}else{
			break;
		}
	}
	//printing the sorted array
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
		cout<<a[i]<<" ";
	}
}