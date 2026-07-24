#include <iostream>
#include <vector>
using namespace std;

// Node of Circular Singly Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* constructCSLL(vector<int>& arr) {
    if (arr.empty())
        return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    // Create remaining nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    // Make it circular
    temp->next = head;

    return head;
}


void printCSLL(Node* head) {
    if (head == nullptr)
        return;

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    Node* head = constructCSLL(arr);

    cout << "Circular Linked List: ";
    printCSLL(head);

    return 0;
}
