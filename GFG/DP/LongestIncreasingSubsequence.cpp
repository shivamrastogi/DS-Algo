#include<bits/stdc++.h>
#define m 1000000007

using namespace std;
typedef unsigned long long int  LLD;


int lis(int* arr, int n){
	
	int list[n]={0},max=0,i,j;
	
	for(i=0;i<n;i++){
		list[i]=1;
		for(j=0;j<=i;j++){
			
			if(arr[i] > arr[j] && list[i] < list[j] + 1)
				list[i] = list[j] + 1;
		}
		// cout<<list[i]<<' ';
		if(max < list[i])
			max = list[i];
	}
	
	return max;

}

int main()
{ 
	
	int arr[]={  10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lis( arr, n );
	return 0;
}
 