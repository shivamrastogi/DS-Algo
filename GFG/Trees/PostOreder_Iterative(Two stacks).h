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

void postOrderIterative(struct node* root){
	stack<struct node*> nodeStackA;
	stack<struct node*> nodeStackB;
	
	nodeStackA.push(root);
	
	while(!nodeStackA.empty()){
		root = nodeStackA.top();
		nodeStackA.pop();
		nodeStackB.push(root);
		
		if(root->left)
			nodeStackA.push(root->left);
		if(root->right)
			nodeStackA.push(root->right);
	}
	
	while(!nodeStackB.empty()){
		root = nodeStackB.top();
		nodeStackB.pop();
		cout << root->key << ' ';
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
	
	postOrderIterative(root);
	return 0;
}
 