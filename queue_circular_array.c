#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 5

int size(int *queue);

int rear=-1;
int front=-1;
int capacity=MAX_LENGTH;

bool is_full(int *queue){
    return size(queue)>=capacity-1;
}

bool is_empty(int *queue){
    return rear==front;
}


int size(int *queue){
    return (rear-front+capacity) % capacity;
}

int now_front(int *queue){
    return queue[(front+1)>=capacity?0:front+1];
}

void enqueue(int *queue,int value){
    if(is_full(queue)){
        printf("queue full!\n");
        return;
    }
    queue[(rear+1)>=capacity?0:++rear]=value;
}

int dequeue(int *queue){
    if(is_empty(queue)){
        return -999;
    }
    return queue[(front+1)>=capacity?0:++front];
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