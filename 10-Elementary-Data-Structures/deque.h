#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <vector>

template<typename T> class Deque{
private:
    typedef T value_type;
    std::vector<T> vec;
    typename std::vector<T>::iterator it_head;
    typename std::vector<T>::iterator it_tail;
    int qsize;
    int qcap;
public:
    Deque(int c = 50){
        qcap = c;
        qsize = 0;
        vec.assign(qcap, 0);
        it_head = it_tail = vec.begin();
    }
    int size() const{
        return qsize;
    }
    int capacity() const{
        return qcap;
    }

    bool empty() const{
        if(qsize == 0)
            return true;
        else
            return false;
    }
    void enqueue(T val){
        if(qsize == qcap){
            throw std::runtime_error("Queue Overflow!");
        }
        if(it_tail-vec.begin() == qcap){
            std::cout << "Round! val: " << val << std::endl;
            it_tail = vec.begin();
            *it_tail++ = val;
        }else{
            *it_tail++ = val;
        }
        ++qsize;
    }

    T dequeue(){
        if(it_tail-it_head<0){
            T rval = *it_head++;
            if(it_head == vec.end()){
                it_head = vec.begin();
            }
            --qsize;
            return rval;
        }else if(it_tail == it_head && qsize == 0){
            throw std::runtime_error("Queue Underflow!");
        }else{
            --qsize;
            return *it_head++;
        }
    }

    // enqueue from head (reverse)
    void renqueue(T val){
        if(qsize == qcap){
            throw std::runtime_error("Queue Overflow!");
        }
        if(it_head == vec.begin()){
            std::cout << "rRound! val: " << val << std::endl;
            it_head = vec.end()-1;
            *it_head = val;
        }else{
            *--it_head = val;
        }
        ++qsize;
    }

    // dequeue from tail (reverse)
    T rdequeue(){
        if(it_tail-it_head<0){
            T rval = *--it_tail;
            if(it_tail == vec.begin()){
                it_tail = vec.end();
            }
            --qsize;
            return rval;
        }else if(it_tail == it_head && qsize == 0){
            throw std::runtime_error("Queue Underflow!");
        }else{
            --qsize;
            return *--it_tail;
        }
    }

    T head() const{
        if(!empty()){
            return *it_head;
        }else{
            throw std::runtime_error("Queue Empty!");
        }
    }
    T tail() const{
        if(!empty()){
            return *(it_tail-1);
        }else{
            throw std::runtime_error("Queue Empty!");
        }
    }
    T rhead() const{
        return tail();
    }
    T rtail() const{
        return head();
    }
};


#endif // !DEQUE_H