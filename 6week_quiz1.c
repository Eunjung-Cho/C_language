/*
�迭�� �̿��Ͽ� stack �����ϱ�
������
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1; //top�� �ʱⰪ�� ������ ������� �� -1 (�������), �׻� ������ ����Ű�� ������ ũ��� ����.
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) { //������ ���� �� �ִ��� �˻��ϴ� �Լ�
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) { //������ ����ִ��� �˻��ϴ� �Լ�
    return stack->top == -1;
}

void push(Stack* stack, int item) { //���ÿ� ������ ����
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) //���ÿ��� �����͸� �����Ͽ� ��ȯ
{
    if (stack->top > -1) { //���ÿ��� �������� �ִ� ���� -1�ʰ� (=������ �ƴϰ� ���� �ִٸ�)        
        int idx = stack->array[stack->top--]; //�迭���� top�� �ִ� ����
        return idx;
    }
    else // �� ������ ���ó�� -9999�ֱ�
        return -9999;
}


int peek(Stack* stack) //�������� ����� ��Ҹ� ��ȯ�ϵ� �������� �ʴ´�.
{
    int idx;
    idx = stack->top;
    return stack->array[idx];
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}
