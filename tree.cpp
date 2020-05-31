// Implementation file for the binaryTree class
#include <iostream>
#include <cstddef>
#include "tree.h"
#include <fstream>
#include <string>
using namespace std;


// Accepts a TreeNode pointer and a pointer to a node. 
// This function inserts the node into the tree pointed to by the TreeNode Pointer.
// This function is called recursively.

void tree::insert(TreeNode *&nodePtr, TreeNode *&newNode){

	if(nodePtr == NULL){ nodePtr = newNode; // insert the node.
	}else if (newNode->wordLength == nodePtr->wordLength){
		nodePtr->word = nodePtr->word+" "+newNode->word;
	       // cout << "list now equals: "<< nodePtr->word << endl;
       }else if (newNode->wordLength < nodePtr->wordLength){
		insert(nodePtr->left,newNode); // search the left branch
	}else {
		insert(nodePtr->right, newNode); // search the right branch
	}
}// close insert function
	

// insertNode creates a new mode to hold num as its value, and passes it to the insert function

//void tree::insertNode(string word){
void tree::buildTree(string word){

	TreeNode* newNode = NULL; // Pointer to a new node
	//create a new node and store num in it
	newNode = new TreeNode;
	newNode->word = word;
	newNode->wordLength = newNode->word.length();
	//newNode->indent = 0;
	newNode->left = newNode->right = NULL;

	// insert the node
	insert(root, newNode);

}// close insertNode

// printInOrder member function displays the values in the subtree pointed
// to by the nodePtr via inorder traversal
void tree::printInorder(TreeNode* nodePtr) const{
	
	if (nodePtr){
		printInorder(nodePtr->left);
		cout << nodePtr->word << endl;
		printInorder(nodePtr->right);
	}
}// close printInOrder

//printPreOrder member function displays the values in the subtree pointed
//to by nodePtr via preorder traversal

void tree::printPreorder(TreeNode* nodePtr) const {

	if(nodePtr){
		cout<< nodePtr->word << endl;
		printPreorder(nodePtr->left);
		printPreorder(nodePtr->right);
	}
}//close printPreOrder

// printPostOrder member function displays the values in the subtree pointed
// to the nodePtr,via post traversal
void tree::printPostorder(TreeNode* nodePtr) const {	

	if(nodePtr){
		printPostorder(nodePtr->left);
		printPostorder(nodePtr->right);
		cout<< nodePtr->word << endl;
	}
}//close printPostOrder

		 	


