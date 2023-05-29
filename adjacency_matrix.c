#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n); //5
    int **graph=(int**)malloc(n*sizeof(int*)); //generate the matrix 
    for(int i=0;i<n;i++){
        graph[i]=(int*)malloc(n*sizeof(int));
        memset(graph[i],0,n*sizeof(graph[i]));
    }
    int a,b;
    for(int i=0;i<6;i++){  //link start
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    printf("  ");
    for(int i=0;i<n;i++){
        printf("%d ",i);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",i);
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}