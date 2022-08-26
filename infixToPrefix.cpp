#include<bits/stdc++.h>
#include"MYSTACK.H"
using namespace std;
int precisionCalc(char ch)
{
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}
string infixToPrefix(string str)
{
    //Step 1: reverse string
    reverse(str.begin(),str.end());
    //Step 2: 4 condition this step
    Stack <char> st;
    string result;
    for(int i = 0; i<str.length(); i++)
    {
        if(str[i]>= '0' && str[i]<='9')
        {
            result += str[i];
        }
        else if(str[i] == ')')
        {
            st.push(str[i]);
        }
        else if(str[i] == '(')
        {
            while(!st.empty() && st.Top() != ')')
            {
                result += st.pop();
            }
            if(! st.empty()) st.pop();

        }
        else
        {
            while(!st.empty() && precisionCalc(st.Top()) >= precisionCalc(str[i]))
            {
                result += st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty())
    {
        result += st.pop();
    }
    reverse(result.begin(),result.end());

    return result;


}
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
    string infix = "(7+(4*5))-(2+0)";
    string prefix = infixToPrefix(infix);
    cout<<prefixEvaluation(prefix)<<endl;

    return 0;
}

