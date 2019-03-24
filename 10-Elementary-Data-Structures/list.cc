#include <iostream>
#include <iomanip>
#include "list.h"

/* test List (doubly linked list)
 */

using std::cout; using std::endl;

int main(){
    List<int> l;
    cout << std::boolalpha << l.empty() << endl;
    l.insert(4);
    l.insert(1);
    l.insert(2);
    l.insert(8);
    l.insert(0);
    l.insert(1);
    cout << l.empty() << endl;
    auto p = l.search(4);
    cout << p->key << endl;
    cout << l.remove(4) << endl;
    p = l.search(4);
    cout << p->key << endl;
    cout << l.empty() << std::noboolalpha << endl;
    cout << l.size() << endl;
    for(p = l.head(); p != nullptr; p = l.next(p)){
        cout << p->key << ", ";
    }
    cout << endl;
}