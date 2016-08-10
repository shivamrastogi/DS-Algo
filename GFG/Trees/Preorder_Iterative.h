/*
http://www.geeksforgeeks.org/iterative-preorder-traversal/
*/




#include<bits/stdc++.h>
#define m 1000000007

using namespace std;
typedef unsigned long long int  LLD;

struct node {
	int key;
	struct node* left;
	struct node* right;
};

struct node* newNode(int key){
	 struct node* temp = (struct node *) malloc( sizeof(struct node) );
	 temp->key = key;
	 temp->left = NULL;
	 temp->right = NULL;
	 return temp;
}

void preorderIterative(struct node* root){
	stack<struct node*> nodeStack;
	
	if(root == NULL)
		return;
		
	nodeStack.push(root);
	
	while(!nodeStack.empty()){
		
		root = nodeStack.top();
		cout<<root->key<<" ";
		nodeStack.pop();
		if( root->right )
			nodeStack.push(root->right);
		
		if( root->left )
			nodeStack.push(root->left);
	}
}

int main()
{ 
	int t,n,bin,ans,i,j;
	struct node* root         = newNode(23);
	root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
	
	preorderIterative(root);
	return 0;
}
 