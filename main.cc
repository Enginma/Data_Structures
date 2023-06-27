// Xianqi Cao U83561269 -- Code
// Matthew Keen U44822882 -- Report

#include "BinaryTree.h"
#include <iostream>

using namespace std;

// These two functions I grabbed from test.cc to help test the program. 


void func2( const int& src, int arr[], int &index)
  // A test function for the function-based 
{
  cout << src << " ";
  arr[index] = src;
  ++index;
}


int complete_tree_height2( int n )
  // Returns the height of a complete binary tree having 'n' nodes
{
  int h = 0;
  // essentially, take the base-2 logarithm of 'n'
  while (n > 0) {
    n /= 2;
    h++;
  }
  return h;
}





// In the main function, we first make two int variables choice for the prompt inputs and value for the inputted int value. 
// As well as an int array with size 256.

int main() {
    int choice;
    int value;
    int elements[256];
    for (int k = 1; k <= 256; k++)
        elements[k] = k;

    int array[500];
    int index = 1;

    bool emptyTree = 1;

    BinaryTree<int> tmp;
    // Construct a PDF object to write the tree output
    PDF *pdf = new PDF("trees.pdf");
    




    // This is from test.cc file as well, it creates the base of the tree for later add/delete functions. 
    // Create a new binary tree, having 'n' elements

    // *************************************************************************************

    int n = 0;  // <-- try changing the value of 'n', right now its 12 nodes to start with but you can change it however you like!. 
    BinaryTree<int> tree(elements, n);


// These three lines below draws the tree. 
    ostringstream ostring;
    ostring << "Complete tree having " << n << " nodes";
    tree.display(pdf, ostring.str());


// The program prompts for user to read. 

    cout << "------------------------------------------------------------" << endl;
    cout << "Menu:" << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Delete Node" << endl;
    cout << "3. Check Preorder" << endl;
    cout << "4. Check Inorder" << endl;
    cout << "5. Check Postorder" << endl;
    cout << "6. Quit" << endl;


// A while loop that will run until the user inputs 6. If user enters a letter or symbol the program will end with an error message. 
// Everytime 1 through 5 is pressed, a new tree will be drawn on the pdf file with its corresponding function. 

    while (choice != 6) {
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter 1-6 as choice." << endl;
            break;
        }
        int index = 1;


// If the choice is equal to 1, we ask the user for a value to insert to the tree and we implement n by 1 for the pdf file's
// message and we display a new tree on the pdf file. 

        if (choice == 1) {

            cout << "Enter the value to insert: ";
            cin >> value;
            tree.insert_node(value);
            cout << "Node inserted!" << endl;
            n++;
            ostringstream ostring;
            ostring << "Complete tree having " << n << " nodes (Insert)";
            tree.display(pdf, ostring.str());
        } 

// If the choice is 2, we ask for the value that the user want to delete and we delete using the delete function. 
// The delete function needs 2 parameters so I made a new function called get root that simply gets the current root value and second
// parameter is the value we want to delete. We then decrement n by 1 for printing purposes and draw a new tree with the deleted node 
// not present. 

        else if (choice == 2) {
            cout << "Enter the value to delete: ";
            cin >> value;
            tree.delete_node(tree.get_root(), value);
            n--;
            if (n < 0){

            cout << "Nothing to delete!" << endl;
            n = 0;
            }

            else if (n >= 0) { 
            cout << "Node deleted!" << endl;
            }
            
            ostringstream ostring;
            ostring << "Complete tree having " << n << " nodes (Delete)";
            tree.display(pdf, ostring.str());

        } 

// If the user press 3 we will be displaying in the terminal of the preorder traversal. A new tree will be drawn as well but it will
// appear the same as this is simply just a way to read the tree and not changing the tree. 

        else if (choice == 3) {
            cout << "Preorder Traversal: ";
            tree.preorder(func2, array, index);
            tmp = BinaryTree<int>(array, tree.node_count());
            cout << endl;
            

            ostringstream ostring;
            ostring << "Complete tree with preorder traversal. " << endl ;
            tmp.display(pdf, ostring.str());
        } 

// If the user press 4 we will be displaying in the terminal of the inorder traversal. A new tree will be drawn as well but it will
// appear the same as this is simply just a way to read the tree and not changing the tree. 

        else if (choice == 4) {
            cout << "Inorder Traversal: ";
            tree.inorder(func2, array, index);
            tmp = BinaryTree<int>(array, tree.node_count());
            cout << endl;

            ostringstream ostring;
            ostring << "Complete tree with inorder traversal. " << endl;
            tmp.display(pdf, ostring.str());
        } 

// If the user press 5 we will be displaying in the terminal of the postorder traversal. A new tree will be drawn as well but it will
// appear the same as this is simply just a way to read the tree and not changing the tree. 

        else if (choice == 5) {
            cout << "Postorder Traversal: ";
            tree.postorder(func2, array, index);
            tmp = BinaryTree<int>(array, tree.node_count());
            cout << endl;

            ostringstream ostring;
            ostring << "Complete  tree with postorder traversal. " << endl;
            tmp.display(pdf, ostring.str());
        } 

// Program ends if user press 6. 

        else if (choice == 6) {
            cout << "Thanks for using our program!" << endl;
            break;
        } 

// This is the default case if use enters something like 100 when its asking 1-6. 

        else {
            cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
        }
    }

// Finish the pdf file.



    pdf->finish();
    delete pdf;

    return 0;
}
