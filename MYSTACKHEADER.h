#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    string name;
    Node *Prev;
    Node *Next;

    //Constructor declare
    Node(string name)
    {
        this -> name = name;
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
    //Constructor call and Node type pointer initializer
    Stack()
    {
        head = NULL;
        top = NULL;
        count = 0;
    }
    //PUSH
    void push(string name)
    {
        Node *newNode = new Node(name);
        if(head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        top->Next = newNode;
        newNode->Prev = top;
        top = newNode;
        count++;
    }
    //POP
    string pop(void)
    {
        Node *delNode = top;
        string check = "null";
        if(top == NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return check;
        }
        if(top == head) //only 1 element in the stack list
        {
            head = top = NULL;
        }
        else
        {
            top = delNode->Prev;
            delNode->Prev->Next = NULL;
        }
        check = delNode->name;
        delete delNode;
        count--;

        return check;
    }
    //EMPTY
    bool empty(void)
    {
        if(head == NULL) return true;
        else false;
    }
    //SIZE
    int size(void)
    {
        return count;
    }
    //TOP
    string Top(void)
    {
        string chk = "null";
        if(head == NULL)
        {
            cout<<"There is no value in the top(Stack Underflow)"<<endl;
            return chk ;
        }
        else
        {
            chk = top->name;
            return chk;
        }
    }

};

