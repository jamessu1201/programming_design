#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void bfs(int graph[][5],int start,int n){
    int queue[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int front=-1,rear=-1;
    int result[n],p=0;
    memset(result,0,n*sizeof(result[0]));
    queue[++rear]=start;
    visited[start]=true;
    while(front!=rear){
        int vertex=queue[++front];
        result[p++]=vertex;
        for(int i=0;i<5;i++){
            if(graph[vertex][i]==1&&visited[i]==false){
                queue[++rear]=i;
                visited[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
}

int main(){
    int graph[][5]={
    0,1,0,0,1,
    1,0,1,0,1,
    0,1,0,1,0,
    0,0,1,0,1,
    1,1,0,1,0
    };
    bfs(graph,0,5);
}