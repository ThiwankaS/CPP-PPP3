#pragma once

#include "Node.hpp"
#include <cstddef>
#include <stdexcept>
#include <utility>

/**
 * @brief A generic, high-performance, and resource-safe singly linked list.
 * 
 * This class implements standard container functions using the Rule of 5 to safely 
 * support deep copying, resource moving, and efficient O(1) operations.
 * 
 * @tparam any_type The type of elements stored in the list.
 */
template <typename any_type>
class List {
    public:
        /**
         * @brief Constructs an empty singly linked list.
         */
        List();
        /**
         * @brief Destructor. Safely deallocates all nodes to prevent memory leaks.
         */
        ~List();
        /**
         * @brief Copy Constructor. Performs a deep copy of another list's nodes.
         * @param other The source list to be copied.
         */
        List(const List<any_type>& other);
        /**
         * @brief Copy/Move Assignment Operator. Uses the Copy-and-Swap idiom to provide strong exception safety.
         * @param other The list being assigned (passed by value to handle both copy and move).
         * @return Reference to this updated list.
         */
        List<any_type>& operator=(List<any_type> other);
        /**
         * @brief Move Constructor. Transfers ownership of resources from another list without copying.
         * @param other The temporary list being moved from.
         */
        List(List<any_type>&& other) noexcept;
        /**
         * @brief Inserts an element at the front of the list (Copy version).
         * @param value A constant reference to the element to copy into the list.
         */
        void push_front(const any_type& value);
        /**
         * @brief Inserts an element at the front of the list (Move version).
         * @param value An rvalue reference to move into the list without copying.
         */
        void push_front(any_type&& value);
        /**
         * @brief Removes and returns the element at the front of the list.
         * @throw std::runtime_error If the list is empty.
         * @return The data value that was stored in the popped head node.
         */
        any_type pop_front(void);
        /**
         * @brief Accesses the data in the front node without removing it.
         * @throw std::runtime_error If the list is empty.
         * @return A constant reference to the data inside the head node.
         */
        const any_type& peek(void) const;
        /**
         * @brief Checks if the list has no elements.
         * @return True if the list is empty, false otherwise.
         */
        bool empty() const;
        /**
         * @brief Safely deletes all nodes and resets the list state back to empty.
         */
        void clear();
        /**
         * @brief Retrieves the current number of elements in the list.
         * @return The size of the list as a size_t.
         */
        size_t size() const;
    private:
        size_t elements;        //Keeps track of the total elements in the list.
        Node<any_type>* head;   //Pointer to the first node in the list.
        /**
         * @brief Swaps the internal members (head pointer and size) of this list with another.
         * @param other The other list to swap resources with.
         */
        void swap(List<any_type>& other) noexcept;
};

// --- Implementations ---

//Constructor
template<typename any_type>
List<any_type>::List() : elements(0), head(nullptr) {}

//Destructor
template<typename any_type>
List<any_type>::~List() {
    clear();
}

//Copy Constructor
template<typename  any_type>
List<any_type>::List(const List<any_type>& other) : elements(0), head(nullptr) {
    if(other.head == nullptr) {
        return;
    }

    this->head = new Node<any_type>(other.head->data);

    Node<any_type>* current = head;
    Node<any_type>* source  = other.head->next;

    while (source != nullptr) {
        current->next = new Node<any_type>(source->data);
        current = current->next;
        source = source->next;
    }
    this->elements = other.elements;
}

//Assignment operator
template<typename any_type>
List<any_type>& List<any_type>::operator=(List<any_type> other) {
    this->swap(other);
    return *this;
}

//Move Constructor
template<typename any_type>
List<any_type>::List(List<any_type>&& other) noexcept : elements(0), head(nullptr) {
    this->swap(other);
}

//Adding element to the front by copying
template<typename any_type>
void List<any_type>::push_front(const any_type& value) {
    Node<any_type>* newNode = new Node<any_type>(value);
    newNode->next = head;
    head = newNode;
    this->elements++;
}

//Adding elemnt to the front by moving
template<typename any_type>
void List<any_type>::push_front(any_type&& value) {
    Node<any_type>* newNode = new Node<any_type>(std::move(value));
    newNode->next = head;
    head = newNode;
    this->elements++;
}

//Remove first element from the front 
template<typename any_type>
any_type List<any_type>::pop_front(void) {
    if(this->empty()) {
        throw std::runtime_error("pop_front attempted on an empty list.");
    }
    Node<any_type>* temp = head;
    any_type extarcted_data = std::move(temp->data);
    head = head->next;
    delete temp;
    this->elements--;
    return extarcted_data;
}

//Access data containing in the first element (read only)
template<typename any_type>
const any_type& List<any_type>::peek(void) const {
    if(this->empty()) {
        throw std::runtime_error("peek attempted on an empty list.");
    }
    return head->data;
}

//Check if the list is empty
template<typename any_type>
bool List<any_type>::empty(void) const {
    return (head == nullptr);
}

//Delete and relase the resources
template<typename any_type>
void List<any_type>::clear(void) {
    while (!empty()) {
        pop_front();
    }
    this->elements = 0;
}

//Get the size of the list
template<typename any_type>
size_t List<any_type>::size() const {
    return this->elements;
}

//Swap resources of two oobjects
template<typename any_type>
void List<any_type>::swap(List& other) noexcept {
    std::swap(this->head, other.head);
    std::swap(this->elements, other.elements);
}
