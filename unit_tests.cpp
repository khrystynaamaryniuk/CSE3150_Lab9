#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"

TEST_CASE("Building Circular Linked List") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();

    
    CHECK(list.getRoot() != nullptr);

    
    CHECK(list.getRoot()->name == "zero");

   
    CHECK(list.getRoot()->next->name == "one");

    
    CHECK(list.getRoot()->next->next->next->next->next->next == list.getRoot());
}

TEST_CASE("Deleting Circular Linked List") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();

    
    CHECK(list.getRoot() != nullptr);
    CHECK(list.getRoot()->name == "zero");

 
    list.SERVER_deleteCircularLinkedList();

   
    CHECK(list.getRoot() == nullptr);
}

TEST_CASE("Client Prints Circular Linked List") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();


    // This won't check output directly but will ensure no crashes
    CHECK_NOTHROW(list.CLIENT_printLinkedList());
}

TEST_CASE("Server Prints Circular Linked List") {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();

    // This won't check output directly but will ensure no crashes
    CHECK_NOTHROW(list.SERVER_printLinkedList());
}
