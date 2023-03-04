#include <iostream>
using namespace std;


// Node data structure.
struct Node {
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};