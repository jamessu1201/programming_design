#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int top=-1;
int capacity=1;

bool is_full(int *stack){
    return top>=capacity;
}

bool is_empty(int *stack){
    return top==0;
}

void stack_full(int *stack){
    int* new_stack = (int*)realloc(stack, capacity*2*sizeof(int));
    if(!new_stack){  //分配失敗
        perror("overflow");
    }
    stack = new_stack;
}

int size(int *stack){
    return top;
}

int now_top(int *stack){
    return stack[top];
}

void push(int *stack,int value){
    if(is_full(stack)){
        stack_full(stack);
    }
    stack[++top]=value;
}

int pop(int *stack){
    if(is_empty(stack)){
        printf("is empty.\n");
        return -999;
    }
    return stack[top--];
}

int main(){
    int *stack=(int*)malloc(capacity*sizeof(int));

    char move[10],*ptr;
	int movement;
	
	while(gets(move)){
		if(!strcmp(move,"pop")){
			int out=pop(stack);
			if(out>=0) printf("poped %d\n",out);
		}else if(!strcmp(move,"size")){
			printf("%d\n",size(stack));
		}else if(!strcmp(move,"isempty")){
			if(is_empty(stack)){
				printf("isempty.\n");
			}else{
				printf("not empty.\n");
			}
		}else if(!strcmp(move,"top")){
			if(is_empty(stack)){
				printf("isempty.\n");
			}else{
				printf("top is %d\n",now_top(stack));
			}
		}else{
			ptr=strtok(move," ");
			if(strcmp(ptr,"push")){
				printf("wrong instruction.\n");
				continue;
			}
			ptr=strtok(NULL," ");
			movement=atoi(ptr);
			push(stack,movement);
		}
	}
}