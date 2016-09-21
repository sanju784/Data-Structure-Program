/**
 * Path from root to a node
 */
 
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n)
{
	node *newN = (node*)malloc(sizeof(node));
	newN->data=n;
	newN->left=NULL;
	newN->right = NULL;
	
	return newN;
}

bool hasPath(node *p, vector<int> &arr, int n)
{
	if(p == NULL)
		return false;
	
	arr.push_back(p->data);
	
	if(p->data == n)
		return true;
	
	if(hasPath(p->left, arr, n) || hasPath(p->right, arr, n))
		return true;
	
	arr.pop_back();
	return false;
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	
	vector<int> arr;
	if(hasPath(root, arr, 4))
	{
		for(int i=0;i<arr.size();i++)
			cout<<arr[i]<<" ";
	} else
		cout<<"No Path";
}