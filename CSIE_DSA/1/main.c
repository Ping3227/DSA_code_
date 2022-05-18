#include<stdio.h>
#include<string.h>

void stoi(int *,char *);
void Binary_Algorithm(int* ,int* ,int*);
void output(int *);

void swap(int*,int*);
int compare(int*,int*);

void multiple(int* ,int *);
void multiple2(int *);
void divide2(int *);
void minus(int*,int *);

int exist(int *);

char char_a[512],char_b[512];
int int_a[128],int_b[128],ans[128]; // one index store 4 decimal
int main()
{
    scanf("%s %s",char_a,char_b);

    stoi(int_a,char_a);
    stoi(int_b,char_b);

    Binary_Algorithm(int_a ,int_b ,ans);


    output(ans);
}


void stoi(int *Int,char * Char){
    int length=strlen(Char);
    int i=length-1,j=1,k=127,total=0;
    memset(Int,0,sizeof(int)*128);
    while (i>=0){
        total+=(Char[i--]-'0')*j;
        j*=10;
        if(j==10000){
            j=1;
            Int[k--]=total;
            total=0;
        }
    }
    if (total!=0){
        Int[k]=total;
    }


};


void Binary_Algorithm(int* a,int*b ,int* ans){
    memset(ans,0,sizeof(int)*128);
    ans[127]=1;

    while(exist(a) && exist(b)){//need fixed

        if(a[127]%2==0 && b[127]%2==0){
            multiple2(ans);
            divide2(a);
            divide2(b);
        }
        else if (b[127]%2==0) divide2(b);
        else if (a[127]%2==0) divide2(a);
        if (!compare(a,b)){
            swap(a,b);
        }
        minus(a,b);

    }

    multiple(ans,b);

};

void output(int *a){
    int find=0;
    for(int i=0;i<128;i++){
        if(find==1) {
            if(a[i]/1000>0)printf("%d",a[i]);
            else if (a[i]/100>0)printf("0%d",a[i]%1000);
            else if (a[i]/10>0)printf("00%d",a[i]%100);
            else printf("000%d",a[i]%10);
        }
        if(a[i]!=0&&find==0) {
            printf("%d",a[i]);

            find =1;
        }

    }
};

void swap(int* a,int*b){
    int replace;
    for(int i=0;i<128;i++){
        replace= a[i];
        a[i]=b[i];
        b[i]=replace;
    }
};

int compare(int*a,int*b){
    for(int i=0;i<128;i++){
        if(a[i]>b[i]) return 1;
        if(b[i]>a[i]) return 0;
    }
};


void multiple(int* a,int *b){
    int c[128];
    int i=1;

    memset(c,0,sizeof(int)*128);
    for(int i=127;i>=0;i--){
        if(a[i]==0) continue;
        for (int j=127;j>=0;j--){
            c[i+j-127]+=a[i]*b[j];
        }
    }

    int carry=0;
    for (int i=127;i>=0;i--){
        c[i]=c[i]+carry;
        carry=c[i]/10000;
        c[i]%=10000;
    }
    swap(a,c);
};

void multiple2(int *a){
    int carry=0;
    for(int i=127;i>=0;i--){
        a[i]=a[i]*2+carry;
        carry=a[i]/10000;
        a[i]%=10000;

    }
};

void divide2(int *a){
    for(int i=127;i>=0;i--){
        if (a[i]%2==1) a[i+1]+=5000;
        a[i]/=2;
    }
};

void minus(int*a,int *b){
    for(int i=127;i>=0;i--){
        a[i]-=b[i];
        if (a[i]<0){
            a[i]+=10000;
            a[i-1]-=1;
        }

    }
};

int exist(int * a){
    for (int i=0;i<128;i++){
        if(a[i]) return 1;
    }
    return 0;
};
