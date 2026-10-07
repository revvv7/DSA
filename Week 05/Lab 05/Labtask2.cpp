#include <iostream>
#include <stack>
using namespace std;

int priority(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string exp)
{
    stack<char> s;
    string postfix = "";

    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // If operand
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }

        // Opening bracket
        else if(ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if(ch == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }

        // Operator
        else
        {
            while(!s.empty() && priority(s.top()) >= priority(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: "
         << infixToPostfix(exp);

    return 0;
}
