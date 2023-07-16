template <typename Comparable>
bool sumArray( vector<Comparable> & a, int k )
{
  int i, r, sum, sumctr = 0;
  vector<Comparable> tmpArray( a.size( ) * a.size( ) );
  for( i = 0; i < a.size( ); ++i )
    {
      for( r = i; r < a.size( ); ++r )
        {
          sum = a[ i ] + a[ r ];
          tmpArray[ ++sumctr ] = sum;
        }
    }
     
  //standard quicksort definition elsewhere
  template <typename Comparable>
  void quicksort( vector<Comparable> & tmpArray )
  {
      quicksort( tmpArray, 0, a.size( ) - 1 );
  }

    //adds two sums together to equal 4 numbers added
   if( tmpArray[ 0 ] != k )
    {  
      for( i = 0; tmpArray[ i ] < k && i < tmpArray.size( ); ++i )
        {
          for( r = i; tmpArray[ r ] < k && r < tmpArray.size( ); ++r )
            {
              sum = tmpArray[ i ] + tmpArray[ r ];
              if( sum == k )
                return true;
            }
        }
    }
}