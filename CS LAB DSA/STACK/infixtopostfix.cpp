#include<bits/stdc++.h>
using namespace std;
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int prec(char c)
{
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    return 0;
}
void infixToPostfix(string s)
{
    string post;
    stack<char> stk;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        if(isOperand(s[i]))
            post += s[i];
        else if(s[i] == '(')
            stk.push(s[i]);
        else if(s[i] == ')')
        {
            while(!stk.empty() && stk.top() != '(')
            {
                char c = stk.top();
                stk.pop();
                post += c;
            }
            if(!stk.empty())
                stk.pop();

        }
        else
        {
            while(!stk.empty() && prec(s[i]) <= prec(stk.top()))
            {
                char c = stk.top();
                stk.pop();
                post += c;
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty())
    {
        post += stk.top();
        stk.pop();
    }
    cout << post <<endl;

}
int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(s);
}

