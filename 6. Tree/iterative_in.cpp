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

void printIn(node *root)
{
	if(!root)
		return;
	stack<node*> s;
	
	//This loop ends only when stack is empty and value of root is NULL
	while(1)
	{
		//when root is not null we push root on stack
		//and move to root left
		if(root != NULL)
		{
			s.push(root);
			root=root->left;
		} else {
			//when root is null and stack is empty we exit
			//otherwise we get top of stack as root then print it and move to root right
			if(s.empty())
				break;
			root = s.top();
			s.pop();
			printf("%d ", root->data);
			root = root->right;
		}
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
	
	printIn(root);
}