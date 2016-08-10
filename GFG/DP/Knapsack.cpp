#include<bits/stdc++.h>
#define MAXI 1000000007

using namespace std;
typedef unsigned long long int  LLD;

//dp[i][j] : sum j using i elements (number of ways)


int knapSack(int W, int wt[],int val[],int n)
{
	int i,j,k[n+1][W+1];
		
		for(i=0;i<=n;i++){
			for(j=0;j<=W;j++){
				
				if(i==0 || j==0)
					k[i][j]=0;
				else if(wt[i-1] <= j)
					k[i][j] = max(val[i-1] + k[i-1][j-wt[i-1]],k[i-1][j]);
				else
					k[i][j] = k[i-1][j];
			}
		}
    return k[n][W];
}

int main()
{ 
	 int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    
    cout<<knapSack(W, wt, val, n);
	return 0;
}
 