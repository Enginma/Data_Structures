// Xianqi Cao U83561269 -- Code
// Matthew Keen U44822882 -- Report

using namespace std;


/*
 * Input/Output
 * ------------
 *
 * Unlike certain kinds of specific binary trees, there is no natural
 * method of inserting elements incrementally into a general binary
 * tree.  Most often they are built up from subtrees.  That makes it
 * difficult to define a constructor that constructs a binary tree
 * all at once from a collection of elements, e.g., an array.  So
 * array-based construction works assuming the tree is a complete
 * binary tree.
 *
 * Recall that a *perfect* (or full) binary tree has all the levels
 * completely filled.  A *complete* binary tree has all the levels
 * full, except that a segment of leaves at the right may be missing.
 * There is exactly one complete binary tree structure having n elements.
 * The sequence of complete binary trees looks like this:
 *
 *          1
 *      
 *
 *          1       1     
 *         /       / \   
 *        2       2   3  
 *                           
 *			     
 *          1                 1                 1                 1        
 *        /   \             /   \    	      /   \             /   \    
 *      2       3         2       3  	    2       3         2       3  
 *     /                 / \         	   / \     /   	     / \     / \ 
 *    4                 4   5        	  4   5   6    	    4   5   6   7
 *
 *
 * The nodes of a complete binary tree thus have a natural linear order;
 * in fact, a complete binary tree is suited for representation in a
 * flat array:
 *
 *            1
 *          /   \                +---+---+---+---+---+---+---+---+- -
 *        2       3        -->   | X | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
 *       / \     / \             +---+---+---+---+---+---+---+---+- -
 *      4   5   6   7              0   1   2   3   4   5   6   7   
 *
 * For computational convenience, the root element is stored at index 1
 * in the array (the cell at index 0 is unused).  In this arrangement
 * the index of the children and parents of the node at index 'i'
 * have clean formulas:
 *
 *   parent of node i:       i/2  (rounding down, as usual)
 *   left child of node i:   2*i
 *   right child of node i:  2*i + 1
 *
 * Of course, in the present implementation the tree is stored as
 * linked nodes rather than a flat array.  However, the flat array
 * interpretation is useful for input and output: a tree is constructed
 * from an array assuming it is a complete tree with elements given
 * by the array in the natural complete-tree ordering.
 *
 * NOTE:  For consistency, this code assumes that the element at index 0
 *        is unused, so if there are 'n' elements, the array has 'n + 1'
 *        cells.
 */



/****************************************************************************/
/***                    Implementation of BinaryTree			  ***/
/****************************************************************************/


/****************/
/* Construction */
/****************/


// Constructor for empty tree. 

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree& src) {
  root = clone(src.root);
}



// This Binary tree is made with n elements. T *elements is a point to the address of elements of any type. 
// It calls the init_complete function right below. 

template<class T>
BinaryTree<T>::BinaryTree( T *elements, int n_elements )
  // Constructs this tree to have elements 'elements[1]', 'elements[2]' ...
  // as a complete binary tree (see above); 'element[0]' is ignored,
  // so the total number of cells if 'elements' is 'n_elements + 1'
{
  root = NULL;
  init_complete(elements, n_elements);
}




// This sets the root of the entire tree and connects the each one with the init_complete function below. 

template<class T>
void BinaryTree<T>::init_complete( T *elements, int n_elements )
  // Initializes this tree, regarding it as a complete binary tree
  // having elements 'elements[1]', 'elements[2]', ... (see above)
{
  // call the helper function starting at the root index (1)
  root = init_complete(elements, n_elements, 1);
}




// This is the function that connects all the nodes. This function make sure the tree is a complete tree. 

template<class T>
BTNode<T>* BinaryTree<T>::init_complete( T *elements, int n_elements, int index )
  // Initializes this tree, regarding it as a complete binary tree,
  // starting at the array node at 'index'
{
  // check for the end of the array 
  if (index > n_elements)
    return NULL;

  // create a new node, with left and right children assigned by
  // the recursive call
  return new BTNode<T>(elements[index], init_complete(elements, n_elements, 2*index), init_complete(elements, n_elements, 2*index + 1));
}


/********************/
/* Access and Tests */
/********************/



template<class T>
int BinaryTree<T>::node_count( BTNode<T> *node ) const
{
  if (node == NULL)
    return 0;
  return 1 + node_count(node->left) + node_count(node->right);
}

/*************/
/* Traversal */
/*************/


