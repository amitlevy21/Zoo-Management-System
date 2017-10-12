//
// Created by Moshe Sheena on 11/10/2017.
//

#ifndef ZOO_MANAGEMENT_SYSTEM_MYLINKEDLIST_H
#define ZOO_MANAGEMENT_SYSTEM_MYLINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class MyLinkedList
{

private:

    class Node
    {
        friend class MyLinkedList;
    private:
        T data;
        Node* next;

        Node(T data, Node* next = nullptr): data(data), next(next) {}

        //~Node() {delete next;}
    };

    int size;
    Node* head;
    Node* tail;

public:
    MyLinkedList();

    ~MyLinkedList();

    int getSize()           const;
    const Node* getHead()   const;
    const Node* getTail()   const;

    void addNodeToBackOfList(const T data);

    void removeFirstNodeFound(const T dataToRemove) throw(const char*);

    void printList(ostream &os) const;

    const Node* getNext(Node* p)  const;

    const T& getData(Node* p)     const;

    const T& operator[](int index) const throw(const char*);
};

template <class T>
MyLinkedList<T>::MyLinkedList(): size(0), head(nullptr), tail(nullptr)
{}

template <class T>
int MyLinkedList<T>::getSize() const
{
    return size;
}

template <class T>
const typename MyLinkedList<T>::Node* MyLinkedList<T>::getHead() const
{
    return head;
}

template <class T>
const typename MyLinkedList<T>::Node* MyLinkedList<T>::getTail() const
{
    return tail;
}

template <class T>
void MyLinkedList<T>::addNodeToBackOfList(const T data)
{
    if(size == 0)
    {
        head = new Node(data);
        tail = new Node(data);
    }
    else if(size == 1)
    {
        Node* newNode = new Node(data);
        head->next = newNode;
        tail = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
void MyLinkedList<T>::removeFirstNodeFound(const T dataToRemove) throw(const char*)
{
    if(dataToRemove == head->data)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    else if(dataToRemove == tail->data)
    {
        size--;
        Node* temp = tail;
        Node* p = head;
        for (int i = 0; i < size - 1; i++)
        {
            p = p->next;
        }

        tail = p;
        tail->next = nullptr;
        delete temp;
        return;
    }
    else
    {
        Node* p = head;
        for (int i = 0; i < size - 1; i++)
        {
            if(dataToRemove == p->next->data)
            {
                Node* temp = p->next;
                p->next = p->next->next;
                temp->next = nullptr;
                delete temp;
                size--;
                return;
            }
            p = p->next;
        }
    }
    throw("required node is not part of the list.");
}

template <class T>
void MyLinkedList<T>::printList(ostream &os) const
{
    Node* p = head;
    os << "[";
    os.flush();
    for (int i = 0; i < size; ++i, p = p->next)
    {
        os << p->data ;
        if(i != size - 1)
            os << ", ";
        os.flush();
    }
    os << "]";
    os.flush();
}

template <class T>
MyLinkedList<T>::~MyLinkedList()
{
    delete head;
    delete tail;
}

template <class T>
const T& MyLinkedList<T>::operator[](int index) const throw(const char*)
{
    if(index < 0 || index >= size)
        throw "index out of bound exception";

    else if(index == 0)
    {
        return head->data;
    }
    else if(index == size - 1)
    {
        return tail->data;
    }
    else
    {
        Node* p = head;
        for (int i = 0; i < index; ++i)
        {
            p = p->next;
        }
        return p->data;
    }
}


#endif //ZOO_MANAGEMENT_SYSTEM_MYLINKEDLIST_H