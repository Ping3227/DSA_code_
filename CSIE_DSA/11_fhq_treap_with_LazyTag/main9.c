#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    unsigned long priority;
    struct Node *left,*right;
    int size;   // size how mant nod below(include itself)
    long long value,total; 
    int reverse;//1 true 0 false
    long long max,max2;//use to solve 5 
    int cnt;// how many max in this interval 
    int max_tag;
}node;

typedef struct pair{
    node * first;
    node * second;
}pair;//use to return node 

node * init(long long value){
    
    node* new=(node *)malloc(sizeof(node));
    
    new->priority=rand();
    
    new->left=new->right=NULL;
    new->cnt=new->size=1;
    new->max=new->total=new->value=value;
    new->max2=0;
    new->max_tag=new->reverse=0;
    
    return new;
}

typedef struct Treap{
    node * root;
}treap;

treap *tp;
int N;// machine 
int Q;//line
long long tim;

void update(node * root){
    root->total= root->value;
    root->size = 1;
    if(root->left!=NULL){
        root->total+= root->left->total;
        root->size += root->left->size;
        
        
        if( root->value > root->left->max){
            root->max = root->value;
            root->cnt = 1;
            root->max2 = root->left->max;
        }
        else if(root->value == root->left->max){
            root->max=root->value;
            root->cnt = root->left->cnt+1;
            root->max2 = root->left->max2;
        }
        else{
            root->max=root->left->max;
            root->cnt=root->left->cnt;
            // decide root->max2 between max and lft max2
            if (root->value > root->left->max2) root->max2=root->value;
            else root->max2=root->left->max2;
        }
        
    }
    else{
        root->max=root->value;
        root->max2=0;
        root->cnt=1;
    }
    
    
    if(root->right!=NULL){
        root->total+= root->right->total;
        root->size += root->right->size;
        
        if( root->max > root->right->max){
            //root->max same 
            // cnt same
            //decide root->max2
            if(root->max2 < root->right->max) root->max2=root->right->max;
        }
        else if(root->max == root->right->max){
            //root->max same
            root->cnt += root->right->cnt;
            //decide root->max2
            if(root->max2 < root->right->max2) root->max2 = root->right->max2;
        }
        else{
            root->max=root->right->max;
            root->cnt=root->right->cnt;
            // decide root->max2 between max and right max2
            if (root->max > root->right->max2) root->max2=root->max;
            else root->max2=root->right->max2;
            
        }
        
    }
    
};

void to_k(node *root,long long k){
    if(root==NULL) return ;
    if(root->max<=k) {
        return;
    }
    if(root->left!=NULL){
        if(root->left->max>k){
            if(root->left->max2 >= k) to_k(root->left,k); //recursive
            else{ //max_tag  // between max and max2
                root->left->max_tag=k;
                root->left->total-=(root->left->max - k)*(root->left->cnt);
                root->left->max=k; 
                // rnt same as initial
                // max2 same  
            }
        } 
    }
    if(root->value >k ) root->value=k;
    if(root->right!=NULL){
        if(root->right->max>k){
            if(root->right->max2 >= k)to_k(root->right,k);
            else{ // max_tag;
                root->right->max_tag=k;
                root->right->total-=(root->right->max-k)*(root->right->cnt);
                root->right->max=k; 
                // rnt same as initial
                // max2 same  
            }
        }
    }
    root->max_tag=0;
    update(root);
};

void push_down(node * root){
    //reverse part
    node * lft= root->left,* rgt=root->right;
    root->right=lft; root->left=rgt; // swap
    
    if (lft!=NULL){
        if(lft->reverse==1) lft->reverse=0;
        else lft->reverse=1;
       
    }
    
    
    if (rgt!=NULL){
        if( rgt->reverse==1)  rgt->reverse=0;
        else rgt->reverse=1;
        
    }
    
    root->reverse=0;
    
    
};

pair split(node * root,int order){ // let left side has only order
    pair return_pair;
    if (root==NULL) {
        return_pair.first=return_pair.second=NULL;
        return return_pair;   
    }
    if(root->reverse==1) push_down(root);
    
    if(root->max_tag!=0) to_k(root,root->max_tag);
    
    if(root->left==NULL){
        if(0<order){ //need to sort right only
            return_pair=split(root->right,order-1);
            root->right=return_pair.first;
            return_pair.first=root;
            
        }else{
            return_pair= split(root->left,order);
            root->left=return_pair.second;
            return_pair.second=root;
            
        }
    }
    else{
        if(root->left->size <order){ //need to sort right only
            return_pair=split(root->right,order-root->left->size-1);
            root->right=return_pair.first;
            return_pair.first=root;
        }else{
            
            return_pair=split(root->left,order);
            root->left=return_pair.second;
            return_pair.second=root;
        }
    }
    
    update(root);
    
    return return_pair;
};


