#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
    {
        return 1;
    }

    if (operator== '*' || operator== '/')
    {
        return 2;
    }
    return 0;
}

int calculate(int num1, int num2, char operator)
{
    if (operator== '+')
    {
        return num1 + num2;
    }
    if (operator== '-')
    {
        return num1 - num2;
    }
    if (operator== '*')
    {
        return num1 * num2;
    }
    if (operator== '/')
    {
        return num1 / num2;
    }
    return 0; 
}


int evaluateExpression(const char *expression, int *errorFlag)
{
    
    int numbers[MAX_LEN], numTop = -1;
    char operators[MAX_LEN], opTop = -1;

    
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        
        if (isspace(current))
        {
            continue;
        }

        
        if (isdigit(current))
        {
            int number = 0;
            while (isdigit(expression[i]))
            {
                number = number * 10 + (expression[i] - '0');
                i++;
            }
            i--;                        
            numbers[++numTop] = number; 
        }
        
        else if (current == '+' || current == '-' || current == '*' || current == '/')
        {
            while (opTop >= 0 && precedence(operators[opTop]) >= precedence(current))
            {
                
                char op = operators[opTop--];
                int num2 = numbers[numTop--];
                int num1 = numbers[numTop--];

                
                if (op == '/' && num2 == 0)
                {
                    *errorFlag = 1;
                    return 0;
                }

                
                numbers[++numTop] = calculate(num1, num2, op);
            }
            operators[++opTop] = current; 
        }
        
        else
        {
            *errorFlag = 2;
            return 0;
        }
    }

    
    while (opTop >= 0)
    {
        char op = operators[opTop--];
        int num2 = numbers[numTop--];
        int num1 = numbers[numTop--];

        if (op == '/' && num2 == 0)
        {
            *errorFlag = 1;
            return 0;
        }

        numbers[++numTop] = calculate(num1, num2, op);
    }

    
    return numbers[numTop];
}

int main()
{
    char expression[MAX_LEN];
    printf("Enter a mathematical expression: ");
    fgets(expression, MAX_LEN, stdin); 

    
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n')
    {
        expression[len - 1] = '\0';
    }

    int errorFlag = 0; 
    int result = evaluateExpression(expression, &errorFlag);

    if (errorFlag == 1)
    {
        printf("Error: Division by zero.\n");
    }
    else if (errorFlag == 2)
    {
        printf("Error: Invalid expression.\n");
    }
    else
    {
        printf("Result: %d\n", result);
    }

    return 0;
}