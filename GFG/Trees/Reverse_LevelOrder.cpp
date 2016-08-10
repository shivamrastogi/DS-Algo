/*
http://www.geeksforgeeks.org/reverse-level-order-traversal/
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

void reverseLevelOrder(struct node* root){
	queue<struct node*> nodeQueue;
	stack<struct node*> nodeStack;
	
	if( root == NULL )
		return;
	
	nodeQueue.push(root);
	
	while(!nodeQueue.empty()){
		root = nodeQueue.front();
		nodeStack.push(root);
		nodeQueue.pop();
		
		if(root->right)
			nodeQueue.push(root->right);
		if(root->left)
			nodeQueue.push(root->left);
		
	}
	
	while(!nodeStack.empty()){
		cout<< nodeStack.top()->key << ' ';
		nodeStack.pop();
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
	
	reverseLevelOrder(root);
	return 0;
}
 