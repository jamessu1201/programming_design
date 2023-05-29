#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Queue{
	int val;
	struct Queue *next;
	struct Queue *prev;
}Queue;


bool is_empty(Queue *rear,Queue *front){
	if(rear->next==front){
		return true;
	}
	return false;
}

void print(Queue *rear,Queue *front){
	Queue *search=rear->next;
	while(search!=front){
		printf("%d ",search->val);
		search=search->next;
	}
	printf("\n");	
}

int size(Queue *rear,Queue *front){
	int count=0;
	Queue *search=rear->next;
	while(search!=front){
		count++;
		search=search->next;
	}
	return count;
}

void enqueue(Queue *rear,Queue *front,int val){
	Queue *new=(Queue*)malloc(sizeof(Queue));
	new->val=val;
	new->next=rear->next;
	rear->next=new;
	new->prev=rear;
	new->next->prev=new;
	printf("enqueued %d\n",val);
}

int dequeue(Queue *rear,Queue *front){
	if(is_empty(rear,front)){
		printf("isempty.\n");
		return -1;
	}
	Queue *remove=front->prev;
	int val=remove->val;
	front->prev=remove->prev;
	front->prev->next=front;
	free(remove);
	remove=NULL;
	return val;
}




int main(){
	Queue *rear=(Queue*)malloc(sizeof(Queue));
	Queue *front=(Queue*)malloc(sizeof(Queue));
	rear->next=front;
	front->prev=rear;

	char move[10],*ptr;
	int movement;
	
	while(gets(move)){
		if(!strcmp(move,"dequeue")){
			int out=dequeue(rear,front);
			if(out>=0) printf("get %d\n",out);
		}else if(!strcmp(move,"print")){
			print(rear,front);
		}else if(!strcmp(move,"size")){
			printf("%d\n",size(rear,front));
		}else if(!strcmp(move,"isempty")){
			if(is_empty(rear,front)){
				printf("isempty.\n");
			}else{
				printf("not empty.\n");
			}
		}else{
			ptr=strtok(move," ");
			if(strcmp(ptr,"enqueue")){
				printf("wrong instruction.\n");
				continue;
			}
			ptr=strtok(NULL," ");
			movement=atoi(ptr);
			enqueue(rear,front,movement);
		}
	}
}
