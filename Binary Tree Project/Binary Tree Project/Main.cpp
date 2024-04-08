// Binary Tree Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<cstdlib>

#include "BST.h"
using namespace std;

int Main()
{

	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;
	int input = 0;

	cout << "Printing the tree in order \nBefore adding numbers\n";
	myTree.PrintInOrder();

	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding numbers\n";

	myTree.PrintInOrder();
	 
	cout << endl;

	cout << "The smallest value in the tree is" << myTree.FindSmallest() << endl;
	cout << "Enter a key value to delete.  Enter -1 to stop the process.\n";
	while (input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		{
			if (input != -1)
			{
				cout << endl;
				myTree.RemoveNode(input);
				myTree.PrintInOrder();
				cout << endl;
			}
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
