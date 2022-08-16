#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    if(st.Top() != -1)
    {
        cout<<st.Top()<<endl;
    }
    cout<<st.size()<<endl;

    return 0;
}

