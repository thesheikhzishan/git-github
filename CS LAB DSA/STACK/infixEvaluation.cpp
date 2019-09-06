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
int perform(int a, int b, char op)
{
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
    if(op == '*')
        return a * b;
    if(op == '/')
        return a / b;
    if(op == '^')
        return a ^ b;
}
int infixEvaluation(string s)
{
    stack<int> value;
    stack<char> opt;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == ' ')
            continue;
        else if(isdigit(s[i]))
        {
            int val = 0;
            while(isdigit(s[i]) && i < n)
            {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            value.push(val);
        }

        else if(s[i] == '(')
            opt.push(s[i]);
        else if(s[i] == ')')
        {
            while(!opt.empty() && opt.top() != '(')
            {
                int op2 = value.top(); value.pop();
                int op1 = value.top(); value.pop();
                char op = opt.top();   opt.pop();
                value.push(perform(op1, op2, op));
            }
            if(!opt.empty())
                opt.pop();

        }
        else
        {
            while(!opt.empty() && prec(s[i]) <= prec(opt.top()))
            {
                int op2 = value.top(); value.pop();
                int op1 = value.top(); value.pop();
                char op = opt.top();   opt.pop();
                value.push(perform(op1, op2, op));
            }
            opt.push(s[i]);
        }
    }
    while(!opt.empty())
    {
        int op2 = value.top(); value.pop();
        int op1 = value.top(); value.pop();
        char op = opt.top();   opt.pop();
        value.push(perform(op1, op2, op));
    }
    return value.top();

}
int main()
{
    string s = "100 * ( 2 + 12 ) / 14";
    cout << infixEvaluation(s);
}

