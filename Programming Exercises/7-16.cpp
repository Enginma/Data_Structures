//uses insertion sort to sort two halves of array then merge sort to sort them

template <typename Comparable>
void mergeSort( vector<Comparable> & a )
{
  int left = 0;
  int right = a.size( ) - 1
  int center = ( left + right ) / 2;
  int leftctr = 0;
  int rightctr = 0;
  
  vector<Comparable> tmpArray( a.size( ) );
  vector<Comparable> tmpArrayLeft( a.size( ) / 2);
  vector<Comparable> tmpArrayRight( a.size( ) / 2);

  for( i = 0; i < center; ++i )
    tmpArrayLeft[ leftctr++ ] = std::move( a[ i ] );
  for( i = center + 1; i < right; ++i )
    tmpArrayRight[ rightctr++] = std::move( a[ i ] ); 

  insertionSort( tmpArrayleft );
  insertionSort( tmpArrayRight );

  int leftctr = 0;
  int rightctr = 0;

 for( i = 0; i < a.size( ); ++i )
   {
     if( i <= center)
       a[ i ] = std::move( tmpArrayLeft[ leftctr++ ] );
     else
       a[ i ] = std::move( tmpArrayRight[ rightctr++ ] );
   }
    
  merge( a, tmpArray, left, center + 1, right );
}

template <typename Comparable>
void insertionSort( vector<Comparable> & a )
{
  for( int p = 1; p < a.size( ); ++p )
    {
      Comparable tmp = std::move( a[ p ] );

      int j;
      for( j = p; j > 0 && tmp < a[ j - 1 ]; --j )
        a[ j ] = std::move( a[ j - 1 ] );
      a[ j ] = std::move( tmp );
    }
}


template <typename Comparable>
void merge( vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos,
            int rightEnd )
{
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int numElements = rightEnd - leftPos + 1;

  while( leftPos <= leftEnd && rightPos <= rightEnd )
    if( a[ leftPos ] <= a[ rightPos ] )
      tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
    else
      tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

  while( leftPos <= leftEnd )
    tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );

  while( rightPos <= rightEnd )
    tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

  for( int i = 0; i < numElements; ++i, --rightEnd)
    a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
}
