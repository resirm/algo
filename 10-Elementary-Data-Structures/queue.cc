#include <iostream>
#include "queue.h"

int main(){
    Queue<int> q;
    std::cout << q.empty() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.capacity() << std::endl;
    q.enqueue(3);
    std::cout << q.head() << std::endl;
    std::cout << q.size() << std::endl;
    q.enqueue(5);
    std::cout << q.head() << std::endl;
    std::cout << q.empty() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.size() << std::endl;
    // std::cout << q.head() << std::endl;
    for(int i = 0; i < 50; ++i){
        q.enqueue(i);
    }
    std::cout << q.size() << std::endl;
    std::cout << q.tail() << std::endl;
    std::cout << q.dequeue() << std::endl;
    q.enqueue(100);
    // q.enqueue(100);
    std::cout << q.head() << std::endl;
    for(int i = 0; i < 50; ++i){
        std::cout << q.dequeue() << ", ";
    }
    std::cout << std::endl;
}