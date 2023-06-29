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