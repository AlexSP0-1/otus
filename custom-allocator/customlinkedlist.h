#ifndef CUSTOMLINKEDLIST_H
#define CUSTOMLINKEDLIST_H

template<typename T>
struct Node {

    Node<T> *next;

    T data;
};

template<typename T, typename Allocator>
class CustomLinkedList {

private:
    Node<T> *head = nullptr;

    Node<T> *current = nullptr;

    typename Allocator::template rebind<Node<T>>::other NodeAllocator;

    CustomLinkedList() = default;

    CustomLinkedList(const CustomLinkedList &other);

    CustomLinkedList(const CustomLinkedList &&other);

    template<typename Alloc>
    CustomLinkedList(const CustomLinkedList<T, Alloc> &other);

    template<typename Alloc>
    CustomLinkedList(const CustomLinkedList<T, Alloc> &&other);

    ~CustomLinkedList();

    void add(const T& newData);

    template<typename ...Args>
    void emplace(Args&& ...args);

    bool isEmpty();

    void clear();

    Node<T> *getNext();

    Node<T> *getHead();
};

#include <customlinkedlist.inl>

#endif //CUSTOMLINKEDLIST_H
