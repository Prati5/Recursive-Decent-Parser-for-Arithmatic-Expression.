#include<stdio.h>
#include<string.h>
char input[100];
int i=-1,l,st=-1;
// i is used to indicate the current input pointer value and st is current top of the stack
// l holds the length of input string.
char id,num;
void E();
void T();
void F();
void increment();
void Td();
void Ed();
void increment()
{
    i++;
    if(i<l)
    {
        if(input[i]>='0'&& input[i]<='9')
        {
            num=input[i];
            id='\0';
        }
        if((input[i]>='a' || input[i]>='A')&&(input[i]<='z' || input[i]<='Z'))
        {
            id=input[i];
            num='\0';
        }
    }
}
void E()
{
    T();
    Ed();
}
void Ed()
{
    int p=1;
    if(input[i]=='+')
    {
        p=0;
        increment();
        T();
        Ed();
    }
    if(input[i]=='-')
    {  
        p=0;
        increment();
        T();
        Ed();
    }

    // Recursive Descent Parser
    if(p==1)
    {
    }
}

void T()
{
    F();
    Td();
}
void Td()
{
    int p=1;
    if(input[i]=='*')
    {
        p=0;
        increment();
        F();
        Td();
    }
    if(input[i]=='/')
    {  
        p=0;
        increment();
        F();
        Td();
    }
}
void F()
{
    if(input[i]==id) {
    increment();          }
    if(input[i]=='(')
    {
        increment();
        E();
        if(input[i]==')')  
        {
            increment();         
        }
    }
    if(input[i]==num)
    {
        increment();
    }
}
int main()
{
    int i;
    printf("Enter Input String ");
    scanf("%s",input);
    l=strlen(input);
    input[l]='$';
    increment();
    E();
    if(i==l)
    {
        printf("String Accepted\n");
    }
    else
    {
        printf("String rejected\n");
    }

    return 0;
}
