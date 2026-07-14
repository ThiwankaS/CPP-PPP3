#pragma once

#include <utility>

template<typename any_type>
class Node {
    public:
        any_type data;
        Node<any_type>* next;
        Node(const any_type& value);
        Node(any_type&& value);
};

template<typename  any_type>
Node<any_type>::Node(const any_type& value) : data(value), next(nullptr) {}

template<typename any_type>
Node<any_type>::Node(any_type&& value) : data(std::move(value)), next(nullptr) {}
