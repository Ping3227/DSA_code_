#include <stdio.h>
int main(){
	int i,j,A=0,B;
	char answer[5],comanswer[5];
	printf("Enter the answer:\n");
	scanf("%s",&comanswer);
	while(A!=4){
		A=0;
		B=0;
		printf("Please enter quess :\n");
		scanf(" %s",&answer);
		for(i=0;i<4;i++){
			if(answer[i]==comanswer[i]){
				A++;
			}
			for(j=0;j<4;j++){
				if(answer[i]!=comanswer[i]&&answer[i]==comanswer[j]){
					B++;
				}
			} 
		}
		printf("%dA%dB\n",A,B);
	
	
	}
	if(A==4){
		printf("You win!");
		return 0;
	}
	
	
	
	}

	
