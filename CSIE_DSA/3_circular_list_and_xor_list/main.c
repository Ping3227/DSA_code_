#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// find next node
typedef struct circular_node next_line;
next_line* construct_circular_node(next_line* before,int num);
typedef struct circular_list all_bathroom;
all_bathroom* construct_circular_list(int size);
int remove_node(all_bathroom* list,int i,int size);
void destruct_n(all_bathroom *list,int size);

// XOR node function and defination
typedef struct XOR_node node;
// constructer
node* construct_node(int id);
// return xor_ptr
node * xor_ptr(node *first,node * last);

// XOR_list function and defination
typedef struct XOR_list list;

list* construct_list();
void destruct(list* target);
void push_back(list* target,int id);
void pop_front(list* target);
void pop_back(list* target);

// to save the order
typedef struct group_node group_node;
group_node * construct_group_node(int group);
// return xor_group_node
group_node *xor_group(group_node* front,group_node* back);

typedef struct group_list group_list;
group_list* construct_group_list();
void destruct_G(group_list* target);

// group search
int search_group(group_list* target,int group);

// group push pop
void push_back_G(group_list* target,int group);
void pop_front_G(group_list* target);
void pop_back_G(group_list *target);

//order
void enter();
void leave();
void go();
void close();

//cutline-close
void cutline(node * end,node *begin); // end->   ->begin

// print
void print(int target);
// initial data

// seperate save group in bathroom
list * group_of_list[1000000];   // [bathroom][group]
// save the order of group in bathroom with list
group_list* group_order[1000000];
all_bathroom *next;
int bathroom,situation,group_num;
int main(){

    char input[6];
    scanf("%d %d %d",&bathroom,&situation,&group_num);
    next=construct_circular_list(bathroom);
    // initial
    for(int i=0;i<bathroom;i++){
        for(int j=0;j<group_num;j++){
           group_of_list[i*group_num+j]=construct_list();
        }
        group_order[i]=construct_group_list();
    }

    for (int i=0;i<situation;i++){
        scanf("%s",input);
        if(!strcmp(input,"enter")){ //return 0 if same  so add !
            enter();
        }
        else if(!strcmp(input,"leave")){
            leave();
        }
        else if(!strcmp(input,"go")){
            go();
        }
        else if(!strcmp(input,"close")){
            close();
        }
    }
    for(int i=0;i<bathroom;i++){
        print(i);
        if (i!= bathroom-1) printf("\n");
    }

}


// XOR node function and defination
typedef struct XOR_node{
    struct XOR_node* nxt;
    int id;
}node;

// constructer
node* construct_node(int id){
    node *new_node= (node*)malloc(sizeof(node));
    new_node->id=id;
    new_node->nxt=NULL;
    return new_node;
}

// return xor_ptr
node * xor_ptr(node *first,node * last){
    return (node*)((int)first^(int)last);
}

// XOR_list function and defination
typedef struct XOR_list{
    node* head;
    node* tail;
    int search;
}list;

list* construct_list(){
    list *new_list=(list *)malloc(sizeof(list));
    new_list->head=new_list->tail=NULL; // cant delete
    new_list->search=0;
    return new_list;
}

void destruct(list* target){
    if(target){
        node *itr2 = target->head;  // itr2->itr1
        node * itr1=NULL;
        while(itr2){
            node *tmp =itr2;
            itr2=xor_ptr(itr2->nxt,itr1);
            itr1=tmp;
            //free(tmp);
        }
        //free(target);
    }
}
// push ,pop
void push_back(list* target,int id){
    node *Node =construct_node(id);
    if(!target->tail) target->head=target->tail=Node;
    else {
        Node->nxt=xor_ptr(target->tail,NULL);
        target->tail->nxt=xor_ptr(target->tail->nxt,Node); // (front^ NULL)^ Node = front^ Node
        target->tail=Node;
    }

}


