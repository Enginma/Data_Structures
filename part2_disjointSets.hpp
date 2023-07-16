#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

using namespace std;

#include <vector>

//internal method for checking the heights of sets
int height( int set, vector<int> & a )
{
  int max = 0, tmpMax = 0, tmp;
  
  for( int i = 0; i < a.size(); ++i )
    {
      if( a[i] == set && a[i] == i )
        continue;
      else if( a[i] == set )
      {
        tmpMax = 0;
        tmpMax++;
        for( int j = 0; j < a.size(); ++j )
          {
            if( a[j] == i )
            {
              tmp = j;
              j = 0;
              tmpMax++;
            }
          }
      }
      
      if( tmpMax > max)
        max = tmpMax;
    }
  return max;
};

//finds an element and returns what set it is in
int find( int element, vector<int> & a )
{
  int i = a.at( element );
  if( i == a[i] )
    return i;
  else
  {
    a[i] = find( a[i], a );
      return a[i];
  }
};

//merges two sets based on height to keep the tree as short as possible
void unionSet( int set1, int set2, vector<int> & a )
{
  if( height( set1, a ) >= height( set2, a ) )
  {
    a[set2] = set1;
    return;
  }
  else
    a[set1] = set2;
};

//makes a new set hashed to give the int input its equivalent index number
int makeset( int element, vector<int> & a )
{
  int i = element;
  if( element >= a.size() )
  {
    a.resize( element + 1 );
    return a[i] = i;
  }
  else
    return a[i] = i;
};

#endif
