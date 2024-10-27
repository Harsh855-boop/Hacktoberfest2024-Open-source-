#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Class for Singly Linked List
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize head to nullptr
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

    // Function to insert a new node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        cout << "Node inserted at the beginning with value: " << data << endl;
    }

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = createNode(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Node inserted at the end with value: " << data << endl;
    }

    // Function to delete a node by value
    void deleteNode(int data) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete node." << endl;
            return;
        }

        // Deleting head node
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << data << " deleted." << endl;
            return;
        }

        // Deleting other nodes
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != data) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with value " << data << " not found." << endl;
        } else {
            previous->next = current->next;
            delete current;
            cout << "Node with value " << data << " deleted." << endl;
        }
    }

    // Function to traverse and display the linked list
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    SinglyLinkedList list;

    // Insert nodes at the beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);

    // Insert nodes at the end
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Traverse and display the list
    list.traverse();

    // Delete a node
    list.deleteNode(20);
    list.traverse();

    // Delete another node
    list.deleteNode(40);
    list.traverse();

    return 0;
}
