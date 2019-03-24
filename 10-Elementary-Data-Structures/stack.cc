#include <iostream>
#include "stack.h"

int main(){
    Stack<int> s;
    std::cout << s.empty() << std::endl;
    s.push(3);
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;
    s.push(4);
    std::cout << s.top() << std::endl;
    std::cout << s.pop() << ", " << s.pop() << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s.top() << std::endl;
}