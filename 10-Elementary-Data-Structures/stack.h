#ifndef STACK_H
#define STACK_H

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

#endif // !STACK_H