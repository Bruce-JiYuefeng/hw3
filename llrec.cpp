#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void attachNode(Node*& list, Node*& node) {
    node->next = list;
    list = node;
}

void llpivotHelper(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == nullptr) {
        return;
    }

    Node* currentNode = head;
    head = head->next; 
    currentNode->next = nullptr; 

    if (currentNode->val <= pivot) {
        attachNode(smaller, currentNode);
    } else {
        attachNode(larger, currentNode);
    }

    llpivotHelper(head, smaller, larger, pivot);
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    smaller = nullptr;
    larger = nullptr;
    Node *smallerTail = nullptr, *largerTail = nullptr; 

    while (head != nullptr) {
        Node* nextNode = head->next; 
        head->next = nullptr; 
        if (head->val <= pivot) {
            if (smaller == nullptr) {
                smaller = head;
                smallerTail = head;
            } else {
                smallerTail->next = head;
                smallerTail = head;
            }
        } else {
            if (larger == nullptr) {
                larger = head;
                largerTail = head;
            } else {
                largerTail->next = head;
                largerTail = head;
            }
        }
        head = nextNode;
    }

    head = nullptr; 
}


