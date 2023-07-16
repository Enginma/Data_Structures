//first element
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = a[ left ]

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

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right );    
    }
    else  
        insertionSort( a, left, right );
}

//middle element
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = a[ left + right / 2 ]

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

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right );    
    }
    else  
        insertionSort( a, left, right );
}

//random element
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = a[ rand( ) % a.size( ) ]

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

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right );    
    }
    else  
        insertionSort( a, left, right );
}

//median of 3
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
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

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right );    
    }
    else  
        insertionSort( a, left, right );
}

template <typename Comparable>
const Comparable & median3( vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    
    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

//median of 5
template <typename Comparable>
void quicksort( vector<Comparable> & a, int left, int right )
{
    if( left + 10 <= right )
    {
        const Comparable & pivot = median5( a, left, right );

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

        quicksort( a, left, i - 1 );     
        quicksort( a, i + 1, right );    
    }
    else  
        insertionSort( a, left, right );
}

template <typename Comparable>
const Comparable & median5( vector<Comparable> & a, int left, int right )
{
    int center1 = ( left + right ) / 2;
    int center2 = ( left + center1 ) / 2;
    int center3 = ( center1 + right ) / 2;
    
    if( a[ center2 ] < a[ left ] )
        std::swap( a[ left ], a[ center2 ] );
    if( a[ center1 ] < a[ left ] )
        std::swap( a[ left ], a[ center1 ] );
    if( a[ center1 ] < a[ center2 ] )
        std::swap( a[ center2 ], a[ center1 ] );

    if( a[ center3 ] < a[ center1 ] )
        std::swap( a[ center1 ], a[ center3 ] );
    if( a[ right ] < a[ center1 ] )
        std::swap( a[ center1 ], a[ right ] );
    if( a[ right ] < a[ center3 ] )
        std::swap( a[ center3 ], a[ right ] );
    
    if( a[ center1 ] < a[ center2 ] )
        std::swap( a[ center2 ], a[ center1 ] );
    if( a[ center3 ] < a[ center2 ] )
        std::swap( a[ center2 ], a[ center3 ] );
    if( a[ center3 ] < a[ center1 ] )
        std::swap( a[ center1 ], a[ center3 ] );

    std::swap( a[ center1 ], a[ right - 1 ] );
    return a[ right - 1 ];
}