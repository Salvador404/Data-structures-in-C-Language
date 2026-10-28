#include <cstdio>
#include <stdio.h>
#include <time.h>



#define SIZE(A) sizeof(A)/sizeof(A[0])
///////////////////////////////////////////////////////
void create_arr(int *,size_t);
///////////////////////////////////////////////////////

struct Node {
    int data;
    struct Node *next;
};

struct clist {
    struct Node *end;
};

////////////////////////////////////////////////////////
int
main(){
    int A[10];
    create_arr(A,sizeof(A)/sizeof(A[0]));
    struct clist testlist={.end=NULL};
    for (int i=0;i<SIZE(A);i++)
        
    /////////////////////////////////////////
    
    /////////////////////////////////////////
    return 0;
}
///////////////////////////////////////////////////////

void create_arr(int *ptr , size_t s){
        for (int i=0;i<s;i++){
            struct timespec t;
            clock_gettime(CLOCK_REALTIME,&t);
            *(ptr+i)=(t.tv_nsec%10);
           }
}

///////////////////////////////////////////////////////
void clist_append(struct clist *base,int value){
    struct Node *ptr=base->end;
    if(!ptr){
        ptr=malloc(sizeof(struct Node));
        ptr->data=value;
        ptr->next=ptr;
        base->end=ptr;
        return;
    }
    else{
        struct Node *trace=base->end;
        while(ptr->next == base->end)
        
    }
}








