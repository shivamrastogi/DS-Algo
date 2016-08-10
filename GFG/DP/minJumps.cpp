#include<bits/stdc++.h>
#define MAXI 1000000007

using namespace std;
typedef unsigned long long int  LLD;


int minJumps(int arr[], int n){
	
	int jumps[n],i,j,k;
	cout<<n<<' ';
	jumps[0] = 0;
	
	for(i=1;i<n;i++){
		jumps[i] = 99999999;
		
		for(j=0;j<=i;j++){
			if(i <= j + arr[j] && jumps[i] > 1 + jumps[j] && jumps[j] != 99999999){
				jumps[i]  = jumps[j] + 1;
			}
		}
		
		cout<<jumps[i]<<' ';
	}
	
	return jumps[n-1];
}

int main()
{ 
	
	int arr[] = {1, 3, 6, 1, 0, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minJumps(arr,n);
	return 0;
}
 