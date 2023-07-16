#include <iostream>
#include <vector>
#include "part2_disjointSets.hpp"

using namespace std;

int main()
{
  vector<int> a;
  int choice;
  int element;
  int set1, set2;

  //main menu prompts
  cout << "Menu:" << endl;
  cout << "1: Make a new set" << endl;
  cout << "2: Find an element" << endl;
  cout << "3: Union two sets" << endl;
  cout << "4: Quit" << endl;

  //main loop for input and output
  while( choice != 4 )
    {
      cout << "Enter your choice" << endl;
      cin >> choice;

      if (cin.fail()) 
      {
            cout << "Invalid input. Please enter 1-4 as choice." << endl;
            break;
      }

      switch (choice)
        {
          case 1: 
            cout << "Enter new element greater than 0" << endl;
            cin >> element;
            if( element > 0)
            {
              makeset( element, a );
              cout << "Operation complete" << endl;
              break;
            }
            else
            {
              cout << "Please enter an element greater than 0" << endl;
              break;
            }
          case 2:
            cout << "Enter element to be found" << endl;
            cin >> element;
            if( element < 0 || element >= a.size() || find( element, a ) == -2 )
            {
              cout << "Entered element is not found" << endl;
              break;
            }
            else
            {
              cout << "Your element is in set: " << find( element, a ) << endl;
              break;
            }
          case 3:
            cout << "Enter two sets to be unioned. Please press enter after each set" << endl;
            cin >> set1;
            cin >> set2;            
            if( set1 < 0 || set1 >= a.size() || a[set1] == 0 || set2 < 0 || set2 >= a.size() || a[set2] == 0)
            {
              cout << "Entered set is not found" << endl;
              break;
            }
            else
            {
              unionSet( set1, set2, a );
              cout << "Operation complete" << endl;
              break;
            }
          case 4:
            cout << "Thanks for using our program!" << endl;
            break;
          default:
            cout << "Invalid choice. Please press 1-4" << endl;
            break;
        };
    };
  
  return 0;  
};
