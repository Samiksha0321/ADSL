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
	b)Erase all nodes in a binary tree
	c)Create a mirror image of the tree
	d)Check two binary trees are equal or not
	e)Inorder, Preorder, Postorder traversal of tree(recursive and non-recursive)
	f)Print internal and leaf nodes
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

//	void MirrorImage(Tree A){
//		root = A.root;
//		Node *n = new Node;
//		void Copy(n){
//			if(n)
//		}
//	}

	void inorderRecursive(Node *n){
		if(n != NULL){
			inorderRecursive(n->left);
			cout<<n->data<<" ";
			inorderRecursive(n->right);
		}
	}
};

int main() {

	Tree A;

	//Tree B;
	//B = A;

	Tree C;
	//C.MirrorImage(A);

	int option;
	cout<<"Enter"
			"1. Create Tree"
			"2. Inorder Recursive"
			"3. Inorder Non-Recursive"
			"4. Preorder Recursive"
			"5. Preorder Non-Recursive"
			"6. Postorder Recursive"
			"7. Postorder Non-Recursive";
	cin>>option;
	switch(option){
	case 1: A.CreateTree();
			break;
	case 2: A.inorderRecursive(A.root);
	}

	return 0;
}
