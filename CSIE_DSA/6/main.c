#include <stdio.h>
#include <memory.h>

int return_num[1000000],prev[1000000],find[1000000];
int num,query,capital,sort,city1,city2,query_num;

typedef struct node node;
typedef struct list list;
void push_back(int ,int );
list * construct_list();
node * construct_node(int );

void mark(int start);
void filled1(int,int);
void filled2(int,int);

list* relation[1000000];

int main(){
    scanf("%d %d %d %d",&num,&query,&capital,&sort);
    // construct the road
    for(int i=0;i<num;i++){
        relation[i]=NULL;
        find[i]=0;
    }
    for(int j=0;j<num-1;j++){
        scanf("%d %d",&city1,&city2);
        push_back(city1-1,city2-1);
        push_back(city2-1,city1-1);
    }
    //search 1.find_road between from central to sort
    //       2.set the return num

    mark(capital);

    filled1(sort,capital);// problem might be here

    //query here
    for(int i=0;i<query;i++){
        scanf("%d",&query_num);
        printf("%d\n",return_num[query_num-1]);
    }
};

typedef struct node{
    int num;
    struct node* nxt;
}node;

typedef struct list {
    node* head;
    node* tail;
}list;

void push_back(int to,int target){
    node* ptr=construct_node(target);
    if(!relation[to]) {
        relation[to]=construct_list();
        relation[to]->head=ptr;
    }
    if(relation[to]->tail) relation[to]->tail->nxt=ptr;
    relation[to]->tail=ptr;
    return ;
};

list * construct_list(){
    list* ptr=(list*)malloc(sizeof(list));
    ptr->head=ptr->tail=NULL;
    return ptr;
};
node * construct_node(int num){
    node * ptr=(node*)malloc(sizeof(node));
    ptr->nxt=NULL;
    ptr->num=num;
    return ptr;
};



void mark(int start){  //DFS
    find[start-1]=1;// been founded
    node* ptr=relation[start-1]->head;

    while(ptr){

        if(find[ptr->num]!=1) {// not travel yet
            prev[ptr->num]=start;
            mark(ptr->num+1);
        }
        ptr=ptr->nxt;
    }
    return ;
}

void filled1(int start,int end){//input initial
    if(start==end){
        for (int i=0;i<num;i++){
            return_num[i]=start;
        }
        return;
    }
    int itr=prev[start-1];
    find[start-1]=2;
    return_num[start-1]=start;

    //printf("num %d: %d \n",start,return_num[start-1]);

    // sort
    node* ptr=relation[start-1]->head;
    //printf("before loop1\n");
    while(ptr){

        if(ptr->num!=itr-1) filled2(start,ptr->num+1);

        ptr=ptr->nxt;
    }


    while(1){
        return_num[itr-1]=itr;
        find[itr-1]=2;

        if(itr==end)break;


        //iterate
        start=itr;
        //middle
        ptr=relation[start-1]->head;
        itr=prev[start-1];

        while(ptr){

            if(ptr->num!=itr-1&&find[ptr->num]!=2) filled2(start,ptr->num+1);

            ptr=ptr->nxt;
        }

    }





    // capital
    ptr=relation[itr-1]->head;

    while(ptr){
        if(ptr->num!=start-1) filled2(itr,ptr->num+1);
        ptr=ptr->nxt;
    }
    return;
}

void filled2(int fill_num,int start){
    find[start-1]=2;
    node* ptr=relation[start-1]->head;
    return_num[start-1]=fill_num;

    while(ptr){
        if(find[ptr->num]!=2) filled2(fill_num,ptr->num+1);
        ptr=ptr->nxt;
    }
    return ;
};
