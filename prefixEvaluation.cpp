#include<bits/stdc++.h>
#include"MYSTACK.H"
using namespace std;

int prefixEvaluation(string str)
{
    Stack <int> st;
    for(int i = str.length()-1 ; i>=0; i--)
    {
        //Case 1:  character are operant
        if(str[i]>='0' && str[i]<='9')
        {
            st.push(str[i] - '0');
        }
        //Case 2: character are operator
        else
        {
            int a = st.pop();
            int b = st.pop();
            switch(str[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;
            default:
                break;

            }
        }

    }
    return st.Top();
}

int main()
{
    string str = "-+7*45+20";
    cout<<prefixEvaluation(str)<<endl;

    return 0;
}
