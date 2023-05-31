// Circular array
// - keep track of start and end
// - insert to the end
// - remove elements from the start


// Simulate behavior of a queue
// Insert to the end (enqueue)
// Remove elements from start (dequeue)

#include <iostream>

class Circular_Array {
    
    public:
        Circular_Array(){
            storage = new int[500];
            start = 0; 
            end = 0;
        }
        void insert_end(int element){
            end += 1;
            end = end % 500;
            storage[end] = element;
        }

        void remove_start(){
            storage[start] = 0;
            start += 1;
        }
     void print() {
        int current = start;
        while (current != end) {
            std::cout << storage[current] << '\n';
            current = (current + 1) % 500;
        }
        std::cout << storage[current] << '\n';
    }


    private:
        int *storage;
        int start;
        int end;

};


class Queue {
public:
    Queue() {
        array = new Circular_Array();
        size = 0;
    }

    void enqueue(int element) {
        array->insert_end(element);
        size += 1;
    }

    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        array->remove_start();
        size -= 1;
    }
    void print() {
        array->print();
    }

private:
    Circular_Array* array;
    int size;
};



int main (){

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.dequeue();
    queue.enqueue(3);
    queue.dequeue();


    queue.print();
    return 0;
}