#pragma once

#include "Node.hpp"
#include <stdexcept>
#include <utility>

template <typename any_type>
class List {
    public:
        List();
        ~List();
        List(const List<any_type>& other);
        List<any_type>& operator=(List<any_type> other);
        List(List<any_type>&& other) noexcept;
        void push_front(const any_type& value);
        void push_front(any_type&& value);
        any_type pop_front(void);
        bool empty() const;
        void clear();
    private:
        Node<any_type>* head;
        void swap(List<any_type>& other) noexcept;
};

template<typename any_type>
List<any_type>::List() : head(nullptr) {}

template<typename any_type>
List<any_type>::~List() {
    clear();
}

template<typename  any_type>
List<any_type>::List(const List<any_type>& other) : head(nullptr) {
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
}

template<typename any_type>
void List<any_type>::swap(List& other) noexcept {
    std::swap(this->head, other.head);
}

template<typename any_type>
List<any_type>& List<any_type>::operator=(List<any_type> other) {
    this->swap(other);
    return *this;
}

template<typename any_type>
List<any_type>::List(List<any_type>&& other) noexcept : head(nullptr) {
    this->swap(other);
}

template<typename any_type>
void List<any_type>::push_front(const any_type& value) {
    Node<any_type>* newNode = new Node<any_type>(value);
    newNode->next = head;
    head = newNode;
}

template<typename any_type>
void List<any_type>::push_front(any_type&& value) {
    Node<any_type>* newNode = new Node<any_type>(std::move(value));
    newNode->next = head;
    head = newNode;
}

template<typename any_type>
any_type List<any_type>::pop_front(void) {
    if(this->empty()) {
        throw std::runtime_error("pop_front attempted on an empty list.");
    }
    Node<any_type>* temp = head;
    any_type extarcted_data = std::move(temp->data);
    head = head->next;
    delete temp;
    return extarcted_data;
}

template<typename any_type>
bool List<any_type>::empty(void) const {
    return (head == nullptr);
}

template<typename any_type>
void List<any_type>::clear(void) {
    while (!empty()) {
        pop_front();
    }
}
