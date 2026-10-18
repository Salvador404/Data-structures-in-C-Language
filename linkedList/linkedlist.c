#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE(A) sizeof(A)/sizeof(A[0])
struct Node{
    int data;
    struct Node *next;
};
struct list{
    struct Node *head;
};

void linkedlist_search(struct Node**,struct list ,int);
void linkedlist_delete_val(struct list* , int);
void linkedlist_append(struct list* ,int );
void linkedlist_print(struct list* );

int main(){
    int A[5]={10,20,30,40,50};	
    struct list testlist={.head=NULL};
    for(int i=0;i<5;i++)
        linkedlist_append(&testlist,A[i]);
    ////////////////////////////////////////////
    linkedlist_print(&testlist);
    ////////////////////////////////////////////
    int num;
    printf("\nenter a number : ");
    scanf("%d",&num);
    struct Node *check=NULL;
    linkedlist_search(&check, testlist, num);
    if(check==NULL)
        printf("\nNot found!!\n");
    else
        printf("\nFounded!!\n");
    ////////////////////////////////////////////


    return 0;
}


////////////////////////////////////////////////////////////

void linkedlist_append(struct list *base , int value){
    struct Node *ptr1=base->head;
    if (!ptr1){
        struct Node *ptr=base->head;
        ptr=malloc(sizeof(struct Node));
        ptr->next=NULL;
        ptr->data=value;
        base->head=ptr;

    }else{
        struct Node *ptr=base->head;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=malloc(sizeof(struct Node));
        ptr->next->data=value;
        ptr->next->next=NULL;
    }
}

/////////////////////////////////////////////////////////////

void linkedlist_print(struct list *base){
    struct Node *ptr1=base->head;
    while(ptr1){
        printf("%d ",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("\n");
}


////////////////////////////////////////////////////////////

void linkedlist_search(struct Node **ptr,struct list base,int value){
    struct Node *sptr=base.head;
    while(sptr->data != value && sptr->next)
        sptr=sptr->next;
    if (sptr->data == value)
        *ptr=sptr;
}

////////////////////////////////////////////////////////////

void linkedlist_delete_val(struct list *base,int value){
    struct Node *ptr1,*ptr =base->head;
    
    while(ptr->next && ptr->next->data != value)
        ptr=ptr->next;
    if (ptr->data == value)
        ptr1=ptr->next->next;
        free(ptr->next);
        ptr->next=ptr1;

}

////////////////////////////////////////////////////////////










