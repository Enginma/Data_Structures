//modified in text quicksort to use new partitioning algo
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = median3( a, left, right );

        int head = left, tail = right - 1;
        int headctr = 0, tailctr = 0;
        for( ; ; )
          {
            while( a[ ++i ] == pivot )
              {
                ++head;
                ++headctr;
                continue;
              }
            while( a[ --j ] == pivot )
              {
                --tail;
                ++tailctr;
                continue;
              }
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
              if( i < j )
                std::swap( a[ i ], a[ j ] );
              else
                break;
          }
        
        std::swap( a[ i ], a[ right - 1 ] );
        --i;
        while( headctr != 0 )
          {
            std::swap( a[ i ], a[ head ] );
            --head;
            --headctr;
            --i;
          }
        while( tailctr != 0 )
          {
            std::swap( a[ j ], a[ tail ] );
            ++tail;
            --tailctr;
            ++j;
          }

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right ); 
    }
    else  
        insertionSort( a, left, right );
}