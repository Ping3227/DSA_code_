#include <stdio.h>
#include <stdlib.h> 
int main(){
	int a; 
	int *score; 
	int i,j,highest=0;
	float b;
	 
	scanf("%d",&a); 
	score=(int*)malloc(sizeof(int)*a);
	 
	for (i=0;i<a;i++){
		scanf("%d",&score[i]);
		b+= score[i];
		} 
	
	printf("avg = %.2f\n",b/3);
	printf("fail:\n");
	
	for (i=0;i<a;i++){
		if(score[i]<60){
			printf("%d: %d\n",i+1,score[i]);
			} 
		if(score[i]>highest){
			highest =score[i];
			j=i;
			}
		}
		
	printf("highest:\n%d: %d",j+1,highest);
			 
	free(score); 
	score = NULL; 
	return 0;
	}


	