// The preorder function shows preorder traversal.

template<class T>
void BinaryTree<T>::preorder( void (*f)(const T&, T*, T&), BTNode<T> *node, T arr[], T &index )
{
  if (!node)
    return;
  f(node->elem, arr, index);
  preorder(f, node->left, arr, index);
  preorder(f, node->right, arr, index);
}






/************************/
/* Conversion to Arrays */
/************************/

template<class T>
int BinaryTree<T>::to_flat_array( T *elements, int max ) const
  // PRE: This is a complete binary tree
  // Copies the elements contained in the nodes of this tree to
  // 'elements' in complete-tree order (see above).  At most
  // 'max' elements are actually copied; the return value is
  // the total number of nodes.
  // The elements are copied starting at 'elements[1]' (see above)
  // so 'elements' must have at least 'max + 1' cells available
{
  // call the helper
  int max_index = 1;
  return to_flat_array(elements, max, root, 1, max_index);
}

template<class T>
int BinaryTree<T>::to_flat_array( T *elements, int max, BTNode<T> *node, int index, int& max_index ) const
  // PRE: this is a complete binary tree
  // Helper function for the 'to_flat_array' function above
  // 'node' is the current node, 'index' is the index of the node
  // in the flat array (complete tree array) representation, and
  // 'max_index' is the largest index yet encountered; it is updated
  // accordingly by this call
  
{
  // skip a NULL node
  if (node == NULL)
    return 0;

  // update the maximum index
  if (index > max_index)
    max_index = index;

  // as long as we're not past the maximum number of cells,
  // (and the node is not NULL) the code can be copied
  if (index < max)
    elements[index] = node->elem;

  // make a recursive call, even if we're already past the max
  // (in order to keep the 'max_index' updated)
  to_flat_array(elements, max, node->left, 2*index, max_index);
  to_flat_array(elements, max, node->right, 2*index + 1, max_index);

  return max_index;
}


/**************************/
/* Input/Output Operators */
/**************************/

template<class T>
ostream& operator<<( ostream& out, const BinaryTree<T>& src )
  // Writes the elements contained in the nodes of this tree,
  // by way of an inorder traversal
{
  // make a call to the recursive helper function
  out << src.root;
  return out;
}

template<class T>
ostream& operator<<( ostream& out, const BTNode<T>* node )
  // Helper for the 'operator<<' above
{
  // don't write a NULL node
  if (!node)
    return out;
  
  // write, using an inorder traversal  
  out << node->left;  // (recursive)
  out << node->elem;  // (nonrecursive)
  out << " ";
  out << node->right; // (recursive)

  return out;
}

/***********/
/* Display */
/***********/

static const double font_scale = 20;
static const double level_sep = 90;
static const double node_sep = 30;
static const double node_box_margin = 6;
static const double node_box_r = 6;

template<class T>
void BinaryTree<T>::display( PDF *pdf, const string& annotation ) const
{
  double scale = 1;

  // the overall scale is based on the height of the tree
  int h = height();
  if (h >= 4) 
    scale = 16.0/double(1<<h);

  // start a new page
  pdf->new_page(annotation.c_str());
  
  // regardless of the scale, place the root node at the center
  // of the page, one inch below the top margin
  double x = pdf->get_width()/2;
  double y = pdf->get_height() - 72;

  // set the font to Helvetica, 12 point (times the scale)
  pdf->selectfont(Helvetica, font_scale*scale);
  // set the non-stroke color to light gray
  pdf->setcolor_nonstroke(PDFColor(0.75));
  pdf->setlinewidth(scale);

  // run the "helper"
  display(pdf, get_root(), h - 1, x, y, scale);
}

template<class T>
void BinaryTree<T>::display( PDF *pdf, BTNode<T> *node, int leaf_dist,
			     double x, double y, double scale ) const
{
  // don't draw a NULL node
  if (node == NULL)
    return;

  // if there is a left node, add a line to it and make a recursive call
  if (node->left) {
    double x_left = x - (1<<leaf_dist)*node_sep*scale/2;
    double y_left = y - level_sep*scale;
    pdf->moveto(x, y);
    pdf->lineto(x_left, y_left);
    pdf->stroke();
    display(pdf, node->left, leaf_dist - 1, x_left, y_left, scale);
  }

  // if there is a right node, add a line to it and make a recursive call
  if (node->right) {
    double x_right = x + (1<<leaf_dist)*node_sep*scale/2;
    double y_right = y - level_sep*scale;
    pdf->moveto(x, y);
    pdf->lineto(x_right, y_right);
    pdf->stroke();    
    display(pdf, node->right, leaf_dist - 1, x_right, y_right, scale);
  }

  // Now draw 'node' at (x, y)
  // This is done last so that the box covers the line
  // A text representation is obtained by converting the element to a
  // C-style stringusing an 'ostringstream' instance
  ostringstream str;
  str << node->elem;
  pdf->text_box(str.str().c_str(), x, y,
		scale*node_box_margin, scale*node_box_r,
		0, scale*font_scale);  
}





