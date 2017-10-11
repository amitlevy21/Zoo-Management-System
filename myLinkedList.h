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
    int size;
    Node* head;
    Node* tail;

    class Node
    {
    private:
        T& data;
        Node* next;

        Node(const T& data, Node* next = nullptr);

        ~Node();

        friend class MyLinkedList;

    public:
        const Node* getNext(Node* p)    const;

        const T& getData()              const;
    };

public:
    MyLinkedList();

    ~MyLinkedList();

    int getSize()           const;
    const Node* getHead()   const;
    const Node* getTail()   const;

    void addNodeToBackOfList(const T data);

    void removeFirstNodeFound(const T dataToRemove) throw(const char*);

    void printList()        const;
};

template <class T>
MyLinkedList::Node::Node(const T &data, MyLinkedList::Node *next): data(data), next(next)
{}

template <class T>
MyLinkedList::Node::~Node()
{
    delete next;
}

template <class T>
const MyLinkedList::Node* MyLinkedList::Node::getNext(MyLinkedList::Node *p) const
{
    return next;
}

template <class T>
const T& MyLinkedList::Node::getData() const
{
    return data;
}

template <class T>
MyLinkedList::MyLinkedList(): size(0), head(nullptr), tail(nullptr)
{
}

template <class T>
int MyLinkedList::getSize() const
{
    return size;
}

template <class T>
const MyLinkedList::Node *MyLinkedList::getHead() const
{
    return head;
}

template <class T>
const MyLinkedList::Node *MyLinkedList::getTail() const
{
    return tail;
}

template <class T>
void MyLinkedList::addNodeToBackOfList(const T data)
{
    Node* newNode = new Node(data);

    if(size == 0)
    {
        this->head = newNode;
        tail = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
void MyLinkedList::removeFirstNodeFound(const T dataToRemove)
{
    if(dataToRemove == head->data)
    {
        head = head->next;
        delete head;
        size--;
        return;
    }
    else if(dataToRemove == tail->data)
    {
        size--;
        delete tail;
        Node* p = head;
        for (int i = 0; i < size; i++)
        {
            p = p->next;
        }

        tail = p;
        return;
    }
    else
    {
        Node* p = head;
        for (int i = 0; i < size - 1; i++)
        {
            if(dataToRemove == p->next->data)
            {
                Node* temp = p->next->next;
                delete p->next;
                p->next = temp;
                return;
            }
            p = p->next;
        }
    }
    throw("required node is not part of the list.");
}

template <class T>
void MyLinkedList::printList() const
{
    Node* p = head;
    cout << "[";
    for (int i = 0; i < size; ++i)
    {
        cout << p->data << ", ";
    }
    cout << "\b]";
}

MyLinkedList::~MyLinkedList()
{
    delete head;
    delete tail;
}


#endif //ZOO_MANAGEMENT_SYSTEM_MYLINKEDLIST_H
