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
		puts("i :插入");
		puts("l :列出");
		puts("s :存檔");
		puts("o :讀檔");
		puts("q :結束");
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
				
					printf("姓名  :%s\n",p[i].name);	
					printf("電話  :%d\n",p[i].lv);
					printf("email :%s\n\n",p[i].hp);
					}
				break;
				
			case 's':
				printf("請輸入檔名(.txt):");
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
				printf("請輸入檔名(.txt):");
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
