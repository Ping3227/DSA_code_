#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int N; //shops 
int M; //days
char input[6];
int output[1000000];//query num
int output_order = 0;// show query order

typedef struct list_node {
    struct list_node* nxt;
    int num; //which num pointing on 
}list_Node;

typedef struct list {
    list_Node* head;
}List;

typedef struct disjointSet {
    struct disjointSet* ptr; // NULL
    int size; //1
    
} DisjointSet;

DisjointSet* ds[1000001]; // point on the set 
// set return mainpulate point 
DisjointSet* find_set(DisjointSet* num) {
    
    while (num->ptr != NULL) {
        num = num->ptr;
    }
    return num;

}

typedef struct node {
    List* nxt; //point around 
    int order;// 0 query 1 boom  2 makeset
    DisjointSet* a, * b; // if makeset then record which two ; if query then record order a be inset onto b insert
    int searched; // show searched or not
    int change;
}Node;

Node* node_ptr[1000001];//ptr point on node to build graph fast
int total = 0;
// set group
void group(DisjointSet* num1, DisjointSet* num2, Node* cur) {
    num1 = find_set(num1);
    num2 = find_set(num2);
    if (num2 == num1) {
        cur->order = 1;//invalid this node 
        return;
    } // if in same group 
    cur->change=0;
    if (num1->size >= num2->size) {
        num2->ptr = num1;
        cur->a = num1;
        cur->b = num2;
        if (num1->size == num2->size){
            num1->size++;  // same height than height add one 
            cur->change++;

        }
    }
    else {
        num1->ptr = num2;
        cur->a = num2;
        cur->b = num1;

    }
    total--;
}

//push into list 
void push(int num1, int num2) {
    // num2 to num1
    list_Node * next =node_ptr[num1]->nxt->head;
    node_ptr[num1]->nxt->head=(list_Node*)malloc(sizeof(list_Node));
    node_ptr[num1]->nxt->head->nxt=next;
    node_ptr[num1]->nxt->head->num = num2;
}

void delete(List * list){
    list_Node *deleted=list->head;
    list->head=deleted->nxt;
    free(deleted);
    
};

void solve1(Node* a) {
    if(a->searched==1) return ;
    if (a->order == 0) {//query 
        output[a->change] = total;//!!!!!!!
    }
    if (a->order == 2) {//makeset 
        group(a->a, a->b, a);
    }
    

};
void slove2(Node* a){
    if (a->searched==0) solve1(a);
    if (a->order == 2) {//come back to this one degroup
        a->b->ptr = NULL;
        a->a->size -= a->change;
        total++;
    }
}


int main() {
    scanf("%d %d", &N, &M);
    total=N;
    for (int i = 0; i <= M; i++) { // node 0 is inital status  
        node_ptr[i] = (Node*)malloc(sizeof(Node));
        node_ptr[i]->nxt = (List*)malloc(sizeof(List));
        node_ptr[i]->nxt->head = NULL;
        node_ptr[i]->searched = 0;

    }

    for (int i = 1; i <= N; i++) { //1-N
        ds[i] = (DisjointSet*)malloc(sizeof(DisjointSet));
        ds[i]->ptr = NULL;
        ds[i]->size = 1;
       


    }


    int cur = 0;  //node 0

    for (int i = 1; i <= M; i++) {    // build up the graph
        scanf("%s", input);
        if (strcmp(input, "merge") == 0) { // merge

            // graph
            push(cur, i);
            push(i, cur);
            //need to check DisjointSet first if inside already return 0
            int tar1, tar2;
            scanf("%d %d", &tar1, &tar2);
            node_ptr[i]->order = 2;
            node_ptr[i]->a = ds[tar1];
            node_ptr[i]->b = ds[tar2];

        }
        else if (strcmp(input, "query") == 0) {// query
            push(cur, i);
            push(i, cur);
            node_ptr[i]->order = 0;
            node_ptr[i]->change = output_order++;// query order

        }
        else {  // boom
            //scan new place 
            scanf("%d", &cur);
            //graph
            push(cur, i);
            push(i, cur);
            node_ptr[i]->order = 1;
            //

        }
        cur = i;
    }
    node_ptr[0]->order=1;//invalid order 1 

    //DFS
    Node * itr2;
    Node * itr=node_ptr[0];
    
   
    while(itr->nxt->head!=NULL){
        
        if(node_ptr[itr->nxt->head->num]->searched==0) {
            solve1(itr);
            
            itr->searched=1;
            itr2=itr;
            itr=node_ptr[itr->nxt->head->num];
            delete(itr2->nxt);
        }
        else{
            slove2(itr);
            
            itr->searched=2;
            itr2=itr;
            itr=node_ptr[itr->nxt->head->num];
            delete(itr2->nxt);
        }
    }
    
    for (int i = 0; i < output_order; i++) {//final output
        printf("%d\n", output[i]);
    }


}

