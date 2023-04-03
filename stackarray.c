#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_STACK_SIZE 10

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item);
int is_full();
element pop();
int is_empty();

int main(void)
{
	srand(time(NULL));
	printf("-----Using array-----\n");
	for (int i = 1; i <= 30; i++)
	{
		int rand_num = rand() % 100 + 1;
		
		if (rand_num % 2 == 0)
		{
			push(rand_num);
			printf("[ %d ] Push %d\n", i, rand_num);
		}
		if (rand_num % 2 == 1)
		{
			printf("[ %d ] Pop %d\n", i, pop());
		}
	}
	return 0;
}

void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else stack[++top] = item;
}

int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "Stack Empty!\n");

		return stack[top] = -1;
	}
	else
	{
		return stack[top--];
	}
}

int is_empty()
{
	return (top == -1);
}