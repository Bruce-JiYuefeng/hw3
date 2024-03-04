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
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node dummySmall(0, nullptr);
    Node dummyLarge(0, nullptr);
    Node* tailSmall = &dummySmall;
    Node* tailLarge = &dummyLarge;

    while (head != nullptr) {
        Node* next = head->next;
        if (head->val <= pivot) {
            tailSmall->next = head;
            tailSmall = head;
        } else {
            tailLarge->next = head;
            tailLarge = head;
        }
        head->next = nullptr; // Detach the current node.
        head = next;
    }

    smaller = dummySmall.next;
    larger = dummyLarge.next;
    head = nullptr; // Ensure the original list is marked as empty.
}

