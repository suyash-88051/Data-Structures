#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertBST(Node *root,int val)
{
	if(root == NULL)
	{
		return new Node(val);
	}
	if(val < root->data){
		root->left = insertBST(root->left, val);
	}
	else if(val > root->data){
		root->right = insertBST(root->right, val);
	}
	return root;
}
void Recursive_Inorder(Node *root)
{
	if(root==NULL)
		return;
	Recursive_Inorder(root->left);
	cout<< root->data <<" ";
	Recursive_Inorder(root->right);
}
void Recursive_Preorder(Node *root)
{
	if(root==NULL)
		return;
	cout<< root->data <<" ";
	Recursive_Preorder(root->left);
	Recursive_Preorder(root->right);
}
void Recursive_Postorder(Node *root)
{
	if(root==NULL)
		return;
	Recursive_Postorder(root->left);
	Recursive_Postorder(root->right);
	cout<< root->data <<" ";
}
int main()
{
	Node *root =NULL;
	int temp;
	cout<<"Enter the elements of the BST : ";
	if(temp!=-1)
		cin>>temp;
	root = insertBST(root,temp);
	while(temp!=-1)
	{
		cin>>temp;
		if(temp!=-1)
			insertBST(root,temp);
	}
	cout<<endl;
	cout<<"Inorder : ";
	Recursive_Inorder(root);
	cout<<endl;
	cout<<"Preorder : ";
	Recursive_Preorder(root);
	cout<<endl;
	cout<<"Postorder : ";
	Recursive_Postorder(root);
	cout<<endl;
	return 0;
}
