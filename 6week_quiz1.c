/*
배열를 이용하여 stack 구현하기
조은정
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
    stack->top = -1; //top의 초기값은 스택이 비어있을 때 -1 (공백상태), 항상 맨위를 가리키며 스택의 크기와 같다.
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) { //스택이 가득 차 있는지 검사하는 함수
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) { //스택이 비어있는지 검사하는 함수
    return stack->top == -1;
}

void push(Stack* stack, int item) { //스택에 데이터 삽입
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) //스택에서 데이터를 삭제하여 반환
{
    if (stack->top > -1) { //스택에서 제일위에 있는 값이 -1초과 (=공백이 아니고 값이 있다면)        
        int idx = stack->array[stack->top--]; //배열에서 top에 있는 감소
        return idx;
    }
    else // 다 뺏으면 결과처럼 -9999넣기
        return -9999;
}


int peek(Stack* stack) //마지막에 저장된 요소를 반환하되 삭제하지 않는다.
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
