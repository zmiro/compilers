#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "tree.h"
using namespace std;

// g++ -std=c++98  -o object source 
//prototypes
void breakup(string); // this function breaks up a string into unique words


int main(int argc, char **argv){
	string NAMEAPPEND = ".fa2020"; // what will be appended to the file name
	string name = ""; // what the user typed
	string value; // value pulled from the file or from user	
	
	// check if user had input value for name
	if (argc < 2) {
		cout << "Keyboard input:  " ;
		getline(cin,value);
	       //cout << value << endl;  
	       breakup(value); //HERE'S WHERE I BREAK UP THE STRING INTO WORDS WHICH WILL BE SENT TO tree.buildTree(string word)
	} else {
		name = argv[1] + NAMEAPPEND;
		cout << "Your file is: " + name +"\n";	
		// in C++ book, pg 689, 693
		fstream dataFile; 	// create file stream object
	
		dataFile.open(name.c_str(),ios::in);  // open the file, ios:in reads in file, if it doesn't exist it fails
	
		if (dataFile.fail()){
			cout << name + "  did not exist \n";
			// The file does not exist
		
		} else {
			tree tree; // declare a new tree
			cout << name + "  did already exist \n";
		 	cout <<" Reading input from a file. \n";
			while (dataFile >> value){
				if(ispunct(value[value.length() -1])){
	                           	tree.buildTree(value.substr(0,value.size()-1));
					//cout << value.substr(0, value.size()-1) << endl;
				} else{
					tree.buildTree(value);
					//cout << value << endl;
				}
			}
			cout << "Display in-order:" << endl;
			tree.printInorder();
			dataFile.close();
		}  

	}// close else 	
	
return 0; 
} // close main function

void breakup(string input){
 	tree tree; // declaring a new tree
	string word = "";
	for ( int i =0; i < input.length(); i++){
		if ( isspace(input[i])|| ispunct(input[i])){
		 	if ( !isspace(input[i-1])&& !ispunct(input[i-1])){
				//cout << word << endl;
				tree.buildTree(word);
			}
		  	word = "";
		} else {
		 	word = word + input[i];
		  if (i == input.length() -1){
		  	//cout<<word<<endl;
		 	tree.buildTree(word);
		  }
		}	
	}
	cout << "Display in-order:" << endl;
	tree.printInorder();
}// close breakup function

