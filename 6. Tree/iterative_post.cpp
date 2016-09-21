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

void postTwoStack(node *root)
{
	stack<node*> s1, s2;
	s1.push(root);
	node *temp;
	
	while(s1.empty() == false)
	{
		temp = s1.top();
		s1.pop();
		s2.push(temp);
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
	}
	
	//after all nodes are traversed the final result is saved in stack two
	//so print second stack 
	while(s2.empty() == false)
	{
		temp = s2.top();
		s2.pop();
		printf("%d ",temp->data);
	}
}

void postSingleStack(node *root)
{
	if(root == NULL)
		return;
	
	node *current = root;
	stack<node*> s;
	
	while(current != NULL || !s.empty())
	{
		if(current != NULL)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			node *temp = s.top()->right;
			if(temp == NULL)
			{
				temp = s.top();
				s.pop();
				printf("%d ", temp->data);
				
				while(!s.empty() && temp == s.top()->right)
				{
					temp = s.top();
					s.pop();
					printf("%d ", temp->data);
				}
			} else {
				current = temp;
			}
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
	
	postTwoStack(root);
	printf("\n\n");
	postSingleStack(root);
}