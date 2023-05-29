#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool visited[5];

void dfs(int graph[][5],int start,int n){
    int stack[n];
    int bottom=-1;
    int result[n],p=0;
    memset(result,0,n*sizeof(result[0]));
    stack[++bottom]=start;
    visited[start]=true;
    while(bottom>=0){
        int pop=stack[bottom--];
        result[p++]=pop;
        for(int i=0;i<n;i++){
            if(graph[pop][i]==1&&visited[i]==false){
                stack[++bottom]=i;
                visited[i]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
}




void dfs_recursion(int graph[][5],int vertex,int n){
    visited[vertex]=true;
    printf("%d ",vertex);
    for(int i=0;i<n;i++){
        if(graph[vertex][i]==1&&visited[i]==false){
            dfs_recursion(graph,i,n);
        }
    }
}

int main(){
    int graph[][5]={
    0,1,0,1,0,
    1,0,1,0,0,
    0,1,0,0,0,
    1,0,0,0,1,
    0,0,0,1,0
    };
    for(int i=0;i<5;i++){
        visited[i]=false;
    }
    dfs_recursion(graph,0,5);
    printf("\n");
    for(int i=0;i<5;i++){
        visited[i]=false;
    }
    dfs(graph,0,5);
}