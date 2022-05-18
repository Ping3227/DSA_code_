#include <stdio.h>
#include <string.h>
char input[10000000];
int len;
int KMP[20000000];
int KMP1();
int KMP2();
int main(){

    scanf("%s",input);
    len =strlen(input);
    int a=KMP1(); //add front
    int b=KMP2(); // add back
    if(a==b){
        if(a!=len){// print front
            printf("%d\n",len-a);
            for (int i=0;i<len-a;i++){
                printf("%c",input[len-1-i]);
            }

            printf("%s",input);

            //print back

            printf("\n");

            printf("%s",input);

            for (int i=b;i<len;i++){
                printf("%c",input[len-1-i]);
            }
        }
        else {
            printf("0\n%s",input);
        }

    }
    else if(a>b){
        printf("%d\n",len-a);
         for (int i=0;i<len-a;i++){
            printf("%c",input[len-1-i]);
        }
        printf("%s",input);

    }
        else {
            printf("%d\n",len-b);

            printf("%s",input);

            for (int i=b;i<len;i++){
                printf("%c",input[len-1-i]);
            }
        }



}

int KMP1(){

     // initail + reverse  add at front
    KMP[0]=0;
    if(input[len-1]==input[0]) KMP[len]=1;
    else KMP[len]=0;

    int k=0;

    //inital
    for(int i=1;i<len;i++){
        while(k>0&& input[k]!=input[i]) k=KMP[k-1];
        if (input[k]==input[i]) k++;
        KMP[i]=k;
    }
    // reverse
    if(input[len-1]==input[0]) k=1;
    else k=0;
    for(int i=1;i<len;i++){
        while(k>0&& input[k]!=input[len-1-i]) k=KMP[k-1];
        if (input[k]==input[len-1-i]) k++;
        KMP[i+len]=k;
    }
    return KMP[2*len-1];
};

int KMP2(){
    //reverse+ initial  add at back
    int k=0;

    //inital
    for(int i=1;i<len;i++){
        while(k>0&& input[len-1-k]!=input[len-1-i]) k=KMP[k-1];
        if (input[len-1-k]==input[len-1-i]) k++;
        KMP[i]=k;
    }
    // reverse
    if(input[len-1]==input[0]) k=1;
    else k=0;
    for(int i=1;i<len;i++){
        while(k>0&& input[len-1-k]!=input[i]) k=KMP[k-1];
        if (input[len-1-k]==input[i]) k++;
        KMP[i+len]=k;
    }
    return KMP[2*len-1];
};
