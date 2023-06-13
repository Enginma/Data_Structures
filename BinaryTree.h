#ifndef __BinaryTree_H
#define __BinaryTree_H

#include <iostream>
#include <sstream>
#include <queue>
#include "PDF.h" // for the PDF display

using namespace std;

/* A lightweight structure implementing a general binary tree node */


// "This" keyword 

template <class T>
struct BTNode {
  T       elem;  // element contained in the node
  BTNode *left;  // pointer to the left child (can be NULL)
  BTNode *right; // pointer to the right child (can be NULL)

  // Constructors
  BTNode(){ 

    left = right = NULL; 

  }

  BTNode( T elem, BTNode* left = NULL, BTNode* right = NULL ) {
    this->elem = elem;
    this->left = left;
    this->right = right;
  }
  BTNode( const BTNode& src ) {
    this->elem = src.elem;
    this->left = src.left;
    this->right = src.right;
  }
  
  // Simple tests
  bool is_leaf() const { return (left == NULL && right == NULL); }
};


/**************************************************************************** 
 * 
 * CLASS:  BinaryTree
 * 
 ****************************************************************************/

/* A 'BinaryTree' class implements a basic binary tree.  It serves
 * as a superclass for more specific types of binary trees, such as
 * a binary search tree.
 */

template <class T>
class BinaryTree {
 public:

  /* Construction */

// Initialize the tree as empty. 

  BinaryTree() { root = NULL; }  

//  Constructs the tree with all the elements in usual order so it can be complete. 

  BinaryTree( T *elements, int n_elements );  


  BinaryTree( const BinaryTree& src );
  ~BinaryTree() { empty_this(); }

  /* Access and Tests */
  bool is_empty() const     { return is_empty(root); }
  int height() const         { return height(root); }
  int node_count() const     { return node_count(root); }
  int leaf_count() const     { return leaf_count(root); }

  /* Mutators, and other Initialization */
  bool empty_this() { empty(root); root = NULL; return true; }
  void init_complete( T *elements, int n_elements ); // 1
  int to_flat_array( T* elements, int max ) const; // 1
  
  /* Traversal */
  void preorder( void (*f)(const T&) )  const { return preorder(f, root); }  // 1
  void inorder( void (*f)(const T&) )   const { return inorder(f, root); }
  void postorder( void (*f)(const T&) ) const { return postorder(f, root); }
               
  /* Operators */
  bool operator==( const BinaryTree& src ) const;
  bool operator!=( const BinaryTree& src ) const;
  BinaryTree& operator=(const BinaryTree& src);

  /* Input/Output */
  template<class S>
  friend ostream& operator<<( ostream& out, const BinaryTree<S>& src );

  /* Display */ 
  void display( PDF* pdf, const string& annotation = "" ) const;  // 1

// Functions I added to help code function
  void insert_node(const T& element);
  void delete_last_node (struct BTNode<T>* root, struct BTNode<T>* deleting_node);
  BTNode<T>* delete_node(struct BTNode<T>* root, int key);
  BTNode<T>* get_root() const;
  bool compare(BTNode<T>* node1, BTNode<T>* node2) const;

 protected:
  BTNode<T> *root;  // Root node (NULL if the tree is empty)

  /* "Helper" functions for the basic operations */
  BTNode<T> *clone( BTNode<T> *node );
  
  int height( BTNode<T>* node ) const;
  int balance_factor( BTNode<T>* node ) const;
  int node_count( BTNode<T>* node ) const; // 1
  int leaf_count( BTNode<T>* node ) const;
  bool is_empty( BTNode<T> *node ) const; 

  void preorder( void (*f)(const T&), BTNode<T> *node ) const;
  void inorder( void (*f)(const T&), BTNode<T> *node ) const;
  void postorder( void (*f)(const T&), BTNode<T> *node ) const;

  void empty( BTNode<T>* node );

  BTNode<T>* init_complete( T *elements, int n_elements, int index ); // 1
  
  int to_flat_array( T *elements, int max, BTNode<T> *node, int index, // 1
                     int& max_index ) const;
  void display( PDF *pdf, BTNode<T>* node, int leaf_dist, double x, double y, double scale ) const; // 1

  template<class S>
  friend ostream& operator<<( ostream& out, const BTNode<S>& src );



// Insert and delete function declarations. 




}; 

#include "BinaryTree.cpp"

#endif
