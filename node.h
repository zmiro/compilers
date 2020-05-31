// from pg 1261 of our C++ book, Starting with C++
// Specification file for the binaryTreee class
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
 
		struct TreeNode{
		        string word; // holds the word entered from file/keyboard
		        int wordLength;//tells how long the word TreeNode.word attribute is
		     	int indent;   // tells how much one needs to indent the TreeNode.word when printing to file
			TreeNode* left; // The pointer to the left child node
			TreeNode* right; // The pointer to the right child node
		};
	
	
#endif
