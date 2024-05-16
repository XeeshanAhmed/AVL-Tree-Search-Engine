#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Node.h"
#include"linklist.h"
#include"TreeNode.h"
#include"BST.h"
using namespace std;

int main()
{
	system("color f0");
	string filename;
	cout << "Please enter a file name : ";
	//a file name with data.txt is available in this repository with list of URLs
	cin >> filename;
	BST mySearchEngine;
	bool flag = mySearchEngine.createBST(filename);
	if (flag)
	{
		string wordtosearch;
		cout << "File loaded successfully" << endl;
		cout << "Please enter a word to search : ";
		cin >> wordtosearch;
		mySearchEngine.search(wordtosearch);
		int choice;
		string word;
		bool b = true;
		while (b)
		{
			cout << "1. Insert \n2. Search\n3. Exit \nYour choice : ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Enter word to insert : ";
				cin >> word;
				//mySearchEngine.insert(word);
			}
			else if (choice == 2)
			{
				cout << "Enter word to search : ";
				cin >> word;
				mySearchEngine.search(word);
			}
			else if (choice == 3)
			{
				b = false;
			}
			else
			{
				cout << "inavlid input" << endl;
			}
		}
	}
	else
	{
		cout << "Sorry... File with name '" << filename << "' does not exists" << endl;
	}

	system("pause");
}