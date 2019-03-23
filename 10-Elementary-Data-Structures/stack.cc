#include <iostream>
#include <vector>

template<typename T> class Stack{
private:
    typedef T value_type;
    std::vector<T> vec;
    typename std::vector<T>::iterator it_top;
public:
    Stack(){
        it_top = vec.begin();
    }
    bool empty() const{
        if(it_top==vec.begin())
            return true;
        else
            return false;
    }
    void push(T val){
        if(it_top==vec.end()){
            vec.push_back(val);
            it_top = vec.end();
        }else{
            *it_top++ = val;
        }
    }

    T pop(){
        if(it_top==vec.begin()){
            throw std::runtime_error("Stack Underflow!");
        }else{
            return *--it_top;
        }
    }

    T top() const{
        if(!empty()){
            return *(it_top-1);
        }else{
            throw std::runtime_error("Stack Empty!");
        }
    }
};

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