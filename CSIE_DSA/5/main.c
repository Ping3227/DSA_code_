#include "price.h"
// heap NA-> N per time
// heap A -> remember the index  2N+1-> 3N+1   add 2N+1->3N each time  need a special case
// with index array show 2N+1

unsigned long long sorted_array[1001024];
unsigned long long num_heap[2100000];
int A_heap[1024];  //A
int A_index[1024];

int size;// for heap
int A_size;// for A heap
int kth;
unsigned long long new_stock;


void swap(int a,int b);
void insert(unsigned long long num);
unsigned long long pop();
void heapify(int);
void buildheap();

//need
unsigned long long A_price(int);
void A_swap(int ,int );
void A_insert(int);
int  A_pop();
void A_heapify(int);
void A_buildheap();

void push_in(unsigned long long ,int );
// need a output function dealt with the ....

int A,Q,N;
unsigned long long stock[1024];

int main(){
    scanf("%d %d %d",&A,&Q,&N);
    for (int i=0;i<A;i++){// enter stocks
        scanf("%llu",&stock[i]);

        //initaialize

        for(int j=0;j<2*N;j++){
            num_heap[i*2*N+j]= price(stock[i],j+1);//function here  f(stock[i],j);
        }
        A_index[i]=2*N+1;
        A_heap[i]=i;   // initaialize as 0->A-1
    }
    size=A*2*N;
    //heapfiy

    buildheap();

    A_size=A;

    A_buildheap();// A_buildheap();



    //make sorted array  klog(NA)
    int k=0;
    unsigned long long before;
    while(1){
        for (int j=0;j<N;j++){ // for int k to k

            sorted_array[N*k+j]=pop(); // pop N element
            //printf("%d %llu ",N*k+j+1,sorted_array[N*k+j]);
            //printf("%d\n",sorted_array[N*k+j]<before);
            //before=sorted_array[N*k+j];
        }
        k++;
        if(k*N>1000001) break;
        // insert N to num_heap

        int stock_num = A_pop();

        push_in(stock[stock_num],A_index[stock_num]);// insert kN+1->kN+N to heap

        A_index[stock_num]+=N;//kN+1->(K+1)N+1

        A_insert(stock_num);

        // insert back A_heap

    }


    // output
    for(int i=0;i<Q;i++){
        scanf("%llu %d",&new_stock,&kth);
        printf("%llu\n",sorted_array[kth-1]);
    }



}

void swap(int a,int b){
    unsigned long long tmp =num_heap[a];
    num_heap[a]=num_heap[b];
    num_heap[b]=tmp;
    return;
}


void insert(unsigned long long num){
    size++;
    num_heap[size-1]=num;

    //sort
    int current=size-1;
    int parent=(size-2)/2;
    while(1){
        if(num_heap[current]<num_heap[parent]) {

            swap(current,parent);
            current=parent;
            if(current==0) break;
            parent= (current-1)/2;
        }
        else break;
    }

};

unsigned long long pop(){
    size--;
    unsigned long long tmp = num_heap[0];
    num_heap[0]=num_heap[size];

    //sort
    heapify(0);
    return tmp;
}


void heapify(int index){

	int left = index*2+1;
	int right = left + 1;
	int min = index;
	if(left<size&&num_heap[left]<num_heap[min]){
		min = left;
	}
	if(right<size&& num_heap[right]<num_heap[min]){
		min = right;
	}
	if(min != index){
		swap(index,min);
		heapify(min); // resort the subtree of min
	}

};

void buildheap(){
    // size-1 = last
	for(int i=((size-2)/2);i>=0;i--){
		heapify(i);
	}
}

unsigned long long  A_price(int num){ // input num -> stock_num -> stock price
    return price((unsigned long long)stock[A_heap[num]],
                (unsigned long long)A_index[A_heap[num]]);
};

void A_swap(int a,int b){
    int tmp =A_heap[a];
    A_heap[a]=A_heap[b];
    A_heap[b]=tmp;
    return;
};

void A_insert(int num){
    A_size++;
    A_heap[A_size-1]=num;

    //sort
    int current=A_size-1;
    int parent=(A_size-2)/2;
    while(1){

        if(A_price(current)<A_price(parent)) {

            A_swap(current,parent);
            current=parent;
            if(current==0) break;
            parent= (current-1)/2;
        }
        else break;
    }
};

int A_pop(){
    A_size--;
    int tmp =A_heap[0];
    A_heap[0]=A_heap[A_size];

    //sort
    A_heapify(0);
    return tmp;
};

void A_heapify(int index){
    int left = index*2+1;
	int right = left + 1;
	int min = index;

	if(left<A_size&&A_price(left)<A_price(min)){
		min = left;
	}
	if(right<A_size&&A_price(right)<A_price(min)){
		min = right;
	}

	if(min != index){
		A_swap(index,min);
		A_heapify(min); // resort the subtree of min
	}
};


void A_buildheap(){
     // size-1 = last
	for(int i=((A_size-2)/2);i>=0;i--){
		A_heapify(i);
	}
};

void push_in(unsigned long long stock_num,int num){
    for(int i=0;i<N;i++){
        insert(price(stock_num,(unsigned long long) (num+i)));//function (stock_num,int_num+i)

    }
};




