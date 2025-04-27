#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct Node {
    string name;
    shared_ptr<Node> next; // Shared pointer to the next node

    Node(string name) : name{name} {}
    
    ~Node() {
        cout << "Node [" << name << "] destructor" << endl;
    }
};

#endif 
