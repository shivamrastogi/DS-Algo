#include<bits/stdc++.h>
#define MAXI 1000000007

using namespace std;
typedef unsigned long long int  LLD;


int minCost(int cost[3][3], int n, int m){
	
	
	int arr[3][3],i,j;
	
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			
			if(i==0 && j==0)
				arr[i][j]=0;
			else if(i == 0 && j !=0 )
				arr[i][j] = arr[i][j-1];
			else if(j == 0)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = min(min(arr[i-1][j-1],arr[i][j-1]),arr[i-1][j]);
				
			arr[i][j]+=cost[i][j];
				cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return arr[n][m];
}

int main()
{ 
	
	int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	
    cout<<minCost(cost, 2, 2 );
	return 0;
}
 