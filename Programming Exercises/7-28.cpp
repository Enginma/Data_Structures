//a
int i = left, j = right - 1;
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