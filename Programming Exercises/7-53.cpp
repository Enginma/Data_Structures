//a
template <typename Comparable>
bool sumArray( vector<Comparable> & a, int k )
{
  int i, j, sum;
  for( i = 0; i < a.size( ); ++i )
    {
      for( j = i j < a.size( ); ++j )
        {
          sum = a[ i ] + a[ j ];
          if( sum == k )
            cout << a[ i ] " " a[ j ]"\n"
            return true;
        }
    }
}

//b
template <typename Comparable>
bool sumArray( vector<Comparable> & a, int k )
{
  //standard quicksort definition elsewhere
  template <typename Comparable>
  void quicksort( vector<Comparable> & a )
  {
      quicksort( a, 0, a.size( ) - 1 );
  }

  //should not go beyond value of k because i > k can't sum to k
  int i, r, sum;
  if( a[ 0 ] != k )
    {  
      for( i = 0; a[ i ] < k && i < a.size( ); ++i )
        {
          for( r = i; a[ r ] < k && r < a.size( ); ++r )
            {
              sum = a[ i ] + a[ r ];
              if( sum == k )
                cout << a[ i ] " " a[ r ]"\n"
                return true;
            }
        }
    }
}