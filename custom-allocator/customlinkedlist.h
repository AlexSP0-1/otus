#ifndef CUSTOMLINKEDLIST_H
#define CUSTOMLINKEDLIST_H

template<typename T>
struct Node {

    Node<T> *next;

    T data;
};

template<typename T>
class CustomLinkedListIterator : public std::iterator<std::forward_iterator_tag, T> {

    CustomLinkedListIterator() = default;

    CustomLinkedListIterator(Node<T> *ptr) : pCurrent(ptr) {}

    bool operator!=(const CustomLinkedListIterator &other) const {
        return pCurrent != other.pCurrent;
    }

    bool operator==(const CustomLinkedListIterator &other) const {
        return pCurrent == other.pCurrent;
    }

    CustomLinkedListIterator<T> &operator++() {
        pCurrent = pCurrent->next;

        return this;
    }

    CustomLinkedListIterator<T> operator++(int) {
        CustomLinkedListIterator<T> temp = *this;

        pCurrent = pCurrent->next;

        return temp;
    }

    Node<T> *ptrToNode() const {return pCurrent;}

    typename CustomLinkedListIterator::reference operator*() const {
        return pCurrent->data;
    }

    typename CustomLinkedListIterator::pointer operator->() const {
        return pCurrent->data;
    }

    private:
        Node<T> pCurrent = nullptr;
};

template<typename T, typename Allocator>
class CustomLinkedList {

private:
    Node<T> *head = nullptr;

    Node<T> *current = nullptr;

    Node<T> beforeHead;

public:

    typename Allocator::template rebind<Node<T>>::other NodeAllocator;

    using iterator = CustomLinkedListIterator<T>;

    using size_type = size_t;

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

    CustomLinkedList::iterator erase_after(iterator it);

    CustomLinkedList::iterator before_begin();
    CustomLinkedList::iterator begin() {return iterator(head);}
    CustomLinkedList::iterator end() {return iterator();}

};


#include <customlinkedlist.inl>

#endif //CUSTOMLINKEDLIST_H
