#include <iostream>
#include <stack>
using namespace std;

int calculate(int a, int b, char op)
{
    if(op == '+')
        return a + b;

    if(op == '-')
        return a - b;

    if(op == '*')
        return a * b;

    if(op == '/')
        return a / b;

    return 0;
}

int evaluatePostfix(string exp)
{
    stack<int> s;

    for(int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // If operand
        if(ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }

        // If operator
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result = calculate(a, b, ch);

            s.push(result);
        }
    }

    return s.top();
}

int main()
{
    string exp;

    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp);

    return 0;
}
