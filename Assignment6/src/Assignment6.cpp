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
public:
	Dictionary(){
		word = "\0";
		meaning = "\0";
	}
	void read();
	friend class Hash;
};

void Dictionary::read(){
	cout<<"Enter word:\t";
	cin>>word;
	cout<<"Enter meaning:\t";
	cin>>meaning;
}

class Hash{
	Dictionary dict[MAX];
public:
	void insertKey(Dictionary);
	void printHashTable();
	int findKey(string key);
	void deleteKey();
	int hashFunction(string);
	friend class Dictionary;
};

void Hash::insertKey(Dictionary d){
	int i = hashFunction(d.word);
		if(dict[i].word == "\0")
		dict[i] = d;
	else{
		while(dict[i].word != "\0"){
			i++;
		}
		dict[i] = d;
	}
	cout<<"Key inserted\n";
}

int Hash::findKey(string key){
	int flag=0;
	int i=-1;

	i = hashFunction(key);

	if(dict[i].word == "\0")
		return 0;
		//cout<<"\n"<<key<<" not found.";
	else{
		if(dict[i].word == key){
			return i;
			//cout<<"\n"<<key<<" found.";
		}
		else{
			while(dict[i].word != "\0"){
				if(dict[i].word == key){
					return i;
					//cout<<"\n"<<key<<" found.";
					flag=1;
				}
				i++;
			}
			if(flag == 0)
				return 0;
				//cout<<"\n"<<key<<" not found.";
		}
	}
	return 0;
}

void Hash::deleteKey(){										//done
	int flag;
	string key;
	cout<<"\nEnter word to be deleted:\t";
	cin>>key;
	flag = findKey(key);
	if(flag == 0)
		cout<<"\nWord not found to be deleted.\n";
	else{
		dict[flag].word = "\0";
		dict[flag].meaning = "\0";
		cout<<"\nWord deleted successfully.";
	}
}

int Hash::hashFunction(string W){							//done
	if(int(W[0]) < 96)
		return (int(W[0])-65);
	else
		return (int(W[0])-97);
}

void Hash::printHashTable(){								//done
	cout<<endl;
	cout<<"\tIndex\tWord\t\tMeaning"<<endl;
	for(int i=0; i<20; i++){
		cout<<"\t"<<i<<"\t"<<dict[i].word<<"\t\t"<<dict[i].meaning<<endl;
	}
}


int main() {

	Hash H;
	Dictionary D;

	int select, flag;
	string key;

	while(1){
		cout<<"\nSelect: \n"
				"1. Insert\n"
				"2. Display\n"
				"3. Find\n"
				"4. Delete\n"
				"5. Exit\t";
		cin>>select;
		switch(select){
			case 1:	D.read();
					H.insertKey(D);
					break;
			case 2: H.printHashTable();
					break;
			case 3: cout<<"\nEnter the word to be searched:\t";
					cin>>key;
					flag=0;
					flag = H.findKey(key);
					if(flag == 0)
						cout<<"\nWord not found.";
					else
						cout<<"\nWord found.";
					break;
			case 4: H.deleteKey();
					break;
			case 5: return 0;
			default:cout<<"\nSelect valid option:\t";
		}
	}
	return 0;
}
