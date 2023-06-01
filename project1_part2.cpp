// Xianqi Cao U83561269
// Matthew Keen U44822882




// Circular array
// - keep track of start and end
// - insert to the end
// - remove elements from the start


// Simulate behavior of a queue
// Insert to the end (enqueue)
// Remove elements from start (dequeue)

#include <iostream>
#include <cstdlib>
#include <queue>
#include <chrono>


// Initialize the circular array with size 500, variables start and end as index. 
class Circular_Array {
    public:
        Circular_Array(){
            storage = new int[500];
            start = 0; 
            end = 0;
        }

// Inserting an element to the end of the array, end will implement by 1 each time, once it reaches 499 it will go back to the beginning

        void insert_end(int element) {
            storage[end] = element;
            end = (end + 1) % 500;
        }

// Removing the element in the beginning of array, it will implement by 1 and come back once it reach 499. 

        void remove_start(){
            storage[start] = 0;
            start = (start + 1) % 500;
        }

// Returns the first value that has not been popped. 

        int get_front(){
            return storage[start];
        }

// Returns the last element entered.  
// We also need to make sure that since it is circular when it reaches max it need to come back.  

        int get_back() {
                return storage[(end - 1 + 500) % 500];
            }
        

// Check if both valeus are the same which can only happen if they are 0. 



// Returns the size of the queue.

        int get_size(){
            if (end >= start)
                return end - start + 1;
            else 
                return 500 - start + end + 1;
        }
// Variables used in this class. 

    private:
        int *storage;
        int start;
        int end;

};


// The queue class contains an circular array and a size variable to keep track of the size. 

class Queue {
public:
    Circular_Array* array;
    int size;

    Queue() {
        array = new Circular_Array();
        size = 0;
    }

// Inserting the element to the end after taking an element from main function. 

    void enqueue(int element) {
        array->insert_end(element);
        size += 1;
    }

// Call the previous remove function to pop the first element in the array. 

    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        array->remove_start();
        size -= 1;
    }


// Size function that return the size of the array currently. 

    int number_of_elements(){
        std::cout << "The size is "; 
        return size;
    }

// The front function that return the front element. We must check if the size is empty or not. 

    int front() {
        if (size == 0) {
            std::cout << "Queue is empty, the size is ";
            return 0;
        } else {
            return array->get_front();
        }
    }


// The back function that return the last element. We must check if the size is empty or not. 

    int back(){
        if (size == 0){
            std::cout << "Queue is empty, the size is ";
            return 0;
        }
        return array->get_back();
    }


// Check if the array is empty.  
    bool empty(){
        if (size == 0)
            return true;
        else{
            return false;
        }
    }

};



// The C++ Built in queue
class builtin_queue {
public:
    std::queue<int> q;

    void enqueue(int element) {
        q.push(element);
    }

    void dequeue() {
        if (q.empty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        q.pop();
    }

    int number_of_elements() {
        return q.size();
    }

    int front() {
        if (q.empty()) {
            std::cout << "Queue is empty." << std::endl;
            return 0;
        }
        return q.front();
    }

    int back() {
        if (q.empty()) {
            std::cout << "Queue is empty." << std::endl;
            return 0;
        }
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

// In main function we compare speed after queueing the same elements to both queues. 
// The case below is the test case given. 


int main() {
    Queue queue;
    queue.enqueue(5);
    queue.enqueue(8);
    queue.enqueue(4);
    queue.enqueue(2);

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << queue.front() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Our front operation took: " << duration.count() << " seconds." << std::endl;
    }

    builtin_queue queue2;
    queue2.enqueue(5);
    queue2.enqueue(8);
    queue2.enqueue(4);
    queue2.enqueue(2);

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << queue2.front() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();  
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "C++ front operation took: " << duration.count() << " seconds." << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        queue.dequeue();
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Our dequeue operation took: " << duration.count() << " seconds." << std::endl;
    }


    {
        auto start_time = std::chrono::high_resolution_clock::now();
        queue2.dequeue();
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "C++ dequeue operation took: " << duration.count() << " seconds." << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    std::cout << "New front: ";
    std::cout << queue.front() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    queue.dequeue();
    queue2.dequeue();

    std::cout << "New front: ";
    std::cout << queue.front() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    queue.dequeue();
    queue2.dequeue();

    std::cout << "New front: ";
    std::cout << queue.front() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << queue.back() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Our back operation took: " << duration.count() << " seconds." << std::endl;
    }

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << queue2.back() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "C++ back operation took: " << duration.count() << " seconds." << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;


    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << std::boolalpha << queue.empty() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Our empty operation took: " << duration.count() << " seconds." << std::endl;
    }

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << std::boolalpha << queue2.empty() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "C++ empty operation took: " << duration.count() << " seconds." << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    queue.dequeue();
    queue2.dequeue();
    std::cout << "New front: ";
    std::cout << queue.front() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << queue.number_of_elements() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Our size operation took: " << duration.count() << " seconds." << std::endl;
    }

    {
        auto start_time = std::chrono::high_resolution_clock::now();
        std::cout << "The size is " << queue2.number_of_elements() << std::endl;
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "C++ size operation took: " << duration.count() << " seconds." << std::endl;
    }
    return 0;
}






