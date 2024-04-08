#include<iostream>
#include<cstdlib>

#include "BST.h"
using namespace std;



BST::BST()
{
	root = NULL;
}
BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;

}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			AddLeafPrivate(key, Ptr->left);
		}
		else
		{
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			AddLeafPrivate(key, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "The key" << key << "has already been added to the tree\n";
	}
}

BST::node* BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}
BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
	if (Ptr != NULL)
	{
		if (Ptr->key == key)
		{
			return Ptr;
		}
		else
		{
			if (key < Ptr->key)
			{
				return ReturnNodePrivate(key, Ptr->left);
			}
			else
			{
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}

int BST::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else 
	{
		return -1000;
	}
}

void BST::PrintChildren(int key)
{
	node* Ptr = ReturnNode(key);

	if (Ptr != NULL)
	{
		cout << "Parent Node = " << Ptr->key << endl;

		Ptr->left == NULL ?
			cout << "Left Child = NULL\n" :
			cout << "Left Child = " << Ptr->left->key << endl;

		Ptr->right == NULL ?
			cout << "Right Child = NULL\n" :
			cout << "Right Child = " << Ptr->right->key << endl;
	}
	else
	{
		cout << "Key" << key << "is not in the tree\n";
	}
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}

			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else
			{
				cout << "The key" << key << "was not found in the tree.\n";
			}
		}
	}
	else
	{
		cout << "The tree is empty.\n";
	}
}

void BST::RemoveRootMatch()
{
	if (root != NULL)
	{
		node* delPtr = root;
		int rootKey = root->key;
		int smallesinRightSubTree;

		//Case 0-0 children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}

		//Case 1-1 child
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout << "The root node with key" << rootKey << "was deleted." <<
				"The new root contains key" << root->key << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout << "The root node with key" << rootKey << "was deleted." <<
				"The new root contains key" << root->key << endl;
		}

		//Case 2-2 children
		else
		{
			smallesinRightSubTree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallesinRightSubTree, root);
			root->key = smallesinRightSubTree;
			cout << "The root key containing key" << rootKey <<
				"was overwritten with key" << root->key << endl;
		}
	}
	else
	{
		cout << "Cannot remove root.  The tree is empty.\n";
	}
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			PrintInOrderPrivate(Ptr->left);
		}
		cout << Ptr->key << " ";
		if (Ptr->right != NULL)
		{
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty.\n";
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}


int BST::FindSmallestPrivate(node* Ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty.\n";
		return -1000;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return FindSmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int smallesinRightSubTree;
		//Case 0-0 Children
		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			cout << "The node containing key" << matchKey << "was removed.\n";

		}

		//Case 1-1 Child
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing key" << matchKey << "was removed.\n";
		}

		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing key" << matchKey << "was removed.\n";
		}

		//Case 2-2 Children
		else
		{
			smallesinRightSubTree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallesinRightSubTree, match);
			match->key = smallesinRightSubTree;
		}
	}
	else
	{
		cout << "Cannot remove match.  The tree is empty.\n";
	}
}

BST::~BST()
{
	RemoveSubtree(root);
}

void BST::RemoveSubtree(node* Ptr)
{
	if (Ptr != NULL)
	{
		if (Ptr->left != NULL)
		{
			RemoveSubtree(Ptr->left);
		}

		if (Ptr->right != NULL)
		{
			RemoveSubtree(Ptr->right);
		}
		cout <<"Deleting the node containing the key." << Ptr->key << endl;
		delete Ptr;
	}
}


