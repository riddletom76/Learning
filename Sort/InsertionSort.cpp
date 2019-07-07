#include<iostream>
using namespace std;
int main(){
	int a[5] = {31,25,54,18,5};
	for (int i=1;i<(sizeof(a)/sizeof(a[0]));i++){
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
		cout<<a[i]<<endl;
	}
}