void pop_front(list* target){

    node * deleted= target->head;
    target->head=xor_ptr(NULL,target->head->nxt);
    if(target->head) target->head->nxt=xor_ptr(deleted,target->head->nxt);  //more than one node ^deleted
    else target->tail=NULL; // if only one node
        //free(deleted);

}

void pop_back(list* target){
    node * deleted= target->tail;
    target->tail=xor_ptr(target->tail->nxt,NULL);
    if(target->tail) target->tail->nxt=xor_ptr(target->tail->nxt,deleted);  //more than one node ^deleted
    else target->head=NULL; // if only one node
        //free(deleted);


}

// to save the order
typedef struct group_node{
    int group;
    struct group_node * nxt;
}group_node;

group_node * construct_group_node(int group){
    group_node * new_node=(group_node*)malloc(sizeof(group_node));
    new_node->group=group;
    new_node->nxt=NULL;
    return new_node;
}


group_node *xor_group(group_node* front,group_node* back){
    return (group_node*)((int)front^( int)back);
}

typedef struct group_list{
    group_node* head;
    group_node* tail;
}group_list;

group_list* construct_group_list(){
    group_list * new_list=(group_list*)malloc(sizeof(group_list));
    new_list->head=new_list->tail=NULL;
    return new_list;
}
void destruct_G(group_list* target){
    if(target){
        group_node *itr2=target->head;  // itr2 <- itr1
        group_node *itr1=NULL;

        while(itr2){
            group_node *tmp =itr2;
            itr2=xor_group(itr2->nxt,itr1);// next
            itr1=tmp;
            //free(tmp);
        }
        //free(target);
    }
}


// group search
int search_group(group_list* target,int group){
    group_node *itr1=target->head;
    group_node *itr2=NULL;           // itr2-> itr1
    while(itr1){
        if(itr1->group==group) return 1;
        group_node* tmp=itr1;
        itr1=xor_group(itr2,itr1->nxt);
        itr2=tmp;
    }
    return 0;
}
// group push pop
void push_back_G(group_list* target,int group){
    group_node *Node=construct_group_node(group);
    if(!target->tail) target->head=target->tail=Node;
    else {
        Node->nxt=xor_group(target->tail,NULL);
        target->tail->nxt=xor_group(target->tail->nxt,Node); // (front^ NULL)^ Node = front^ Node
        target->tail=Node;
    }

}


void pop_front_G(group_list* target){

    group_node * deleted= target->head;
    target->head=xor_group(NULL,target->head->nxt);
    if(target->head) target->head->nxt=xor_group(deleted,target->head->nxt);  //more than one node
    else target->tail=NULL; // if only one node
    //free(deleted);


}

void pop_back_G(group_list *target){
    group_node * deleted= target->tail;
    target->tail=xor_group(target->tail->nxt,NULL);
    if(target->tail) target->tail->nxt=xor_group(target->tail->nxt,deleted);  //more than one node
    else target->head=NULL; // if only one node
        //free(deleted);

}
//order
void enter(){
    int group,id,line;

    scanf("%d %d %d",&group,&id,&line);
    int target=line*group_num+group;
    push_back(group_of_list[target],id);


    if(!group_of_list[target]->search){
        push_back_G(group_order[line],group);//if not found
        group_of_list[target]->search=1;
    }

};

void leave(){
    int line;
    scanf("%d",&line);

    int group = group_order[line]->tail->group;
    int target =line*group_num+group;
    pop_back(group_of_list[target]);
    if(!group_of_list[target]->tail) {
        pop_back_G(group_order[line]);
        group_of_list[target]->search=0;
    }


};

void go(){
    int line;
    scanf("%d",&line);

    int group = group_order[line]->head->group;
    int target =line*group_num+group;
    pop_front(group_of_list[target]);
    if(!group_of_list[target]->head) {
        pop_front_G(group_order[line]);
        group_of_list[target]->search=0;
    }

};

