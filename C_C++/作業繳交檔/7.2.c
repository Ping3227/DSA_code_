#include <stdio.h>

struct Pokemon{
	char name[100];
	int lv;
	char hp[100];
	};

int main(){
	
	struct Pokemon p[50];
	int i;
	int n=0;
	char op;
	char str[100];
	FILE *f1;
	
		
	while(1){
		puts("i :���J");
		puts("l :�C�X");
		puts("s :�s��");
		puts("o :Ū��");
		puts("q :����");
		puts(">");
		scanf(" %c",&op);
		switch(op){
			case 'i':
				scanf("%s",&p[n].name);	
				scanf("%d",&p[n].lv);
				scanf("%s",&p[n].hp);
				n++;
				break;
				
			case 'l':
				for(i=0;i<n;i++){
				
					printf("�m�W  :%s\n",p[i].name);	
					printf("�q��  :%d\n",p[i].lv);
					printf("email :%s\n\n",p[i].hp);
					}
				break;
				
			case 's':
				printf("�п�J�ɦW(.txt):");
				scanf("%s",&str);
				
				f1 = fopen(str,"w");
				fprintf(f1,"%d\n",n);
				for(i=0;i<n;i++){
					fprintf(f1,"%s\n",p[i].name);
					fprintf(f1,"%d\n",p[i].lv);
					fprintf(f1,"%s\n\n",p[i].hp);
					}
				
				break;
				
			case 'o':
				printf("�п�J�ɦW(.txt):");
				scanf("%s",&str); 
				f1= fopen(str,"r");
				fscanf(f1,"%d\n",&n);
				for(i=0; i<n; i++){
					fscanf(f1,"%s",&p[i].name);
					fscanf(f1,"%d",&p[i].lv);
					fscanf(f1,"%s",&p[i].hp);
					}
				
				break;
				
			case 'q':
				return 0;
			}
		system("pause");
		system("cls");
		}
	return 0;
	}
