#include<bits/stdc++.h>
using namespace std;
template <typename N> class Node
{
public:
    N data;
    Node *Next;
    Node *Prev;

    //Constructor declare
    Node(N data)
    {
        this -> data = data;
        this -> Prev = NULL;
        this -> Next = NULL;
    }
};
template <typename S> class Stack
{
    Node <S> *head;
    Node <S> *top;
    int count;
public:
    Stack()
    {
        head = NULL;
        top = NULL;
        count = 0;
    }

    //PUSH
    void push(S val)
    {
        Node <S> *newNode = new Node<S>(val);
        if(head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        top->Next = newNode;
        newNode->Prev = top;
        top = top->Next;
        count++;
    }
    //POP
    S pop(void)
    {
        Node <S> *delNode = top;
        S check;
        if(head == NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return check;
        }
        if(top == head) //only 1 element in the link list
        {
            head = top = NULL;
        }
        else // more element in the link list
        {
            top = delNode->Prev;
            top->Next = NULL;
        }
        check = delNode->data;
        delete delNode;
        count--;

        return check;
    }
    //EMPTY
    bool empty(void)
    {
        if(head == NULL) return true;
        else return false;
    }
    //SIZE
    int size(void)
    {
        return count;
    }
    //TOP
    S Top(void)
    {
        S chk;
        if(head == NULL)
        {
            cout<<"There is no value in the top(Stack Underflow)"<<endl;
        }
        else chk = top->data;

        return chk;
    }
};

