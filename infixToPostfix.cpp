#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int precisionCalc(char ch)
{
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}
string infixToPostfix(string str)
{
    Stack <char>st;
    string result;
    for(int i = 0; i<str.length(); i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            result += str[i];
        }
        else if(str[i] == '(')
        {
            st.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(!st.empty() && st.Top() != '(')
            {
                result += st.pop();
            }
            if(!st.empty()) st.pop();
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

    return result;
}

double postfixEvaluation(string str)
{
    Stack <double>st;
    for(int i = 0; i<str.length(); i++)
    {
        // case 1: character of operant
        if(str[i]>='0' && str[i]<='9')
        {
            st.push(str[i]-'0');
        }
        else
        {
            double a = st.pop();
            double b = st.pop();
            //cout<<"a --> "<<a<<" b --> "<<b<<endl;

            switch(str[i])
            {
            case '+':
                st.push(b+a);
                break;
            case '-':
                st.push(b-a);
                break;
            case '*':
                st.push(b*a);
                break;
            case '/':
                st.push(b/a);
                break;
            case '^':
                st.push(pow(b,a));
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
    string infix = "(4*(3+5))+(2/4)";

    string postfix = infixToPostfix(infix);
    cout<<postfix<<endl<<endl;

    cout<<postfixEvaluation(postfix)<<endl;


    return 0;
}
