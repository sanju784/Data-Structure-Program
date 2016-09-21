#include <bits/stdc++.h>
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

void printPre(node *root)
{
	if(!root)
		return;
	stack<node*> s;
	s.push(root);
	while(!s.empty())
	{
		node *temp = s.top();
		s.pop();
		printf("%d ",temp->data);
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
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
	
	printPre(root);
}