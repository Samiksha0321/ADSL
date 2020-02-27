//============================================================================
// Name        : Assignment6.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Implement all the functions of a dictionary (ADT) using hashing.
 * Data: Set of (key, value) pairs, Keys are mapped to values, Keys
 * must be comparable, Keys must be unique Standard Operations:
 * Insert(key, value), Find(key), Delete(key)
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX 20

class Dictionary{
	string word;
	string meaning;
private:
	Dictionary(){
		word = '\0';
		meaning = '\0';
	}
	void print();
	friend class Hash;
};

void Dictionary::print(){
	cout<<"Enter word:\t";
	cin>>word;
	cout<<"\nEnter meaning:\t";
	cin>>meaning;
}

class Hash{
	Dictionary dict[MAX];
	void hashFunction();
	void printHashTable();

};

void Hash::printHashTable(){
	cout<<endl;
	cout<<"\tIndex\tWord\t\tMeaning"<<endl;
	for(int i=0; i<20; i++){
		cout<<"\t"<<i<<"\t"<<dict[i].word<<"\t\t"<<dict[i].meaning<<endl;
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
