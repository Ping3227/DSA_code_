#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct disjointSet{
    // TODO: Determine fields to use by your method
    int ptr;  // point on other element's hash
    int size;

} DisjointSet;

DisjointSet ds[1 << 24]; // point on the set
bool set[1 << 24] = {}; // the element

int c2i(char c) { // char to int
    if ('0' <= c && c <= '9') return c - '0';
    else if ('a' <= c && c <= 'z') return c - 'a' + 10;
    else if ('A' <= c && c <= 'Z') return c - 'A' + 36;
    return -1;
}

int hash(const char* s) {
    int ret = 0;
    int mask = (1<<24)-1;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        ret = mask & (ret << 4) | c2i(s[i]);
    return ret;
}

void makeset(const char* s){
    // TODO: Initialize a set with hash value
    ds[hash(s)].ptr = 0 ; //initial as point on 0
    ds[hash(s)].size =1;  // initial size as 1
}

inline void static init(const char* s) {
    int i = hash(s);
    if (!set[i]) {
        makeset(s);
        set[i] = 1;
    }
}

int find(int a){
    if(ds[a].ptr == 0) return a ;
    else return ds[a].ptr = find(ds[a].ptr);
};

int find_set(const char* s) { // return hash here
    init(s);
    int i = hash(s);
    // TODO: Implement your find algorithm here
    if(ds[i].ptr==0 ) return i;
    else return ds[i].ptr = find(ds[i].ptr); // compress
}

void group(const char *ra, const char *rb) {
    int a = find_set(ra), b = find_set(rb);
    if(a == b) return ;
    // TODO: Implement your union algorithm here
    if(ds[a].size>ds[b].size){
        ds[b].ptr=a;  // set a point on set b
        ds[a].size+=ds[b].size;
        ds[b].size=0;
    }
    else {
        ds[a].ptr=b;  // set b point on set a
        ds[b].size+=ds[a].size;
        ds[a].size=0;
    }

}

bool same_set(const char*a, const char* b) {
    // TODO: Implement your algorithm here
    return (find_set(a) == find_set(b));
}



int N;
const char a[13],b[13],order[6];

int main() {
    // TODO: Implement your algorithm here

    scanf("%d",&N);

    for(int i =0 ;i<N ;i++){

        scanf("%s",order);
        scanf("%s %s",a,b);
        if(!strcmp(order,"test")){ // order == test
            if(same_set(a,b)) printf("Positive\n");
            else printf ("Negative\n");
        }
        else{ // order == group
            group(a,b);
        }



    }


}
