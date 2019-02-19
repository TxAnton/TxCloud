#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct node{
	int n;
	struct node *next;
};
struct stack{
	struct node *top;
};

struct node* newNode(int n){
	struct node* el = malloc(sizeof(struct node));
	el->n = n;
	el->next = NULL;
	return el;
}
struct stack* newStack(){
	struct stack* stack = malloc(sizeof(struct stack));
	stack->top  = NULL;
	return stack;
}

void push(struct stack* stack, int el){
	struct node* node = newNode(el);
	node->next = stack->top;
	stack->top = node;
}

int pop(struct stack* stack){
	if(stack->top){
		struct node* top = stack->top;
		stack->top = (stack->top)->next;
		int n = top->n;
		free(top);
		return n;
	}
	else return 0;
}
int top(struct stack* stack){
	if(stack->top)
		return stack->top->n;
	else
		return 0;
}

size_t count(struct stack* stack){
	struct node* node = stack->top;
	size_t i = 0;
	while(node){
		node = node->next;
		i++;
	}
	return i;
}

int isEmpty(struct stack* stack){
	return count(stack) == 0;
}

int main()
{
	struct stack* stack = newStack();
	char cmd[4];
	int n;
	while(1){
		scanf("%s", cmd);
		if(strstr(cmd,"push")){
			scanf(" %d\n", &n);
			push(stack, n);
			printf("ok\n"); 
		} else if(strstr(cmd,"pop")){
			if(isEmpty(stack)){
				printf("error");
				return 0;
			}
			else{
				int n = pop(stack);
				printf("%d\n", n);
			}
		} else if(strstr(cmd,"top")){
			if(isEmpty(stack)){
				printf("error");
				return 0;
			}
			else{
				int n = top(stack);
				printf("%d\n", n);
			}
			

		} else if(strstr(cmd,"size")){
			printf("%d\n", count(stack));
		} else if(strstr(cmd,"exit")){
			printf("bye");
			return 0;
		}
	}
	return 0;
}