void close(){
    int line ;
    scanf("%d",&line);
    int newline =remove_node(next,line,bathroom);// remove and return the newline

    group_node * itr1 = group_order[line]->tail;  // itr1  <- itr2
    group_node * itr2 = NULL;
    int line_length=line*group_num;
    while(itr1){
        int group=itr1->group;
        int target1=newline*group_num+group;// move into here
        int target2=line_length+group; // move out from here

        if (group_of_list[target1]->search){ // if have this group in line
            cutline(group_of_list[target1]->tail,group_of_list[target2]->tail);
            group_of_list[target1]->tail=group_of_list[target2]->head;
        }
        else { // if not
            group_of_list[target1]->head = group_of_list[target2]->tail;
            group_of_list[target1]->tail = group_of_list[target2]->head;
            push_back_G(group_order[newline],group);
            group_of_list[target1]->search=1;
        }

        //group_of_list[target2]->tail= group_of_list[target2]->head = NULL; // for easily delete

        group_node * tmp = itr1;
        itr1 = xor_group(itr1->nxt,itr2); //next
        itr2 = tmp;
        //free(tmp);//  can only use to get next now



    }

    //group_order[line]->tail=group_order[line]->head = NULL; //every node inside have been deleted ,so set head and tail to NULL avoid from double deleted

    // destructor
    //destruct_G(group_order[line]); // delete group_order that have only head and tail =NULL
    group_order[line]= NULL;  //set it to NULL
    for(int i=0;i<group_num;i++){
        //destruct(group_of_list[i+line*group_num]);
        group_of_list[i+line_length]=NULL;
    }


};

//cutline-close
void cutline(node * end,node *begin){  // end -> begin
    end->nxt=xor_ptr(end->nxt,begin);
    begin->nxt=xor_ptr(end,begin->nxt);
}

// print
void print(int target){
    if (group_order[target]){

        group_node *itr1=group_order[target]->head;
        group_node *itr2=NULL;

        while(itr1){

            node * itr3=group_of_list[group_num*target+(itr1->group)]->head;
            node * itr4=NULL;
            while(itr3){
                printf("%d",itr3->id);
                node* tmp2=itr3;
                itr3=xor_ptr(itr4,itr3->nxt);
                if(itr3)printf(" ");
                itr4=tmp2;

            }
            group_node* tmp1=itr1;
            itr1=xor_group(itr2,itr1->nxt);
            if(itr1)printf(" ");
            itr2=tmp1;
        }
    }
}

typedef struct circular_node{
    struct circular_node* nxt;
    struct circular_node* prv;
    int num;
}next_line;

next_line* construct_circular_node(next_line* before,int num){
    next_line* new_node = (next_line* )malloc(sizeof(next_line));
    new_node->prv = before;
    new_node->num = num;
    return new_node;
}
typedef struct circular_list{
    next_line ** search_array;
}all_bathroom;


all_bathroom* construct_circular_list(int size){
    all_bathroom *new_list= (all_bathroom*)malloc(sizeof(all_bathroom));
    new_list->search_array = (next_line*)malloc(size *sizeof(next_line));
    next_line *before=NULL;
    for (int i= 0;i<size; i++){
        next_line * itr =new_list->search_array[i] = construct_circular_node(before,i);  //before -> new_node
        if (before) before->nxt = itr;// new_list->search_array[i];
        before = itr ;//new_list->search_array[i];  // iterate
    }
    new_list->search_array[0]->prv=before;
    before->nxt = new_list->search_array[0];
    return new_list;
}

int remove_node(all_bathroom* list,int i,int size){
    next_line * Node = list->search_array[i];
    next_line * return_node = Node->prv;
    Node->nxt->prv = Node->prv;
    Node->prv->nxt = Node->nxt;
    //free(Node);
    list->search_array[i] = NULL;
    return  return_node->num;
}

void destruct_n(all_bathroom *list,int size){
    for (int i=0;i<size;i++){
        //if(list->search_array[i]) free(list->search_array[i]);
    }
    //free(list);
}
