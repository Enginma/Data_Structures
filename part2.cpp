#include <iostream>
#include <unordered_map>
#include "part2_disjointSets.hpp"

using namespace std;



int main(){
    
    // Main menu prompts. 
    string choice;

    // Main loop for input and output. 
    while(true){
        cout << "Menu:" << endl;
        cout << "1: Make a new integer disjoint set" << endl;
        cout << "2: Make a new character disjoint set" << endl;
        cout << "3: Quit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice[0])
        {
        case '1':
            makeIntSet();
            break;
        case '2':
            makeCharSet();
            break;
        case '3':
            cout << "Thanks for using our program!" << endl;
            return 0;
        default:   
            cout << "Invalid input, please try again." << endl;
            break;
        }        
    }
    return 0;
}