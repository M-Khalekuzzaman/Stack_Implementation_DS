#include<bits/stdc++.h>
#include"MYSTACKHEADER.h"
using namespace std;
int main()
{
    Stack st;
    st.push("Kaochar");
    st.push("Khalekuzzaman");
    st.push("Shakib");
    st.push("Sha-alom");
    st.push("Anower");
    while(! st.empty())
    {
        cout<<st.pop()<<endl;
    }
    cout<<endl<<st.size()<<endl;
    if(st.empty() == true)
    {
        cout<<"NOT EMPTY"<<endl;
    }
    else cout<<"Stack is Empty"<<endl;



    return 0;
}
