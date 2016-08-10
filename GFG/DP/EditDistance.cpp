#include<bits/stdc++.h>
#define MAXI 1000000007

using namespace std;
typedef unsigned long long int  LLD;


int editDistance(string a, string b){
	int n=a.size(), m = b.size();
	
	int arr[n+1][m+1],i,j;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			
			if(i==0 || j==0)
				arr[i][j]=i?i:j;
				
			else if(a[i] == b[j])
				arr[i][j] = arr[i-1][j-1];
			else
				arr[i][j] = min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1]) + 1;
				cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return arr[n][m];
}

int main()
{ 
	
	string a = "geek";
	string b = "gesek";
	
    cout<<editDistance( a, b );
	return 0;
}
 