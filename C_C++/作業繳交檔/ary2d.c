#include <stdio.h>
int main(){
	int i,j,total=0;
	int score1[5],score2[5],score3[5];
	float sum,avg,totalavg,highestavg = 0;
	for (i=0;i<5;i++){
		scanf("%d %d %d",&score1[i],&score2[i],&score3[i]);
		sum = (score1[i]+score2[i]+score3[i]);
		avg = sum/3;
		if(avg>highestavg){
			highestavg = avg;
			j=i;
			}
		
		total+=sum;
		}
	for (i=0;i<5;i++){
		printf("student %d\n",i+1);
		printf("1: %d\n",score1[i]);
		printf("2: %d\n",score2[i]);
		printf("2: %d\n",score3[i]);
		printf("sum: %d\n",score1[i]+score2[i]+score3[i]);
		sum = (score1[i]+score2[i]+score3[i]);
		avg = sum/3;
		printf("avg: %.2f\n",avg);
		
		} 
	sum =total;
	totalavg= sum/15;
	printf("total: %d, avg: %.2f\n",total,totalavg);
	printf("highest avg: student %d: %.2f",j+1,highestavg);
	return 0;
	}

	
