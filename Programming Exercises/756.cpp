#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void percolateUp(vector<int>& heap, int hole) {
    int parent = hole / 2;
    int element = heap[hole];


// Moving the element up to the heap until the correct place is reached. 
    while (hole > 1 && element > heap[parent]) {
        heap[hole] = heap[parent];
        hole = parent;
        parent = hole / 2;
    }


// Once we get to the position we place the element in that hole. 
    heap[hole] = element;
}


void percolateDownAlternative(vector<int>& heap, int hole) {
    int element = heap[hole];
    int child;


// This while loop will move the hole down as far as possible 
    while (hole * 2 + 1 <= heap.size() - 1) {
        child = hole * 2 + 1;


// Determine rather left or right child is bigger. 
        if (child + 1 <= heap.size() - 1 && heap[child + 1] > heap[child]) {
            child++;
        }

// Make the larger child to the hole. 
        heap[hole] = heap[child];
        hole = child;
    }

// Percolate the new cell up as the question stated.
    percolateUp(heap, hole);


// Place the element in the desired place. 
    heap[hole] = element;
}







void insert(vector<int>& heap, int element) {
    heap.push_back(element);  
    int hole = heap.size() - 1;
    percolateDownAlternative(heap, hole);
}


// The normal percolate down function. heap is the array and hole is the position that the integer needs to go. 

void percolateDown(vector<int>& heap, int hole) {
    int element = heap[hole];
    int child;

    while (hole * 2 <= heap.size() - 1) {
        child = hole * 2;

        if (child + 1 <= heap.size() - 1 && heap[child + 1] > heap[child]) {
            child++;
        }

        if (heap[child] > element) {
            heap[hole] = heap[child];
            hole = child;
        } else {
            break;
        }
    }

    heap[hole] = element;
}

void heapSort(vector<int>& arr) {
    vector<int> heap;
    heap.reserve(arr.size() + 1);  // Reserve capacity equal to size of input array

    for (int i = 0; i < arr.size(); i++) {
        insert(heap, arr[i]);
    }

    arr.clear();
    for (int i = 1; i < heap.size(); i++) {
        arr.push_back(heap[i]);
    }

    // Sorting the array using standard sorting algorithm (here, std::sort)
    std::sort(arr.begin(), arr.end());
}


int main() {
    vector<int> arr = {4, 3, 2, 9, 7, 5, 8, 1, 6, 1, 2, 3,4,5,6,7,8,5,3,2,1,1,23,3,5,6,7,8,9,2,23,4,5,6,7,8,9,1,90};  // Example array.

    // Sorting with standard heapsort
    vector<int> standardHeapSort(arr);
    auto startStandard = high_resolution_clock::now();
    std::make_heap(standardHeapSort.begin(), standardHeapSort.end());
    std::sort_heap(standardHeapSort.begin(), standardHeapSort.end());
    auto stopStandard = high_resolution_clock::now();

    // Sorting with alternative percolateDown strategy
    vector<int> alternativeHeapSort(arr);
    auto startAlternative = high_resolution_clock::now();
    heapSort(alternativeHeapSort);
    auto stopAlternative = high_resolution_clock::now();

    cout << "Standard heapsort: ";
    for (int num : standardHeapSort) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Alternative heapsort: ";
    for (int num : alternativeHeapSort) {
        cout << num << " ";
    }
    cout << endl;

    auto durationStandard = duration_cast<microseconds>(stopStandard - startStandard);
    auto durationAlternative = duration_cast<microseconds>(stopAlternative - startAlternative);

    cout << "Standard heapsort duration: " << durationStandard.count() << " microseconds" << endl;
    cout << "Alternative heapsort duration: " << durationAlternative.count() << " microseconds" << endl;

    return 0;
}

