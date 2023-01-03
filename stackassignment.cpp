#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10
int toCount = 0;
int StackValue = 10;
struct stack
{
    int data[MAXOFSTACK];
    int top;
};

typedef struct stack st;

// Creating Common Stack
void create_emptyStack(st *mystack)
{
    mystack->top = -1;
}

// check is stack full in Data tube
int is_stackFull(st *mystack)
{
    if (mystack->top == MAXOFSTACK - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int is_stackEmpty(st *mystack)
{
    if (mystack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push and Pop
void push(st *mystack, int value)
{
    if (is_stackFull(mystack))
    {
        printf("Stack is Full!");
    }
    else
    {
        mystack->top++;
        toCount++;
        mystack->data[mystack->top] = value;
        printf(
            "Index %d  of Stack Value is : %d\n", mystack->top, value);
    }
};
//(ii)Pop
void pop(st *mystack)
{
    if (is_stackEmpty(mystack))
    {
        printf("Stack is Empty!");
    }
    else
    {
        printf("we remove from data tube index %d of value : %d\n", mystack->top, mystack->data[mystack->top]);
        mystack->top--;
    }
}

int main()
{
    st *mystack = (st *)malloc(sizeof(st));
    create_emptyStack(mystack);

    for (int i = 0; i < MAXOFSTACK; i++)
    {
        StackValue = StackValue + 10;
        push(mystack, StackValue);
    }

    for (int i = 0; i < toCount; i++)
    {
        pop(mystack);
    }
}
