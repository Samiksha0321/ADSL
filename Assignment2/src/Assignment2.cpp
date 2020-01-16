//============================================================================
// Name        : Assignment2.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
/*	A Dictionary stores keywords & its meanings. Provide facility for
	adding new keywords (done), deleting keywords, updating values of any
	entry (done), assign a given tree into another tree (=). Provide facility to
	display whole data sorted in ascending/ Descending order (done). Also find
	how many maximum comparisons may require for finding any
	keyword. Use Binary Search Tree for implementation.
 */

#include <bits/stdc++.h>
using namespace std;

class Node{
	string keyword;
	vector<string>meaning;
	int no_of_meanings;
	Node *left;
	Node *right;
public:
	Node(){
		keyword = 'a';
		no_of_meanings = 0;
		left = NULL;
		right = NULL;
	}
	friend class Dictionary;
};

class Dictionary{
	Node *root;
public:
	Dictionary(){
		root = NULL;
	}

	void create(){
		char c;
		do
		{
			Node *p = new Node;

			cout<<"Enter the keyword: ";
			cin>>p->keyword;

			if(root==NULL)
				root = p;
			else{
				Node *q= new Node;
				q=root;
				int flag=0;
				do
				{
					if(p->keyword.compare(q->keyword) < 0){
						if(q->left==NULL){
							q->left = p;
							flag=1;
						}
						else
							q = q->left;
					}
					if(p->keyword.compare(q->keyword) > 0){
						if(q->right==NULL){
							q->right = p;
							flag=1;
						}
						else
							q = q->right;
					}

				}while(flag==0);
			}

			cout<<"How many meaning(s) of "<<p->keyword<<"?";
			cin>>p->no_of_meanings;
			string push_meaning;
			for(int i=1; i<=p->no_of_meanings; i++){
				cout<<"Enter meaning "<<i<<": ";
				cin>>push_meaning;
				p->meaning.push_back(push_meaning);
			}

			cout<<"Enter another keyword(y/n)?";
			cin>>c;
		}while(c=='y' || c=='Y');
	}

	void call_display(){
		display(root);
	}
	void display(Node *n){
		if(n != NULL){
			display(n->left);
			cout<<n->keyword<<"\t";
			display(n->right);
		}
	}

	void call_descending_display(){
		descending_display(root);
	}
	void descending_display(Node *n){
		if(n != NULL){
			descending_display(n->right);
			cout<<n->keyword<<"\t";
			descending_display(n->left);
		}
	}

	void update(){
		string word;
		cout<<"Enter the keyword to be updated: ";
		cin>>word;
		Node *q = new Node;
		q = root;
		int flag=0;
		do{
			if(q->keyword.compare(word) == 0){
				cout<<"\nKeyword found.";
				flag=1;
			}
			else if(q->keyword.compare(word) < 0){
				q = q->right;
				if(q == NULL){
					cout<<"\n No such keyword found.";
					flag = 2;
				}
			}
			else if(q->keyword.compare(word) > 0){
				q = q->left;
				if(q == NULL){
					cout<<"\n No such keyword found.";
					flag = 2;
				}
			}
		}while(flag==0);

		if(flag==1){
			cout<<"\nThese are the following meanings of the given keyword:"<<endl;
			for(int i=1; i<=q->no_of_meanings; i++){
				cout<<i<<". "<<q->meaning[i-1]<<endl;
			}
			cout<<"Which meaning would you like to update: ";
			int meaning_no;
			cin>>meaning_no;
			cout<<"\nEnter the new meaning: \t";
			cin>>q->meaning[meaning_no - 1];

			cout<<"The updated meanings of "<<q->keyword<<" are:\n";
			for(int i=1; i<=q->no_of_meanings; i++){
				cout<<i<<". "<<q->meaning[i-1]<<endl;
			}
		}
	}

};

int main() {
	Dictionary A;
	a:
	cout<<"Select:"
			"\n1. Create"
			"\n2. Ascending display"
			"\n3. Descending display"
			"\n4. Update existing keyword";
	int choice;
	cin>>choice;
	switch(choice){
	case 1: A.create();
			break;
	case 2: A.call_display();
			break;
	case 3: A.call_descending_display();
			break;
	case 4: A.update();
			break;
	default:cout<<"Select valid option.";
			break;
	}
	goto a;
	return 0;
}
