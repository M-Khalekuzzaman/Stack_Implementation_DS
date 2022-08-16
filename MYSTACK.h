#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;
    Node *Prev;

    //Constructor declare
    Node(int data)
    {
        this -> data = data;
        this -> Prev = NULL;
        this -> Next = NULL;
    }
};
class Stack
{
    Node *head;
    Node *top;
    int count;
public:
    Stack()
    {
        head = NULL;
        top = NULL;
        count = 0;
    }

    //PUSH
    void push(int val)
    {
        Node *newNode = new Node(val);
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
    int pop(void)
    {
        Node *delNode = top;
        int check = -1;
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
    int Top(void)
    {
        if(head == NULL)
        {
            cout<<"There is no value in the top(Stack Underflow)"<<endl;
            return -1;
        }
        else return top->data;
    }
};

