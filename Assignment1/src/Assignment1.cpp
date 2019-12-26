//============================================================================
// Name        : Assignment1.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * Given binary tree with n nodes and perform following operations on it.
	a)Assign this tree to another [operator=]
	b)Erase all nodes in a binary tree    											(done)
	c)Create a mirror image of the tree												(done)
	d)Check two binary trees are equal or not
	e)Inorder, Preorder, Postorder traversal of tree(recursive and non-recursive)	(done)
	f)Print internal and leaf nodes													(done)
 */
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *right;
	Node *left;
	Node(){
		data = 0;
		right = NULL;
		left = NULL;
	}
};

class Tree{
public:
	Node *root = new Node;

	void CreateTree(){

		root = NULL;
		char c;
		do{
			Node *p = new Node;
			cout<<"Enter the value: ";
			cin>>p->data;
			if(root == NULL)
				root = p;
			else{
				Node *q = new Node;
				q = root;
				int flag=0;


				do{
					char side;
					cout<<"Add this to r or l of "<< q->data;
					cin>>side;
					if(side == 'l'){
						if(q->left == NULL){
							q->left = p;
							flag = 1;
						}
						else
							q = q->left;
					}
					if(side == 'r'){
						if(q->right == NULL){
							q->right = p;
							flag = 1;
						}
						else
							q = q->right;
					}
				}while(flag == 0);
			}
			cout<<"Add new node(y/n): ";
			cin>>c;
		}while(c == 'y');
	}

	void EraseTree(){

	}


	void inorderRecursive(Node *root){
		if(root != NULL){
			inorderRecursive(root->left);
			cout<<root->data<<" ";
			inorderRecursive(root->right);
		}
	}
	void preorderRecursive(Node *n){
		if(n != NULL){
			cout<<n->data<<" ";
			inorderRecursive(n->left);
			inorderRecursive(n->right);
		}
	}
	void postorderRecursive(Node *n){
			if(n != NULL){
				inorderRecursive(n->left);
				inorderRecursive(n->right);
				cout<<n->data<<" ";
			}
		}
	void inorderNONRecursive(Node *n){

	}
	void preorderNONRecursive(Node *n){

	}
	void postorderNONRecursive(Node *n){

	}

	void eraseNodes(Node *n){
		if(n != NULL){
			inorderRecursive(n->left);
			inorderRecursive(n->right);
			cout<<n->data<<" is deleted\n";
		}
	}

	void mirrorTree(Node *root){
		if(root != NULL){
			mirrorTree(root->left);
			mirrorTree(root->right);
			swap(root->left, root->right);
		}
	}

	void print_Leaf_and_Internal(Node *root){

	}
};

int main() {

	Tree A;

	//Tree B;
	//B = A;

	Tree C;
	//C.MirrorImage(A);
a:
	int option;
	cout<<"Enter"
			"1. Create Tree"
			"2. Inorder Recursive"
			"3. Inorder Non-Recursive"
			"4. Preorder Recursive"
			"5. Preorder Non-Recursive"
			"6. Postorder Recursive"
			"7. Postorder Non-Recursive"
			"8. Erase all nodes"
			"9. Mirror of the tree"
			"10. Print internal and leaf nodes";
	cin>>option;
	switch(option){
	case 1: A.CreateTree();
			break;
	case 2: A.inorderRecursive(A.root);
			cout<<endl;
			break;
	case 3: A.inorderNONRecursive(A.root);
			cout<<endl;
			break;
	case 4: A.preorderRecursive(A.root);
			cout<<endl;
			break;
	case 5: A.preorderNONRecursive(A.root);
			cout<<endl;
			break;
	case 6: A.postorderRecursive(A.root);
			cout<<endl;
			break;
	case 7: A.postorderNONRecursive(A.root);
			cout<<endl;
			break;
	case 8: A.eraseNodes(A.root);
			break;
	case 9: A.mirrorTree(A.root);
			break;
	case 10:A.print_Leaf_and_Internal(A.root);
			break;
	default:cout<<"\tEnter valid option."
	}
goto a;
	return 0;
}
