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
stack <int> leaf;
stack <int> internal_node;

class Node{

	int data;
	Node *right;
	Node *left;
public:
	Node(){
		data = 0;
		right = NULL;
		left = NULL;
	}
	friend class Tree;
};

class Tree{

	Node *root;
public:
	Tree(){
		root=NULL;
	}
	void CreateTree(){

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
	void callinorderRecursive(){
		inorderRecursive(root);
	}
	void inorderRecursive(Node *root){
		if(root != NULL){
			inorderRecursive(root->left);
			cout<<root->data<<" ";
			inorderRecursive(root->right);
		}
	}

	void callpreorderRecursive(){
		preorderRecursive(root);
	}
	void preorderRecursive(Node *n){
		if(n != NULL){
			cout<<n->data<<" ";
			preorderRecursive(n->left);
			preorderRecursive(n->right);
		}
	}

	void callpostorderRecursive(){
		postorderRecursive(root);
	}
	void postorderRecursive(Node *n){
			if(n != NULL){
				postorderRecursive(n->left);
				postorderRecursive(n->right);
				cout<<n->data<<" ";
			}
		}
	void inorderNONRecursive(){
		int flag=0;
		Node* p = root;
		stack<Node*>s;

		while(flag==0){
			if(p!=NULL){
				s.push(p);
				p = p->left;
			}
			else if (!s.empty()){
				cout<<"  "<<s.top()->data;
				p = s.top()->right;
				s.pop();
			}
			else
				flag = 1;
		}
	}
	void preorderNONRecursive(){
		int flag=0;
		Node* p = root;
		stack<Node*>s;

		while(flag==0){
			if(p!=NULL){
				s.push(p);
				cout<<"  "<<p->data;
				p = p->left;
			}
			else if (!s.empty()){
				p = s.top()->right;
				s.pop();
			}
			else
				flag = 1;
		}
	}
	void postorderNONRecursive(){

	}


	void calleraseNodes(){
		eraseNodes(root);
	}
	void eraseNodes(Node *n){
		if(n != NULL){
			eraseNodes(n->left);
			eraseNodes(n->right);
			cout<<n->data<<" is deleted\n";
			delete (n);
		}
	}

	void callmirrorTree(){
		mirrorTree(root);
	}
	void mirrorTree(Node *n){
		if(n != NULL){
			mirrorTree(n->left);
			mirrorTree(n->right);
			swap(n->left, n->right);
		}
	}

	void callprint_Leaf_and_Internal(){
		print_Leaf_and_Internal(root);

		cout<<"\nThe leaf nodes are:\t";
		while(leaf.size() != 0){
			cout<<leaf.top()<<"\t";
			leaf.pop();
		}
		cout<<"\nThe internal nodes are:\t";
		while(internal_node.size() != 0){
			cout<<internal_node.top()<<"\t";
			internal_node.pop();
		}
	}
	void print_Leaf_and_Internal(Node *n){

		print_Leaf_and_Internal(n->left);
		print_Leaf_and_Internal(n->right);
		if(n->left==NULL && n->right==NULL)
			leaf.push(n->data);
		else
			internal_node.push(n->data);
	}
};

int main() {
	Tree A;

a:
	int option;
	cout<<"Enter"
			"\n1. Create Tree"
			"\n2. Inorder Recursive"
			"\n3. Inorder Non-Recursive"
			"\n4. Preorder Recursive"
			"\n5. Preorder Non-Recursive"
			"\n6. Postorder Recursive"
			"\n7. Postorder Non-Recursive"
			"\n8. Erase all nodes"
			"\n9. Mirror of the tree"
			"\n10. Print internal and leaf nodes";
	cin>>option;
	switch(option){
	case 1: A.CreateTree();
			break;
	case 2: A.callinorderRecursive();
			cout<<endl;
			break;
	case 3: A.inorderNONRecursive();
			cout<<endl;
			break;
	case 4: A.callpreorderRecursive();
			cout<<endl;
			break;
	case 5: A.preorderNONRecursive();
			cout<<endl;
			break;
	case 6: A.callpostorderRecursive();
			cout<<endl;
			break;
	case 7: A.postorderNONRecursive();
			cout<<endl;
			break;
	case 8: A.calleraseNodes();
			break;
	case 9: A.callmirrorTree();
			break;
	case 10:A.callprint_Leaf_and_Internal();
			break;
	default:cout<<"\tEnter valid option.";
	}
goto a;
	return 0;
}
