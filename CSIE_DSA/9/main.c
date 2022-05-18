#include <stdio.h>
#include <string.h>

int k,l,flag;
char str[1000001];
typedef struct rabinkarp{
    int num; // record the input order of value
    long long Rk_value;
    long long real_value;
} rabinkarp;

rabinkarp value[1000000];

long long count2;
long long total;
long long repeat;
rabinkarp result [1000000];
void merge(int ,int );
void mergesort(int ,int );
int compare(int, int);// used while RK are same


int main(){
    scanf("%d %d %d",&k,&l,&flag);
    for (int i=0;i<k;i++){
       scanf("%s",str+i*l);

    }


         // situtation 0. find one pair
    if(flag==0){
        if(l==1){//speical case:
            if(k==1) printf("No");
            else printf("Yes\n%d %d",0,1);
            return 0;
        }

        long long d =1;
        for(int i=0 ;i<k;i++){
            long long rk_value = 0 ;
            //take 5 for example   0 4 3 2 1 ->  1 0 4 3 2 -> 2 1 0 4 3-> 3 2 1 0 4 -> 4 3 2 1 0
            for(int j=1;j<l;j++){
                rk_value *=127;
                rk_value += str[l*i+j];
                rk_value %=7262497666814783;

            }

            value[i].Rk_value = rk_value;
            value[i].num=i;

        }

        for(int i=0;i<l-2;i++){
            d=d*127%7262497666814783;
        }
        mergesort(0,k-1);
        for(int i=0;i<k-1;i++){
            int nxt =i+1;

            while(nxt!=k &&value[i].Rk_value == value[nxt].Rk_value){
                if(compare(value[i].num,value[nxt].num)){ //test Rk_value first then compare ture data
                    printf("Yes\n%d %d",value[i].num, value[nxt].num);
                    return 0;
                }
                nxt++;
            }

        }

        for(int i=0;i<l-1;i++){
            for(int j=0;j<k;j++){
                value[j].Rk_value-=(str[l*value[j].num+i+1]*d%7262497666814783); //68507
                if(value[j].Rk_value<0) value[j].Rk_value+=7262497666814783;
                value[j].Rk_value*=127;
                value[j].Rk_value+=str[value[j].num*l+i];
                value[j].Rk_value%=7262497666814783;
            }
            mergesort(0,k-1);


            for(int m=0;m<k-1;m++){

                int nxt =m+1;
                while(nxt!=k &&value[m].Rk_value == value[nxt].Rk_value){
                    if(compare(value[m].num,value[nxt].num)){ //test Rk_value first then compare ture data
                        printf("Yes\n%d %d",value[m].num, value[nxt].num);
                        return 0;
                    }
                    nxt++;
                }
            }

        }
        printf("No");
        return 0;

    }   // situtation 1. find how many pair
    else {
        if(l==1){//speical case:
            total=(long long)k*(long long)(k-1);
            if(k==1) printf("No");
            else printf("Yes\n%lld",total/2);
            return 0;
            // speical case l = 1
        }
        long long d =1;
        for(int i=0 ;i<k;i++){
            long long rk_value = 0 ;
            long long RL_value=str[l*i];
            //take 5 for example   0 4 3 2 1 ->  1 0 4 3 2 -> 2 1 0 4 3-> 3 2 1 0 4 -> 4 3 2 1 0
            for(int j=1;j<l;j++){
                rk_value *=127;
                rk_value += str[l*i+j];
                rk_value %=7262497666814783;
            }
            value[i].Rk_value = rk_value;
            value[i].num=i;
            value[i].real_value=RL_value;
             // correct

        }
        for(int i=0;i<l-2;i++){
            d=d*127%7262497666814783;
        }


        mergesort(0,k-1);
        long long count=1;
        long long count3=1;
        long long tmp_value=value[0].Rk_value;
        long long tmp_rl=value[0].real_value;
        for(int i=1;i<k;i++){


            if(tmp_value!=value[i].Rk_value){
                    tmp_value=value[i].Rk_value;
                    total+=count*(count-1);
                    count=1;
                    tmp_rl=value[i].real_value;
                    repeat+=count3*(count3-1);
                    count3=1;
            }
            else{
                if(tmp_rl!=value[i].real_value){
                    tmp_rl=value[i].real_value;
                    repeat+=count3*(count3-1);
                    count3=1;
                }
                else count3++;
                count++;
            }

        }
        repeat+=count3*(count3-1);
        total+=count*(count-1);


        for(int i=0;i<l-1;i++){
            for(int j=0;j<k;j++){
                value[j].Rk_value-=(str[l*value[j].num+i+1]*d%7262497666814783); //68507
                if(value[j].Rk_value<0) value[j].Rk_value+=7262497666814783;
                value[j].Rk_value*=127;
                value[j].Rk_value+=str[value[j].num*l+i];
                value[j].Rk_value%=7262497666814783;

            }
            mergesort(0,k-1);
            count=1;
            tmp_value=value[0].Rk_value;
            for(int m=1;m<k;m++){

                 if(tmp_value!=value[m].Rk_value){
                    tmp_value=value[m].Rk_value;
                    total+=count*(count-1);
                    count=1;
                }
                else count++;

            }
            total+=count*(count-1);
        }


        total-=repeat*(l-1);
        total/=2;
        if(total==0) printf("No");
        else  printf("Yes\n%lld",total);

    }


}

void mergesort(int start ,int end){
    if (start == end ) return ;

    mergesort(start,(start+end)/2);

    mergesort((start+end)/2+1,end);

    merge(start,end);
};

void merge(int start ,int end){
    int L_index =start; // start -> mid -1
    int mid =(start+end)/2+1 ;
    int R_index= mid ; // mid -> end
    int index=0;
    // fill result array  until one is full
    while(L_index < mid && R_index <= end ){
        if(value[L_index].Rk_value < value[R_index].Rk_value){

            result[index++]=value[L_index];

            L_index++;

        }
        else if (value[L_index].Rk_value == value[R_index].Rk_value){
            if(value[L_index].real_value<value[R_index].real_value){
                result[index++]=value[L_index];
                L_index++;
            }
            else{

                result[index++] = value[R_index];

                R_index++;
            }


        }
        else {

            result[index++] = value[R_index];

            R_index++;
        }

    }

    while(L_index<mid){
        result[index++]= value[L_index];
        L_index++;

    }
    while(R_index <= end){
        result[index++] = value[R_index];
        R_index++;
    }
    // copy result to rabin karp
    for(int i =0 ; i< index;i++){

        value[start+i] = result[i];

    }

};

int compare(int a, int b){ // compare all the element in str
                       // if more than one are same return false
    int count=0;
    for(int i=0;i<l;i++){
        if(str[a*l+i]!=str[b*l+i]) count++;
        if(count>=2) return 0;
    }
    if(count==0) count2++;//if totally same
    return 1;
};


