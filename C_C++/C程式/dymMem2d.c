#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	int i,j,a,b;
	int **p;
	float sum=0,total=0;
	
	scanf("%d %d",&a,&b);
	
	p=(int**)malloc(sizeof(int*)*a);
	for(i=0;i<a;i++){
		p[i]=(int*)malloc(sizeof(int)*b);
		
		for(j=0;j<b;j++){
			scanf("%d",&p[i][j]);
			total+=p[i][j];
			}
		}
		
	for(i=0;i<a;i++){
		sum=0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN);
		printf("class ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
		printf("%d\n",i+1);
		
		for(j=0;j<b;j++){
			printf("%d: %d\n",j+1,p[i][j]);
			sum+=p[i][j];
			
			}
		free(p[i]);
		
		printf("sum: %.0f\n",sum);
		printf("avg: %.2f\n",sum/b);
		}
	printf("total: %.0f,avg: %.2f",total,total/(a*b));
	
	free(p);
	
	return 0;
	}


	
