#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// The Disjointset class. We have a node struct for binary tree implementation. 
// We use unordered map library to make hash table implementation.

template <typename T>
class DisjointSet {
private:
    struct Node {
        T element;
        int rank;
        Node* parent;
    };

    unordered_map<T, Node*> nodes;


// Function to find the root node for other functions. 
    Node* findRoot(Node* node) {
        while (node->parent != node) {
            node = node->parent;
        }
        return node;
    }

public:
    DisjointSet() {}

// The make set function in Dijkstra's algorithm. 

    void makeSet(T element) {
        if (nodes.find(element) == nodes.end()) {
            Node* newNode = new Node{element, 0, nullptr};
            newNode->parent = newNode;
            nodes[element] = newNode;
        }
    }

// The find set function in Dijkstra's algorithm. 

    T find(T element) {
        if (nodes.find(element) == nodes.end()) {
            cerr << "Element not found." << endl;
            return T{};
        }

        Node* node = nodes[element];
        Node* root = findRoot(node);

        while (node != root) {
            Node* next = node->parent;
            node->parent = root;
            node = next;
        }

        return root->element;
    }

// The union set function in Dijkstra's algorithm. 

    void unionSets(T element1, T element2) {
        Node* node1 = nodes[element1];
        Node* node2 = nodes[element2];

        if (!node1 || !node2) {
            cerr << "No two elements present." << endl;
            return;
        }

        Node* root1 = findRoot(node1);
        Node* root2 = findRoot(node2);

        if (root1 == root2) {
            return; 
        }

        // Union by rank to keep the tree balanced.
        if (root1->rank < root2->rank) {
            root1->parent = root2;
        } else if (root1->rank > root2->rank) {
            root2->parent = root1;
        } else {
            root1->parent = root2;
            root2->rank++;
        }
    }

  // Deconstructor. 
    ~DisjointSet() {
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            delete it->second;
        }
    }
};


// Making an integer set. 

void makeIntSet(){
    DisjointSet<int> number;
    cout << "---------------------------------------------" << endl;
    cout << "Empty integer disjoint set created!" << endl;
    cout << "Please choose one of the following options:" << endl;
    cout << "1. make a set with given element." << endl;
    cout << "2. Union two sets." << endl;
    cout << "3. Find an element." << endl;
    cout << "4. Quit building." << endl;
    string s;
    int input, set1, set2;
    while(true){
        cout << "Please enter your choice: ";
        cin >> s;
        switch (s[0])
        {
        case '1':
            cout << "Please enter an integer to create a set: ";
            cin >> input; 
            number.makeSet(input);
            break;
        
        case '2':
            cout << "Please enter set 1: ";
            cin >> set2;
            cout << "Please enter set 2: ";
            cin >> set1;
            number.unionSets(set1, set2);
            break;
        
        case '3':
            cout << "Please enter an integer to perform find: ";
            cin >> input;
            cout << "The representation of " << input << " is: " << number.find(input) << "." << endl;
            break;

        case '4':
            cout << endl;
            return;
        default:
            cout << "Invalid input, please try again." << endl;
            break;
        }
    }
}


// Make character set. This is for taking care of character inputs. 

void makeCharSet(){
    DisjointSet<char> character;
    cout << "---------------------------------------------" << endl;
    cout<< "Empty character disjoint set created!" << endl;
    cout << "Please choose one of the following options:" << endl;
    cout << "1. Make a set with given element." << endl;
    cout << "2. Union two sets." << endl;
    cout << "3. Find an element in the sets." << endl;
    cout << "4. Quit building." << endl;
    string s;
    char input, set1, set2;
    while(true){
        cout << "Please enter your choice: ";
        cin >> s;
        switch (s[0])
        {
        case '1':
            cout << "Please enter a character to create a set: ";
            cin >> input; 
            character.makeSet(input);
            break;
        
        case '2':
            cout << "Please enter set 1: ";
            cin >> set2;
            cout << "Please enter set 2: ";
            cin >> set1;
            character.unionSets(set1, set2);
            break;
        
        case '3':
            cout << "Please enter an integer to perform find: ";
            cin >> input;
            cout << "The representation of " << input << ": " << character.find(input) << "." << endl;
            break;

        case '4':
            cout << endl;
            return;
        default:
            cout << "Invalid input, please try again." << endl;
            break;
        }
    }
}

#endif