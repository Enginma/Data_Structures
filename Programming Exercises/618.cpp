#include <iostream>
#include <vector>




/* 
Part A 
To find the minimum element we can simply just return the root of the tree. To find the maximum element, 
we compare the left and right child of the root and return the bigger one and that will be the maximum element. 
*/


// Part B and Part C
using namespace std;
class MinMaxHeap {
public:
    vector<int> heap;

// Initialize variables for later comparisons. 
    int parent(int i) { 
        return (i - 1) / 2; 
    }

    int grandparent(int i) { 
        return parent(parent(i)); 
    }

    int left_child(int i) { 
        return 2 * i + 1; 
    }

    int right_child(int i) { 
        return 2 * i + 2; 
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }


// The trickled up function is here to help insert function to restore the min-max heap structure's order. 
    void trickle_up(int index) {
        int current = index;
        int grandparent_index = grandparent(current);

        if (current > 0 && heap[current] < heap[parent(current)]) {
            swap(heap[current], heap[parent(current)]);
            trickle_up(parent(current));
        }
        else if (current > 2 && heap[current] > heap[grandparent_index]) {
            swap(heap[current], heap[grandparent_index]);
            trickle_up(grandparent_index);
        }
    }

// Get value and put it into the heap then restores the order of the min-max tree. 
    void insert(int value) {
        heap.push_back(value);
        trickle_up(heap.size() - 1);
    }



    void trickle_down(int index) {
        int current = index;
        int left_child_index = left_child(current);
        int right_child_index = right_child(current);

        int minmaxIdx = current;

        // Find the minimum or maximum among the children and grandchildren
        for (int i = left_child_index; i <= right_child_index && i < heap.size(); i++) {
            if (i % 2 == 0 && heap[i] < heap[minmaxIdx]) { // Even level (min level)
                minmaxIdx = i;
            }
            else if (i % 2 != 0 && heap[i] > heap[minmaxIdx]) { // Odd level (max level)
                minmaxIdx = i;
            }
        }

        if (minmaxIdx != current) {
            swap(heap[current], heap[minmaxIdx]);
            trickle_down(minmaxIdx);
        }
    }

    void delete_min() {
        if (heap.empty()) {
            cout << "Min-max heap is empty." << endl;
            return;
        }

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        // Perform trickle down from the root.
        trickle_down(0);
    }

    void delete_max() {
        if (heap.empty()) {
            return;
        }

        int max_index = (heap.size() > 1 && heap[1] > heap[0]) ? 1 : 0;

        // Find the maximum element index
        for (int i = 2; i < heap.size(); i++) {
            if (i % 2 != 0 && heap[i] > heap[max_index]) {
                max_index = i;
            }
        }

        swap(heap[max_index], heap[heap.size() - 1]);
        heap.pop_back();

        // Perform trickle down operation from the position of the maximum element.
        trickle_down(max_index);
    }
};



/*
Part D
Yes you can build it in linear time. The worst case scenario with trickle up and down functions will be O(N) and the average
time is O(log N). Therefore it is possible to build a min-max heap in linear time.  

Part E
First, we need to make one min heap and one max heap. After every insertion, we compare with the root of the max heap and if it smaller 
we put it in the max heap and min heap if it is bigger. After inserting it we check the size of each array to make sure the difference 
is not more than 1, if it is we will rebalance it. 

To delete min or max, we simply delete the root of the desired heap and then balance it. In the end we merge the two min-max heaps 
together and this will make it O(N log N).

*/

