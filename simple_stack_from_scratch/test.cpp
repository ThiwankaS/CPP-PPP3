#include <cstdlib>
#include <iostream>

class Stack {

    private:
        int capacity;
        int sp;
        int *arr;

        void resize() {
            int new_capacity = (capacity == 0) ? 2 : (capacity * 2);
            int *ptr = new int[new_capacity];

            for(int i = 0; i <= sp; i++) {
                ptr[i] = arr[i];
            }

            delete [] arr;
            arr = ptr;
            capacity = new_capacity;
            std::cout << "stacke resized [" << new_capacity << "]\n";
        }

    public:
        
        Stack() : capacity(0), sp(-1), arr(nullptr) {}

        ~Stack() {
            delete [] arr;
            capacity = 0;
            sp = -1;
        }

        void push(int value) {
            if(capacity == 0 || sp == (capacity - 1)) {
                resize();
            }
            sp++;
            arr[sp] = value;
        }

        bool empty() {
            if(capacity == 0 || sp == -1) {
                return true;
            }
            return false;
        }

        int pop() {
            if(empty()) {                                
                std::cout << "empty stack ";
                return -1;
            }
            return arr[sp--];
        }

        int peek() {
            if(empty()) {
                std::cout << "empty stack ";
                return -1;
            }
            return arr[sp];
        }

        int size() {
            return sp + 1;
        }

        int buffer() {
            return capacity;
        }

        void info() {
            std::cout << " size : " << size() << " | buffer : " << buffer() << "\n"; 
        }
};


int main(void) {

    Stack myStack;

    std::cout << myStack.peek(); myStack.info();
    myStack.push(10);
    std::cout << myStack.peek(); myStack.info();

    myStack.push(20);
    std::cout << myStack.peek(); myStack.info();

    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    std::cout << myStack.peek(); myStack.info();
    myStack.push(80);
    myStack.push(90);
    std::cout << myStack.peek(); myStack.info();
    
    return EXIT_SUCCESS;
}
