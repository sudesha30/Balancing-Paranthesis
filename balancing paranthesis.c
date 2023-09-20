#include <stdio.h>

char s[100];
int top = -1;

void push(char x)
{
    s[++top] = x;
}

void pop()
{
    top--;
}

int main()
{
    char str[101]; scanf("%s", str);
    
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(str[i]);
        else if(top != -1 && ( (str[i] == ')' && s[top] == '(') ||
                               (str[i] == ']' && s[top] == '[') ||
                               (str[i] == '}' && s[top] == '{') ))
            pop();
        else    
        {
            printf("Unbalanced");
            return 0;
        }
    }
    
    if(top == -1)
        printf("Balanced");
    else
        printf("Unbalanced");

    return 0;
}
