#include <stdio.h>
#include <stdlib.h>
#define SIZE(A) sizeof(A)/sizeof(A[0])
struct Node{
    int data;
    struct Node *next;
};
struct list{
    struct Node *head;
};

//int search(struct list ,int);
//void delete(struct list , int);
void append(struct list* ,int );
void print_list(struct list );

int main(){
    int A[5]={10,20,30,40,50};	
    struct list testlist={.head=NULL};
    for(int i=0;i<5;i++)
        append(&testlist,A[i]);
    
    print_list(testlist);
    
    return 0;
}




void append(struct list *base , int value){
    struct Node *ptr1=base.head;
    if (!ptr1){
        struct Node *ptr=base.head;
        ptr=malloc(sizeof(struct Node));
        ptr->next=NULL;
        base.head->data=value;
        base.head->next=ptr;

    }else{
        struct Node *ptr=base.head;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=malloc(sizeof(struct Node));
        ptr->next->data=value;
        ptr->next->next=NULL;
    }
}


void print_list(struct list base){
    struct Node *ptr1=base.head;
    while(ptr1){
        printf("%d ",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("\n");
}

















