#include<stdio.h>

typedef struct{
    int a,b;
}Edge;

int main(){
    Edge edge[6];
    int n;
    char a,b;
    scanf("%d",&n); //vertex number
    for(int i=0;i<6;i++){
        scanf("%d %d",&a,&b);
        edge[i].a=a;
        edge[i].b=b;
    }
    for(int i=0;i<6;i++){
        printf("%d %d\n",edge[i].a,edge[i].b);
    }
}




