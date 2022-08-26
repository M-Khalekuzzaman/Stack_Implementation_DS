#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int globalID = 101;

class Person
{
    string name;
    int id;
    float salary;
public:
    Person()
    {
        name = " ";
        id = -1;
        salary = -1.0;
    }
    void setName(string name)
    {
        this -> name = name;
    }
    void setSalary(float salary)
    {
        this -> salary = salary;
    }
    Person(string name,float salary)
    {
        setName(name);
        setSalary(salary);
        id =globalID;
        globalID++;
    }
    string getName(void)
    {
        return name;
    }
    float getSalary(void)
    {
        return salary;
    }
    int getID(void)
    {
        return id;
    }
    void print(void)
    {
        cout<<getName()<<" | "<<getID()<<" | "<<getSalary()<<endl;
    }
};
int main()
{
    Stack <Person> st;
    Person a("Khalekuzzaman",6473.54);
    Person b("Kaochar",8973.43);
    Person c("Laboni",6563.32);
    st.push(a);
    st.push(b);
    st.push(c);
    if(!st.empty())
    {
        Person p;
        p = st.Top();
        p.print();
    }
    cout<<st.size()<<endl;


    return 0;
}