// This checks if the tree is empty. It takes in a node and if it is null it will return True. 

template<class T>
bool BinaryTree<T>::is_empty(BTNode<T>* node) const {
    return node == NULL;
}


// This counts the amount of leaf nodes by taking in a node and it first check if it has 0 or just the root node. 
// Then it goes all the way to the left until it returns 1 and then adds all the left one up and the traverse to the right and do the same. 
// This will return the total amount of nodes in the tree. 

template<class T>
int BinaryTree<T>::leaf_count(BTNode<T>* node) const {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    return leaf_count(node->left) + leaf_count(node->right);
}



// This function takes in a function pointer f and a node pointer. 

// It recursively goes through all the left tree nodes and then the right tree nodes. 

template<class T>
void BinaryTree<T>::postorder( void (*f)(const T&, T*, T&), BTNode<T> *node, T arr[], T & index ){
    if (node == NULL)
        return;
    postorder(f, node->left, arr, index);
    postorder(f, node->right, arr, index);

// Function f gets the value of the node. 
    f(node->elem, arr, index);
}




// == overload operator compares two trees to see if they are equal

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree& src) const {
  return compare(root, src.root);
}


// != overload operator compares two trees to see if they are not equal, use the current tree cmparing to src tree. 

template<class T>
bool BinaryTree<T>::operator!=(const BinaryTree& src) const {
  return !(*this == src);
}


// The boolean compare function. 

template<class T>
bool BinaryTree<T>::compare(BTNode<T>* node1, BTNode<T>* node2) const {
  if (node1 == nullptr && node2 == nullptr)
    return true;

  if (node1 != nullptr && node2 != nullptr) {
    return (node1->elem == node2->elem) && compare(node1->left, node2->left) && compare(node1->right, node2->right);
  }

  return false;
}





// This operator= function check if the tree elements are different and if they are the original root will be replaced to null 
// and root will be cloned by the current tree's root. 

template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& src)
{
  if (this != &src) {
    empty_this();  
    root = clone(src.root);  
  }

  return *this;  
}



// Gets the height of the tree
template <class T>
int BinaryTree<T>::height(BTNode<T>* node) const {
  if (node == nullptr) {
    return 0;
  }
  int left_height = height(node->left);
  int right_height = height(node->right);
  return 1 + max(left_height, right_height);
}


template <class T>
BTNode<T>* BinaryTree<T>::get_root() const {


    return root;
}



// This is created to match the header file's void empty function so the code compiles, it is not used in the main.cc or anywhere,
// but it is implemented to clear off everynode from a tree.  


template <class T>
void BinaryTree<T>::empty( BTNode<T>* node ){
  if (node == nullptr) {
    return;
  }
  empty(node->left);
  empty(node->right);
  delete node;
  node = nullptr;
}



// The clone function copies the whole tree to a new_node

template <typename T>
BTNode<T>* BinaryTree<T>::clone(BTNode<T>* node) {
    if (node == nullptr) {
        return nullptr;
    }

    BTNode<T>* new_node = new BTNode<T>(node->elem);
    new_node->left = clone(node->left);
    new_node->right = clone(node->right);

    return new_node;
}




// The in order function place the node in order from left to right and apply the element to the node. 

template <typename T>
void BinaryTree<T>::inorder( void (*f)(const T&, T*, T&), BTNode<T> *node, T arr[], T & index ){
    if (node == nullptr) {
        return;
    }

    inorder(f, node->left, arr, index);
    f(node->elem, arr, index);
    inorder(f, node->right, arr, index);
}





// Inserting node function


// This function first creates a new node with the given element.

