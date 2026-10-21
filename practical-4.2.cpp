#include <iostream>
#include <cctype>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, a, b, result;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        cout << "Division by zero error";
                        return 1;
                    }
                    result = a / b;
                    break;

                case '%':
                    if (b == 0)
                    {
                        cout << "Division by zero error";
                        return 1;
                    }
                    result = a % b;
                    break;

                default:
                    cout << "Invalid operator" << endl;
                    return 1;
            }

            push(result);
        }
    }

    cout << "Result = " << pop() << endl;

    return 0;
}