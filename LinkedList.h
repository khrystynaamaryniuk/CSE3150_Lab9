#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class LinkedList {
private:
    shared_ptr<Node> root;

public:
    LinkedList() : root(nullptr) {}
    shared_ptr<Node> getRoot() const {
        return root;
    }

    void SERVER_buildCircularLinkedList() {
        vector<string> names = { "zero", "one", "two", "three", "four", "five" };
        int numberOfNodes = names.size();

        root = make_shared<Node>(names[0]);
        shared_ptr<Node> node = root;
        for (int i = 1; i < numberOfNodes; ++i) {
            node->next = make_shared<Node>(names[i]);
            node = node->next;
        }
        node->next = root; 
    }

    void SERVER_printLinkedList() {
        shared_ptr<Node> node = root;
        int count = 0;

        while (node != nullptr && count < 6) {
            cout << "[" << node->name << "] : use_count: " << node.use_count() 
                 << " address: " << node.get() << " next (from shared_ptr): " << node->next.get() << endl;
            node = node->next;
            count++;
        }
    }

    void CLIENT_printLinkedList() {
        weak_ptr<Node> weakNode = root;
        int count = 0;

        while (auto sharedNode = weakNode.lock()) { // Lock weak_ptr to get shared_ptr if available
            cout << "[" << sharedNode->name << "] : use_count: " << sharedNode.use_count() 
                 << " address: " << sharedNode.get() << " next (from weak_ptr): " << sharedNode->next.get() << endl;
            weakNode = sharedNode->next; 
            count++;

            if (count >= 6) break;
        }

        if (count == 0) {
            cout << "[Nothing]" << endl;
        }
    }

    void SERVER_deleteCircularLinkedList() {
        if (!root) return;
    
        shared_ptr<Node> current = root;
        shared_ptr<Node> nextNode = nullptr;
    
        while (current != nullptr) {
            nextNode = current->next;
            current->next = nullptr;  
            current = nextNode;       
            if (current == root) break;  
        }
    
       
        root.reset();
    }
    
};

#endif 