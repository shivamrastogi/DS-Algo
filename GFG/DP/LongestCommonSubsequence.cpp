#include<bits/stdc++.h>
#define MAXI 1000000007

using namespace std;
typedef unsigned long long int  LLD;


int lcs(string a, string b){
	int n=a.size(), m = b.size();
	
	int arr[n+1][m+1],i,j;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			
			if(j==0 || i==0)
				arr[i][j]=0;
			else if(a[i] == b[j])
				arr[i][j] = arr[i-1][j-1]+1;
			else
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
				
				//cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return arr[n][m];
}

int main()
{ 
	
	string a = "AGGTAB";
	string b = "GXTXAYB";
	
    cout<<lcs( a, b );
	return 0;
}
 