// Xianqi Cao U83561269 -- Code
// Matthew Keen U44822882 -- Report


#include <iostream>
#include <string>
#include <chrono>
#include <stack>
using namespace std;



// Create node linked list, the node initiator takes a character as val and creates the node with the given value. 

class Node {
public:
    char value;
    Node* next;

    Node(char val) {
        value = val;
        next = nullptr;
    }
};



// The stack and all of its functions
class Stack {
public:
    Node* head;
    Stack();
    void push(char val);
    void pop();
    void no_op();
    bool is_empty();

};


// Making the head node empty to begin the linked list. 

Stack::Stack(){
    head = nullptr;
}


// Adding and creating the element to the beginning of the stack. 
void Stack::push(char val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

// removes an element by making a tmp variable that copies the address of element to be deleted and making the deleted element the next 
// element. 
void Stack::pop(){
    if (head == nullptr){
        cout << "Nothing to remove" << endl;
        return; 
    }

    Node* delete_job = head;
    head = head->next;
    delete delete_job;
}


// This shows the stack is empty which is the no-op function since it is not popping or adding
void Stack::no_op() {
        cout << "Press 1 when have a string in mind to enter" << endl;
        return;
}




// This function is useful for checking if the stack is empty or not and it returns a boolean result. 
// It will be used in the next boolean function. 
bool Stack::is_empty() {
    return (head == nullptr);
}



// This boolean function takes the input string as "a"
// Since this is outside of the Stack class, we create a class variable called storing_stack to gain access to push and pop 
// into the stack. 
bool find_parenthesis(string a) {
    Stack storing_stack;

// In the for loop, we create a char variable called "c" and it will goes through every element in string a. 
// The first if statement will push the four different kinds of parenthesis to the stack.
// The else if statement happenes when it encounters the counter part of the left parenthesis and if there is nothing in the stack, meaning
// a right parenthesis was inputted before its left counter part, it will just return false. 

// Otherwise we create a new char variable called top that copies the first element of the stack and use its value, which is one of the 
// four kinds of left parenthesis. When we encounter a right parenthesis and the stack is not empty, we check if the top of the stack
// is the correct left parenthesis counter part and if it is we pop the left parenthesis in the stack. Otherwise we return false if 
// it is being matched with the wrong counter part. 
    for (char c : a) {
        if (c == '(' || c == '{' || c == '[' || c == '<') {
            storing_stack.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']' || c == '>') {
            if (storing_stack.is_empty()) {
                return false;
            }

            char top = storing_stack.head->value;
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[') || (c == '>' && top == '<')) {
                storing_stack.pop();
            } 

            else {
                return false;
            }
        }
    }

// This statement will return True if all previous test is passed and all parenthesis match, which means the stack will be empty. 
    return storing_stack.is_empty();
}



// C++ Built in Stack functions
bool find_parenthesis_builtin(string a) {
    stack<char> storing_stack;

    for (char c : a) {
        if (c == '(' || c == '{' || c == '[' || c == '<') {
            storing_stack.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']' || c == '>') {
            if (storing_stack.empty()) {
                return false;
            }

            char top = storing_stack.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[') || (c == '>' && top == '<')) {
                storing_stack.pop();
            } 
            else {
                return false;
            }
        }
    }

    return storing_stack.empty();
}


/*
Main function contains one stack-class variable called user_stack to access the no-op Stack function above.
A boolean variable is_matching to access the result of find_parenthesis function above. 
And a char variable choice to help the user to navigate in the menu of the program. 
*/ 

int main() {
    Stack user_stack;

    string code;
    bool is_matching;
    int choice; 
    int count;

// The first set of chrono instructions display the speed of the program I made, the second set displays the speed of built in stack. 

    string test1 = "(A+b)*(c/d)";
    string test2 = "A(B+C)*2+[A]^2";
    cout << "Example tests: " << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Test 1 ((A+b)*(c/d)): ";
    {
        auto start = chrono::high_resolution_clock::now();
        is_matching = find_parenthesis(test1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
        cout << boolalpha << is_matching << endl;
        cout << "Execution time: " << duration.count() << " seconds." << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Test 1 ((A+b)*(c/d)): ";
    {
        auto start = chrono::high_resolution_clock::now();
        bool is_matching = find_parenthesis_builtin(test1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
        cout << boolalpha << is_matching << endl;
        cout << "Execution time (builtin stack): " << duration.count() << " seconds." << endl;
    }
    

    cout << "------------------------------------------------------------" << endl;
    cout << "Test 2 (A(B+C)*2+[A]^2): ";
    {
        auto start = chrono::high_resolution_clock::now();
        is_matching = find_parenthesis(test2);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
        cout << boolalpha << is_matching << endl;
        cout << "Execution time: " << duration.count() << " seconds." << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    cout << "Test 2 (A(B+C)*2+[A]^2): ";
    {
        auto start = chrono::high_resolution_clock::now();
        bool is_matching = find_parenthesis_builtin(test2);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
        cout << boolalpha << is_matching << endl;
        cout << "Execution time (builtin stack): " << duration.count() << " seconds." << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "Menu:" << endl;
    cout << "1. Check Parentheses" << endl;
    cout << "2. No operation" << endl;
    cout << "3. Quit" << endl;



// Program will run until user enters 3
// If 1 is entered, user will be prompted to enter a string it will be send to the find_parenthesis function and store its boolean
// result in is_matching. 
// If 2 is entered nothing will happen as the no-op function. 


    while (choice != 3) {
        cout << "Enter your choice (1-3): ";
        cin >> choice;



// The fail function is here to make sure that the user enters an integer and not anything else to prevent infinite loop.
// The program will restart if user enters anything but an integer. 

        if (cin.fail()) {
            cout << "Invalid input. Please enter 1-3 as choice." << endl;
            break;
        }



// In case 1, the string entered will be completely passed to the find_parenthesis function. 
// The ignore function will clear the input buffer and wait for the user to input the string to be tested. 
// Without the igore function the previous choice input will be used instead. 
// The if statement simply returns true if is_matching is true and false if it is not.

        switch (choice) {
            case 1:
                cout << "Enter the string of characters: ";
                cin.ignore();
                getline(cin, code);

                {
                    auto start = chrono::high_resolution_clock::now();
                    is_matching = find_parenthesis(code);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
                    cout << "Execution time: " << duration.count() << " seconds." << endl;
                }


                {
                    auto start = chrono::high_resolution_clock::now();
                    bool is_matching = find_parenthesis_builtin(code);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
                    cout << "Execution time (builtin stack): " << duration.count() << " seconds." << endl;
                }

                is_matching = find_parenthesis(code);
                if (is_matching) {
                    cout << "true" << endl;
                } 
                else {
                    cout << "false" << endl;
                }
                count++;
                break;

// The no-op function that just does nothing useful. 

            case 2:
                {
                    auto start = chrono::high_resolution_clock::now();
                    user_stack.no_op();
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start);
                    cout << "Execution time: " << duration.count() << " seconds." << endl;
                }
                break;

// End the program. 

            case 3:
                cout << "Thanks for using our program! You have done " << count << " case(s)." << endl;
                break;

// The default message when user enters an integer that is not 1-3.

            default:
                cout << "Invalid choice. Please enter 1-3" << endl;
                break;
        }
    }

    return 0;
}