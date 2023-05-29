#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n); //5
    int **graph=(int**)malloc(n*sizeof(int*)); //how many lists
    for(int i=0;i<n;i++){
        graph[i]=(int*)malloc(10*sizeof(int)); //most linked edge that vertex can have
        memset(graph[i],0,n*sizeof(graph[i]));
    }
    int *size=(int*)malloc(n*sizeof(int)); //every list's size
    memset(size,0,n*sizeof(size));
    int a,b;
    for(int i=0;i<6;i++){  //link start
        scanf("%d %d",&a,&b);
        graph[a][size[a]++]=b;
        graph[b][size[b]++]=a;
    }
    for(int i=0;i<n;i++){
        printf("%d ",i);
        for(int j=0;j<size[i];j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    
}