template<class T>
void BinaryTree<T>::insert_node(const T& element) {
    BTNode<T>* new_node = new BTNode<T>(element);


// If the tree is empty meaning root is nullptr, the new node will be the root. 

    if (root == nullptr) {
        root = new_node;
        return;
    }


// We use a queue to insert the node to its correct position to maintain a complete tree. We create a queue using the 
// queue library in C++ and we first push the root node to the beginning. 

    queue<BTNode<T>*> queue;
    queue.push(root);


 // While the queue is not empty, we create a new node variable called current and we make it equal to the first element of the
 // queue, then we remove that element with the pop function.    

    while (!queue.empty()) {
        BTNode<T>* current = queue.front();
        queue.pop();

// First, we check the node if it has a left child and if it doesn't then the node will be inserted there. 

        if (current->left == nullptr) {
            current->left = new_node;
            return;
        }

// If it already have a left child then we push this node to the queue, this is useful when we want to insert more nodes in the future. 

        else {
            queue.push(current->left);
        }

// Then we check the right child to see if there is anything there, if there is not then we insert the new node there.  

        if (current->right == nullptr) {
            current->right = new_node;
            return;
        }

// Otherwise we push the right child to the stack for future uses. 
        else {
            queue.push(current->right);
        }
    }
}

// Since it is a while loop, the left child of the root will become the current and it will run until it finds a place where
// it can be inserted from left to right to make sure the tree is complete. 




// The delete node function that takes the root and the value that we want to delete called key as parameters. 
// We first check if there is nothing to delete, and if there is only one root node in the tree. 


template <class T>
BTNode<T>* BinaryTree<T>::delete_node(struct BTNode<T>* root, int key){
  if (root == nullptr)
    return nullptr;



  if (root->left == nullptr && root->right == nullptr){
    if (root->elem == key){
      return nullptr;
    }
    else {
      return root;
    }
  }

// We create a queue called nodes again and we push the root in there as well as two node variables for later computations. 

  queue<struct BTNode<T>*> nodes;
  nodes.push(root);
  struct BTNode<T>* tmp;
  struct BTNode<T>* target_node = nullptr;

// While the queue is not empty, we make tmp equal to the first queue element and we pop the element from the queue. 
// We then hunt for the value that we want to delete and once we find it target_node will be equal to tmp making it the node we want 
// to delete. 

// Tmp will be the last variable in our tree at the end of the while loop. 

  while (!nodes.empty()) {
    tmp = nodes.front();
    nodes.pop();


    if (tmp->elem == key){
      target_node = tmp;
    }

    if (tmp->left){
      nodes.push(tmp->left);

    }

    if (tmp->right){
      nodes.push(tmp->right);

    }
  }


// As long as we found the target node, in other words it is not nullptr, we make a new int variable called last_node to inherit 
// the tmp's value. We then just straight up delete the last node with the delete_last_node function declared below, then we replace
// the value of the node we wanted to delete with the last node. 
// We basically swapped the last node with the node we want to be deleted, and then deleted it. 


    if (target_node == tmp) {
      delete_last_node(root, target_node);
      delete_last_node(root, tmp);
      return root;
    }



    if (target_node != nullptr) {
      int last_node = tmp->elem;
      delete_last_node(root, tmp);
      target_node->elem = last_node;
    }



  return root;

}


// Deleting function that delete the last node of the tree takes the root as one parameter 
// and the value that we want to delete as another. 

// This function will run until it finds the node it want to be deleted and then it will return and end. 

template <class T>
void BinaryTree<T>::delete_last_node(BTNode<T>* root, BTNode<T>* deleting_node) {


// We first create a queue called nodes and we push the root to the queue. We also make a tmp variable for later computations. 

    queue<BTNode<T>*> nodes;
    nodes.push(root);
    BTNode<T>* tmp;


// While the queue is not empty, we set tmp to the root node and pop the node from our queue. We first check if the variable is
// the note we want to delete, if it is we simply delete it. 

    while (!nodes.empty()) {
        tmp = nodes.front();
        nodes.pop();



        if (tmp == deleting_node) {
            delete deleting_node;  

            return;
        }

// Then we check from the right first to see if it is the value we want, if it is not we push it to the queue. 

        if (tmp->right) {
            if (tmp->right == deleting_node) {
                tmp->right = nullptr;
                delete deleting_node;  

                return;
            } 

            else {
                nodes.push(tmp->right);

            }
        }

// Checking the leftside the same way we did for right, if it is not wwse push it into the queue. 
        if (tmp->left) {
            if (tmp->left == deleting_node) {
                tmp->left = nullptr;
                delete deleting_node;
  
                return;
            } 

            else {
                nodes.push(tmp->left);

            }
        }
    }
}



