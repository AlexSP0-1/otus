#include <customlinkedlist.h>

template<typename T, typename Allocator>
CustomLinkedList<T,Allocator>::CustomLinkedList(const CustomLinkedList<T, Allocator> &other) {
    Node<T> pCurrent = other.head;

    while(pCurrent) {
        add(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

template<typename T, typename Allocator>
CustomLinkedList<T,Allocator>::CustomLinkedList(const CustomLinkedList &&other)
    :head(other.head) {

    other.head = nullptr;
}

template<typename T, typename Allocator>
template<typename Alloc>
CustomLinkedList<T,Allocator>::CustomLinkedList(const CustomLinkedList<T, Alloc> &other) {
    Node<T> pCurrent = other.getHead();

    while(pCurrent) {
        add(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

template<typename T, typename Allocator>
template<typename Alloc>
CustomLinkedList<T,Allocator>::CustomLinkedList(const CustomLinkedList<T, Alloc> &&other) {
    Node<T> pCurrent = other.getHead();

    while(pCurrent) {
        add(std::move(pCurrent->data));
        pCurrent = pCurrent->next;
    }

    other.head = nullptr;
}

template<typename T, typename Allocator>
CustomLinkedList<T,Allocator>::~CustomLinkedList() {
    clear();
}

template<typename T, typename Allocator>
void CustomLinkedList<T,Allocator>::add(const T &newData) {

    Node<T> *temp;

    Node<T> *newNode = NodeAllocator.allocate(1u);

    NodeAllocator.costruct(newNode->data, newData);

    newNode->next = nullptr;

    if(!head) {

        head = current = newNode;
    }
    else
    {
        current = head;

        while(current) {

            temp = current;

            current = current->next;
        }

        temp->next = newNode;
    }

}

template<typename T, typename Allocator>
template<typename ...Args>
void CustomLinkedList<T,Allocator>::emplace(Args&& ...args) {

}

template<typename T, typename Allocator>
bool CustomLinkedList<T,Allocator>::isEmpty() {
    return !head;
}

template<typename T, typename Allocator>
void CustomLinkedList<T,Allocator>::clear() {

    Node<T> *temp;

    current = head;

    while(current) {
        temp = current;

        current = current->next;

        NodeAllocator.destroy(temp->data);

        NodeAllocator.deallocate(temp, 1u);
    }

    head = nullptr;
}

template<typename T, typename Allocator>
Node<T>* CustomLinkedList<T,Allocator>::getNext() {
    return current->next;
}

template<typename T, typename Allocator>
Node<T>* CustomLinkedList<T,Allocator>::getHead() {
    return head;
}



template<typename T, typename Allocator>
typename CustomLinkedList<T, Allocator>::iterator CustomLinkedList<T, Allocator>::before_begin() {
    beforeHead.next = head;

    return iterator(&beforeHead);
}

template<typename T, typename Allocator>
typename CustomLinkedList<T, Allocator>::iterator CustomLinkedList<T, Allocator>::erase_after(iterator it) {

    if(it != end()) {
        Node<T> *temp = it.ptrToNode()->next;

        if(temp) {
            it.ptrToNode()->next = temp->next;
            NodeAllocator.destroy(&temp->data);
            NodeAllocator.destroy(temp, 1u);
        }

    }
}

