#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};


Node* constructDLL(vector<int>& arr) {
    if (arr.empty())
        return nullptr;

    
    Node* head = new Node(arr[0]);
    Node* temp = head;

    
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);

        temp->next = newNode;   // Forward link
        newNode->prev = temp;   // Backward link

        temp = newNode;
    }

    return head;
}

// Print from head to tail
void printForward(Node* head) {
    Node* temp = head;

    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print from tail to head
void printBackward(Node* head) {
    if (head == nullptr)
        return;

    Node* temp = head;

    // Move to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    Node* head = constructDLL(arr);

    printForward(head);
    printBackward(head);

    return 0;
}