#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	int *ptr=(int *)malloc(5*sizeof(int));
	printf("%p\n",ptr);
	for(i=0;i<5;i++){
		scanf("%d",&ptr[i]);
	} 
	int *new_ptr=(int *)realloc(ptr,10*sizeof(int));
	if(new_ptr==NULL){
		perror("overflow");
	}
	ptr=new_ptr;
	printf("%p\n",ptr);
	for(i=0;i<5;i++){
		printf("%3d",ptr[i]);
	}		
	printf("\n");
	free(ptr);
	return 0;
}







