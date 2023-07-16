template <typename Comparable>
void planesort( int xMin, int xMax, int yMin, int yMax  )
{
  int i = 0;
  int x1 = xMin, x2 = xMin, y1 = yMin, y2 = yMin + 1;

  //should have enough space to hold every possible slope along with its coordinates
  vector<Comparable> slopeArray( ( ( ( xMax - xMin ) / 2 ) * ( ( yMax - yMin ) / 2 ) ) * 4 );
  
  //storing all points and slopes
  while( x1 <= xMax )
    {
      while( y1 <= yMax )
        {
          while( x2 <= xMax )
            {
              while( y2 <= yMax )
                {
                  slope = ( y2 - y1 ) / ( x2 - x1 );
                  
                  a[ i ] = x1;
                  a[ i + 1 ] = y1;
                  a[ i + 2 ] = x2;
                  a[ i + 3 ] = y2;
                  a[ i + 4 ] = slope;

                  ++y2;
                  i = i + 5;
                }
              ++x2;
            }
          ++y1;
        }
      ++x1;
    }
  
  //some modified quicksort that only sorts every i + 5 (slopes) so respective
  //coordinates stay attached.
  quicksort( vector<Comparable> & slopeArray );

  for( ; ; ) /*some for loop that checks for matching original points and slopes
              * 4 and outputs
             */
    if( )
  
}