
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include "Media.h"
#include <iostream>
template <typename T>
struct Node {
    // Data is now hard-coded to the BASE CLASS pointer: Media*
    T* data;
    Node* next;

    // Constructor initializes data and pointer
    Node(T* media) : data(media), next(nullptr) {}
};

// === 5. Hard-coded LinkedList Class (Singly, Non-Circular) ===
// This list is only capable of managing Media* objects (Song*, Podcast*, etc.) and is forward-only.
template <typename T>
class LinkedList {
private:
    T* head;
    T* tail;
public:
    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr) {}

    // Destructor: Cleans up all nodes and the Media objects they point to.
    ~LinkedList() {
        Node* current = head;
        Node* next_node = nullptr;

        // Traverse the list until the end (nullptr) is reached
        while (current != nullptr) {
            next_node = current->next;
            if (current->next == head) {
                delete current->data;

                    delete current;
                    current = nullptr;
            }
            // Delete the Media object stored in the node's data pointer (polymorphic deletion)
            delete current->data;

            // Delete the node itself
            delete current;

            current = next_node;
            
        }
        head = nullptr; // Ensure head is reset
        std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
    }

    // Insertion: Adds a new Media pointer to the end of the list.
    void insert(Media* newMedia) {
        Media* newNode = new T(newMedia);
        tail.next = head;
        if (head == nullptr) {
            // Case 1: List is empty. New node becomes the head.
            head = newNode;
        } else {
            // Case 2: Traverse to the end and link the new node.
            Node* current = head;
            
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Traversal: Displays all media items in the list.
    void displayList() const {
        if (head == nullptr) {
            std::cout << "\n[Playlist is empty.]" << std::endl;
            return;
        }

        std::cout << "\n--- Current Playlist ---" << std::endl;
        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            // Polymorphism in action: calls the specific toString() method for Song or Podcast
            std::cout << index++ << ". " << current->data->toString() << std::endl;
            current = current->next;
            if (index > 1 && current == head) {
                current = nullptr;
            }
        }
        std::cout << "------------------------" << std::endl;
    }

    // Simple play method for demonstration (students will expand this later)
    void playCurrent() const {
        if (head != nullptr) {
            head->data->play(); // Calls the virtual play() method
        } else {
            std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
        }
    }
    void playnext() {
        Node* current = head;
        if (current = tail) {
            current = head;
            current->next->data;
            current = current->next;

        }
        else {
            
            current->next->data;
            current = current->next;
        }
        
    }
};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H