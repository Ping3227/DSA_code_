#include <stdio.h>
#include <stdlib.h>

// struct for long long int
typedef struct long_long_stack
{
    long long* numbers;// dynamic memory
    int size;
} stack_num;

stack_num* construct_stack_num();
long long pop(stack_num*);
long long top(stack_num*);
void push(stack_num*,long long );
void destruct(stack_num*);


// struct for operator
typedef struct char_stack
{
    char *operation  ;// dynamic memory
    int size;
} stack_op;


stack_op* construct_stack_char();
char pop2(stack_op*);
char top2(stack_op*);
void push2(stack_op*,char );
void destruct2(stack_op*);
int empty2(stack_op*);

// global stack for saving numbers
stack_num* num;
char input[1000010];//add one
long long loop(int);
int order(char opertor1,char operator2 );
long long divide(long long a,long long b);

// int main here
int main()
{
    num = construct_stack_num();
    scanf("%[^\n]",input);
    stack_op* op = construct_stack_char();
    long long temp_num=0;
    char a=input[0];
    for(int i=0; a!='\0'; i++,a=input[i])
    {

        if('0'<=a && a<='9')
        {
            temp_num*=10;
            temp_num +=(long long)(a-'0');
            if (input[i+1]<'0'||input[i+1]>'9'){
                push(num,temp_num);
                temp_num=0;
                }
        }
        else if(a=='+'||a=='-'||a=='*'||a=='*'||a=='/'||a=='%')
        {
            while (!empty2(op)&&order(top2(op),a))
            {
                long long num2 = pop(num);
                long long num1 = pop(num);
                switch(pop2(op))
                {
                case'+':
                    push(num,num1+num2);
                    break;
                case'-':
                    push(num,num1-num2);
                    break;
                case'*':
                    push(num,num1*num2);
                    break;
                case '/':
                    push(num,divide(num1,num2));
                    break;
                case'%':
                    push(num,num1%num2);
                    break;
                }
            }
            push2(op,a);
        }
        else if (a=='(')
        {
            i=loop(++i);
        }
        else if (a=='=')
        {
            while (!empty2(op))
            {
                long long num2 = pop(num);
                long long num1 = pop(num);
                switch(pop2(op))
                {
                case'+':
                    push(num,num1+num2);
                    break;
                case'-':
                    push(num,num1-num2);
                    break;
                case'*':
                    push(num,num1*num2);
                    break;
                case '/':
                    push(num,divide(num1,num2));
                    break;
                case'%':
                    push(num,num1%num2);
                    break;

                }
            }
            printf("Print: %lld\n",top(num));

        }

    }
    destruct2(op);
    destruct(num);
}
long long  loop(int i)
{

    stack_op* op = construct_stack_char();
    long long temp_num=0;
    for(char a=input[i]; a!='\0'; i++,a=input[i])
    {

        if('0'<=a && a<='9')
        {
            temp_num*=10;
            temp_num +=(long long)(a-'0');
            if (input[i+1]<'0'||input[i+1]>'9'){
                push(num,temp_num);
                temp_num=0;
            }

        }
        else if(a=='+'||a=='-'||a=='*'||a=='*'||a=='/'||a=='%')
        {
            while (!empty2(op)&&order(top2(op),a))
            {
                long long num2 = pop(num);
                long long num1 = pop(num);
                switch(pop2(op))
                {
                case'+':
                    push(num,num1+num2);
                    break;
                case'-':
                    push(num,num1-num2);
                    break;
                case'*':
                    push(num,num1*num2);
                    break;
                case '/':
                    push(num,divide(num1,num2));
                    break;
                case'%':
                    push(num,num1%num2);
                    break;
                }
            }
            push2(op,a);
        }
        else if (a=='(')
        {
            i=loop(++i);
        }
        else if (a==')')
        {
            while (!empty2(op))
            {
                long long num2 = pop(num);
                long long num1 = pop(num);
                switch(pop2(op))
                {
                case'+':
                    push(num,num1+num2);
                    break;
                case'-':
                    push(num,num1-num2);
                    break;
                case'*':
                    push(num,num1*num2);
                    break;
                case '/':
                    push(num,divide(num1,num2));
                    break;
                case'%':
                    push(num,num1%num2);
                    break;
                }

            }
            destruct2(op);
            return i;
        }

    }

}


int order(char opertor1,char operator2 )
{
    if((opertor1=='+'||opertor1=='-')&&(operator2=='*'||operator2=='/'||operator2=='%')) return 0;
    return 1;
};


stack_num* construct_stack_num(){
    stack_num* stack_ptr= (stack_num*)malloc(sizeof (stack_num));
    stack_ptr->size=0;
    stack_ptr->numbers= (long long *)malloc(sizeof (long long)*1000000);
    return stack_ptr;
}


long long pop(stack_num* stack)
{
    if (!stack->size) return 0;
    stack->size--;
    return stack->numbers[stack->size];
};

long long top(stack_num* stack)
{
    if (!stack->size) return 0;
    return stack->numbers[stack->size-1];
};

void push(stack_num* stack,long long value)
{
    stack->numbers[stack->size]=value;
    stack->size++;
    return;
};

void destruct(stack_num* stack){
    free(stack->numbers);
    free(stack);

};

stack_op* construct_stack_char(){
    stack_op* stack_ptr= (stack_op*)malloc(sizeof (stack_op));
    stack_ptr->size=0;
    stack_ptr->operation= (char *)malloc(sizeof (char )*1000000);
    return stack_ptr;
};
char pop2(stack_op* stack){
    if (!stack->size) return 0;
    stack->size--;
    return stack->operation[stack->size];
};
char top2(stack_op* stack){
    if (!stack->size) return 0;
    return stack->operation[stack->size-1];
};
void push2(stack_op* stack,char value){
    stack->operation[stack->size]=value;
    stack->size++;
    return;
};
void destruct2(stack_op* stack){
    free(stack->operation);
    free(stack);
};
int empty2(stack_op* stack){
    return stack->size==0;
};
long long divide(long long a,long long b){
    if((a>0&&b<0)||(a<0&&b>0)){
        if(a%b!=0) return a/b-1;
    }
    return a/b;

};