node* merge(node * n1,node* n2){ // must follow n1<n2
    if(n1==NULL)return n2;
    if(n2==NULL) return n1;
    
    if(n1->priority > n2->priority){ // use n1 as root 
        
        if(n1->reverse==1) push_down(n1);
        if(n1->max_tag!=0) to_k(n1,n1->max_tag);
        n1->right=merge(n1->right,n2);
        update(n1);
        return n1;
    }
    else{
        if(n2->reverse==1) push_down(n2);
        if(n2->max_tag!=0) to_k(n2,n2->max_tag);
        n2->left=merge(n1,n2->left);
        update(n2);
        return n2;
    }
    
};

void insert(int k,long long value){
    
    node * lft,*rgt;
    
    pair return_pair =split(tp->root,k);
    
    lft=return_pair.first;
    rgt=return_pair.second;
    node *new = init(value);
    
    tp->root=merge(merge(lft,new),rgt);
    
   
};


void delete(int k){
    node * lft,*tar,*rgt;
    
    pair return_pair=split(tp->root,k); // split out the  fist k 
    lft=return_pair.first;
    rgt=return_pair.second;
    
    return_pair=split(lft,k-1);//split out k 
    lft=return_pair.first;
    tar=return_pair.second;
    
    free(tar);
    tar=NULL;
    tp->root =merge(lft,rgt); //left target right
};

void insrtuct_6(int from, int to){
    node *lft,*tar,*rgt;
    pair return_pair=split(tp->root,to);
    lft=return_pair.first;
    rgt=return_pair.second;
    
    return_pair=split(lft,from-1);
    lft=return_pair.first;
    tar=return_pair.second;
    printf("%lld\n",tar->total);
    tp->root=merge(merge(lft,tar),rgt);
    
};



void insrtuct_5(int from,int end,long long tim){
    node *lft,*tar,*rgt;
    pair return_pair=split(tp->root,end);
    lft=return_pair.first;
    rgt=return_pair.second;
    
    return_pair=split(lft,from-1);
    lft=return_pair.first;
    tar=return_pair.second;
    
    to_k(tar,tim);
    
    
    tp->root=merge(merge(lft,tar),rgt);
    
};


void swith(int from1,int to1,int from2,int to2){
    node *area1,*area2,*area3,*area4,*area5;
    
    pair return_pair=split(tp->root,to2);
    area4=return_pair.first;
    area5=return_pair.second;
    
    return_pair=split(area4,from2-1);
    area3=return_pair.first;
    area4=return_pair.second;
    
    return_pair=split(area3,to1);
    area2=return_pair.first;
    area3=return_pair.second;
    
    return_pair=split(area2,from1-1);
    area1=return_pair.first;
    area2=return_pair.second;
    tp->root=merge(merge(merge(merge(area1,area4),area3),area2),area5);
};


void insrtuct_3(int from,int to ){
    node *lft,*tar,*rgt;
   
    pair return_pair=split(tp->root,to);
    lft=return_pair.first;
    rgt=return_pair.second;
    
    return_pair=split(lft,from-1);
    lft=return_pair.first;
    tar=return_pair.second;
    
    if(tar->reverse==1) tar->reverse=0;
    else tar->reverse=1;
    
    tp->root=merge(merge(lft,tar),rgt);
    
};



int main(){
    
    tp=(treap*)malloc(sizeof(treap));
    tp->root=NULL;
    scanf("%d %d",&N,&Q);
    
    for (int i=0;i<N;i++){
        scanf("%lld",&tim);
        
        insert(i,tim);
        
    }
    int insrtuct;
    int r1,r2,p;
    long long k;
    for (int i=0;i<Q;i++){
        scanf("%d",&insrtuct);
        switch ( insrtuct ){
            case 1: // insert on p,k
                scanf("%d %lld",&p,&k);
                insert(p,k);
                break;
            case 2: //discard p
                scanf("%d",&p);
                delete(p);
                break;
            case 3: // reverse l to r 
                scanf("%d %d",&r1,&r2);
                insrtuct_3(r1, r2);
                break;
            case 4: // swith l to r and x to y
                scanf("%d %d %d %lld",&r1,&r2,&p,&k);
                if (r1<p) swith(r1,r2,p,k);
                else swith(p,k,r1,r2);
                break;
            case 5:  // update  l->r to at least k 
                scanf("%d %d %lld",&r1,&r2,&k);
                insrtuct_5(r1,r2,k);
                break;
            case 6: // print total
                scanf("%d %d",&r1,&r2);
                insrtuct_6(r1,r2);
                break;
            
        
        }
    }
}