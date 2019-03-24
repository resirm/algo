#include <iostream>
#include "deque.h"

int main(){
    Deque<int> dq;
    std::cout << dq.empty() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.capacity() << std::endl;
    dq.enqueue(3);
    std::cout << dq.head() << std::endl;
    std::cout << dq.size() << std::endl;
    dq.enqueue(5);
    std::cout << dq.head() << std::endl;
    std::cout << dq.empty() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.dequeue() << std::endl;
    std::cout << dq.size() << std::endl;
    std::cout << dq.dequeue() << std::endl;
    std::cout << dq.size() << std::endl;
    // std::cout << q.head() << std::endl;
    for(int i = 0; i < 50; ++i){
        dq.enqueue(i);
    }
    std::cout << dq.size() << std::endl;
    std::cout << dq.tail() << std::endl;
    std::cout << dq.dequeue() << std::endl;
    dq.renqueue(100);
    // q.enqueue(100);
    std::cout << dq.head() << std::endl;
    for(int i = 0; i < 50; ++i){
        std::cout << dq.rdequeue() << ", ";
    }
    std::cout << std::endl;
}