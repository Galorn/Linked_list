#include <iostream>

using namespace std;
using std::cout;
using std::endl;


class Node
{
    friend class LinkedList;
private:
    int _value; /* data, can be any data type, but use integer for easiness */
    Node *_pNext; /* pointer to the next node */

public:
    /* Constructors with No Arguments */
    Node(void)
    : _pNext(NULL)
    { }

    /* Constructors with a given value */
    Node(int val)
    : _value(val), _pNext(NULL)
    { }

    /* Constructors with a given value and a link of the next node */
    Node(int val, Node* next)
    : _value(val), _pNext(next)
    {}

    /* Getters */
    int getValue(void)
    { return _value; }

    Node* getNext(void)
    { return _pNext; }
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *_pHead;
    /* pointer of tail node */
    Node *_pTail;

public:
    /* Constructors with No Arguments */
    LinkedList(void);
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList(void);

    /* Traversing the list and printing the value of each node */
    void traverse_and_print();
};
LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    _pHead = _pTail = NULL;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    _pHead = new Node(val);
    _pTail = _pHead;
}

LinkedList::~LinkedList()
{
    /*
     * Leave it empty temporarily.
     * It will be described in detail in the example "How to delete a linkedlist".
     */
}

void LinkedList::traverse_and_print()
{
    Node *p = _pHead;

    /* The list is empty? */
    if (_pHead == NULL) {
        cout << "The list is empty" << endl;
        return;
    }


    cout << "LinkedList: ";
    /* A basic way of traversing a linked list */
    while (p != NULL) { /* while there are some more nodes left */
        /* output the value */
        cout << p->_value;
        /* The pointer moves along to the next one */
        p = p->_pNext;
    }
    cout << endl;
}

int main()
{
/* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.traverse_and_print();

    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.traverse_and_print();

}
