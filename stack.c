#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 10

typedef struct stack{
	int val;
	struct stack *up;
}Stack;

Stack *top;

int now_top(Stack *bottom){
	return top->val;
}

int size(Stack *bottom){
	int count=0;
	Stack *search=bottom->up;
	while(search!=NULL){
		count++;
		search=search->up;
	}
	return count;
}

bool is_full(Stack *bottom){
	if(size(bottom)==MAX){
		return true;
	}
	return false;
}

bool is_empty(Stack *bottom){
	if(bottom->up==NULL){
		return true;
	}
	return false;
}

void print(Stack *bottom){
	Stack *search=bottom->up;
	while(search!=NULL){
		printf("%d ",search->val);
		search=search->up;
	}
	printf("\n");	
}

void push(Stack *bottom,int val){
	if(is_full(bottom)){
		printf("isfull.\n");
		return;
	}
	Stack *insert=bottom;
	while(insert->up!=NULL){
		insert=insert->up;
	}
	Stack *new=(Stack*)malloc(sizeof(Stack));
	new->up=NULL;
	new->val=val;
	insert->up=new;
	printf("insert %d.\n",val); 
}

int pop(Stack *bottom){
	if(is_empty(bottom)){
		printf("isempty.\n");
		return -1;
	}
	Stack *last=bottom;
	Stack *remove=bottom->up;
	while(remove->up!=NULL){
		last=remove;
		remove=remove->up;
	}
	int remove_val=remove->val;
	free(remove);
	remove=NULL;
	last->up=NULL;
	return remove_val;
}

int main(){
	Stack *bottom=(Stack*)malloc(sizeof(Stack));
	bottom->up=NULL;
	char move[10],*ptr;
	int movement;
	

	while(gets(move)){
		if(!strcmp(move,"pop")){
			int out=pop(bottom);
			if(out>=0) printf("poped %d\n",out);
		}else if(!strcmp(move,"print")){
			print(bottom);
		}else if(!strcmp(move,"size")){
			printf("%d\n",size(bottom));
		}else if(!strcmp(move,"isempty")){
			if(is_empty(bottom)){
				printf("isempty.\n");
			}else{
				printf("not empty.\n");
			}
		}else if(!strcmp(move,"top")){
			if(is_empty(bottom)){
				printf("isempty.\n");
			}else{
				printf("top is %d\n",now_top(bottom));
			}
		}else{
			ptr=strtok(move," ");
			if(strcmp(ptr,"push")){
				printf("wrong instruction.\n");
				continue;
			}
			ptr=strtok(NULL," ");
			movement=atoi(ptr);
			push(bottom,movement);
		}
	}
	
} 
