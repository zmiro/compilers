// from pg 1261 of our C++ book, Starting with C++
// Specification file for the binaryTreee class
#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <iostream>
#include<cstddef>
class tree{
	private:
	
		TreeNode* root; //Pointer to the root node

		// Private member functions
		void insert (TreeNode *&, TreeNode *&);
		void printInorder(TreeNode*) const;
		void printPreorder(TreeNode*) const;
		void printPostorder(TreeNode*) const;
	public:
		// Constructor
		tree() { root = NULL;}
		//tree() { root = nullptr;}

		//Binary tree operations
        	//void insertNode(string); THIS WILL INSERT NODE WITH VALUE OF PASSED WORD
		void buildTree(string);
		void printInorder() const {printInorder(root);}
		void printPreorder() const {printPreorder(root);}
		void printPostorder() const {printPostorder(root);}
	};
	#endif
