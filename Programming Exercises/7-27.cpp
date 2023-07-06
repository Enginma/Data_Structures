//a
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right, int depth )
{
  if( depth == 0 )
    heapsort( vector<Comparable> & a );
  else if( left + 10 <= right )
    {
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

        quicksort( a, left, i - 1, --depth );     
        quicksort( a, i + 1, right, --depth );    
    }
    else  
        insertionSort( a, left, right );
}

//6.26
/*
                                      2
                                     / \
                                    4   11
                                   / \  /\
                                  5  9 12 17
                                 /\  /\   /
                                6 8 18 10 18
                               / /  /
                             11 15 31
                             /
                            21
*/
//d
template <typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right, int depth )
{
  if( depth == 0 )
    heapsort( vector<Comparable> & a );
  else if( left + 10 <= right )
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

    quicksort( a ,left, i - 1, --depth );
    
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
        --depth;
      }
}

//e
/*
* It would no longer be needed because when it reaches depth == 0 heapsort will sort it 
* faster.
*/