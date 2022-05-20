#include "prime.h" 
#include <stdio.h>
int prime(int n){
	int i,fct=0;
	for(i=0;i<n;i++){
		if(n%(i+1)==0){
			fct++;
			} 
		}
	if(fct==2){
		return 1;
		}
	else{
		return 0;
		}
			
	}
