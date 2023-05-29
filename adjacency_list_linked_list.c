#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Vertex{
    int vertex;
    struct Vertex *next;
}Vertex;

void add_edge(Vertex *graph[],int a,int b){
    Vertex *tmp=graph[a];
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    Vertex *new=(Vertex*)malloc(sizeof(Vertex));
    tmp->next=new;
    new->next=NULL;
    new->vertex=b;
}

int main(){
    int n;
    scanf("%d",&n); //5
    Vertex *graph[n]; //vertexs lists
    for(int i=0;i<n;i++){   //the head is vertex itself
        graph[i]=(Vertex*)malloc(sizeof(Vertex));
        graph[i]->vertex=i;
        graph[i]->next=NULL;
    }
    int a,b;
    for(int i=0;i<6;i++){ //link start
        scanf("%d %d",&a,&b);
        add_edge(graph,a,b);
        add_edge(graph,b,a);
    }
    for(int i=0;i<n;i++){
        Vertex *tmp=graph[i];
        while(tmp!=NULL){
            printf("%d ",tmp->vertex);
            tmp=tmp->next;
        }
        printf("\n");
    }
}