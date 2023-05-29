#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int rear=-1;
int front=-1;
int capacity=1;

bool is_full(int *queue){
    return rear>=capacity;
}

bool is_empty(int *queue){
    return rear==front;
}

void queue_full(int *queue){
    int* new_queue = (int*)realloc(queue, capacity*2*sizeof(int));
    if(!new_queue){  //分配失敗
        perror("overflow");
    }
    queue = new_queue;
}

int size(int *queue){
    return rear-front;
}

int now_front(int *queue){
    return queue[front+1];
}

void enqueue(int *queue,int value){
    if(is_full(queue)){
        queue_full(queue);
    }
    queue[++rear]=value;
}

int dequeue(int *queue){
    if(is_empty(queue)){
        return -999;
    }
    return queue[++front];
}

int main(){
    int *queue=(int*)malloc(capacity*sizeof(int));

    char move[10],*ptr;
	int movement;
	
	while(gets(move)){
		if(!strcmp(move,"dequeue")){
			int out=dequeue(queue);
			if(out>=0) printf("get %d\n",out);
            else printf("isempty.\n");
		}else if(!strcmp(move,"size")){
			printf("%d\n",size(queue));
		}else if(!strcmp(move,"isempty")){
			if(is_empty(queue)){
				printf("isempty.\n");
			}else{
				printf("not empty.\n");
			}
		}else if(!strcmp(move,"front")){
            if(is_empty(queue)){
				printf("isempty.\n");
			}else{
				printf("front is %d\n",now_front(queue));
			}
        }else{
			ptr=strtok(move," ");
			if(strcmp(ptr,"enqueue")){
				printf("wrong instruction.\n");
				continue;
			}
			ptr=strtok(NULL," ");
			movement=atoi(ptr);
			enqueue(queue,movement);
		}
	}
}