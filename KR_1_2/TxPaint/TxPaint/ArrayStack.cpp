#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define CMPZ(a,b) ((a)>(b)?1:(a)==(b)?0:-1)
#define OPEN "([{<"
#define CLOSE ")]}>"
#define BLOCK 1000
#define NUM 50
#define BM 1000000

typedef int TYPE;

struct stack{
	size_t size;
	TYPE* arr;
	TYPE* top;
};


struct stack* newStack(){
	struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
	stack->size  = BLOCK;
	stack->arr = stack->top = (TYPE*)malloc(BLOCK * sizeof(TYPE));
	return stack;
}

void push(struct stack* stack, TYPE el){
	if( (++(stack->top) - stack->arr)/sizeof(char) > stack->size){
		size_t tmp = stack->top - stack->arr;
		stack->arr = (TYPE*)realloc(stack->arr, stack->size + BLOCK*sizeof(char));
		stack->size += BLOCK;
		stack->top = stack->arr + tmp;
	}
	*(stack->top) = el;
}

char pop(struct stack* stack){
	if(stack->top - stack->arr){
		return *(stack->top--); 
	}
	else return 0;
}
char top(struct stack* stack){
	if(stack->top - stack->arr){
		return *(stack->top);
	}
	else return 0;
}

size_t count(struct stack* stack){
	return stack->top - stack->arr;
}

int isEmpty(struct stack* stack){
	return count(stack) == 0;
}

int main()
{
	struct stack* stack = newStack();
	clock_t start = clock();
	for(int i = 0; i< BM; i++){
		for(int j = 0; j< NUM; j++){
			push(stack, j);
		}
		for(int j = 0; j< NUM; j++){
			pop(stack);
		}
	}
	printf("%d", clock()-start);
	getchar();
	
	/*
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
	*/
	
	return 0;
}
