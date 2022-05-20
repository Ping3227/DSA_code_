#include <stdio.h>
#include "prime.h"
int main(){
	int a;
	scanf("%d",&a);
	
	if(prime(a))
		printf("%d is prime",a);
	
	
	return 0;
	}
