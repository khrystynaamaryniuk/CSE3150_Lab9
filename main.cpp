#include "LinkedList.h"

int main() {
    LinkedList list;

    // Step 1: Server builds the circular linked list
    list.SERVER_buildCircularLinkedList();

    // Step 2: Server prints the circular linked list
    cout << "Server (step 2):" << endl;
    list.SERVER_printLinkedList();

    // Step 3: Client prints the circular linked list
    cout << "Client (step 3):" << endl;
    list.CLIENT_printLinkedList();
    cout<< "Server is deleting the shared_ptrs (step 4): "<< endl;
    // Step 4: Server deletes the circular linked list
    list.SERVER_deleteCircularLinkedList();

    // Step 5: Client tries to print the circular linked list
    cout << "Client after linked list deleted (step 5 alternatively):" << endl;
    list.CLIENT_printLinkedList();

    return 0;
}