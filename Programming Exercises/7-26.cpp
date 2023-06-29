// part a
template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right )
{
  if( left + 10 <= right )
  {
    insertionSort( a, left, right );
    return;
  }
  else
    const Comparable & pivot = median3( a, left, right );

    int i = left, j = right - 1;
    for( ; ; )
      {
        while( a[ ++i ] < pivot ) { }
        while( pivot < a[ --j ] ) { }
        if( i < j )
          std::swap( a[ i ], a[ j ] );
        else
          break;
      }
    std::swap( a[ i ], a[ right - 1 ] );

  if( (left + i) < ( right - (i + 1) ) )
  {
    quicksort( a ,left, i - 1 );
    quicksort( a , i + 1, right); 
  }
  else
    quicksort( a , i + 1, right);
    quicksort( a ,left, i - 1 );
}


//part b
template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right )
{
  if( left + 10 <= right )
  {
    insertionSort( a, left, right );
    return;
  }
  else
    const Comparable & pivot = median3( a, left, right );

    int i = left, j = right - 1;
    for( ; ; )
      {
        while( a[ ++i ] < pivot ) { }
        while( pivot < a[ --j ] ) { }
        if( i < j )
          std::swap( a[ i ], a[ j ] );
        else
          break;
      }
    std::swap( a[ i ], a[ right - 1 ] );

  if( (left + i) < ( right - (i + 1) ) )
  {
    quicksort( a ,left, i - 1 );
    while( left < right )
      {
        int left = i + 1, j = right - 1;
        for( ; ; )
          {
            while( a[ ++left ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( left < j )
              std::swap( a[ left ], a[ j ] );
            else
              break;
          }
        std::swap( a[ left ], a[ right - 1 ] );
      }
  }
  else
    quicksort( a , i + 1, right);
    while( left < right )
      {
        int i = left, right = j - 1;
        for( ; ; )
          {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --right ] ) { }
            if( i < right )
              std::swap( a[ i ], a[ right ] );
            else
              break;
          }
        std::swap( a[ i ], a[ right - 1 ] );
      }
}

//part c 6.22
/*
*  Since time is determined by the length of the right paths the best leftist heap input
*    would be just a single root like 3. Or if it was a maxheap, for example, the input
*    would be each element being smaller than the last so only left paths are taken.
*    i.e. 3 2 1
*/