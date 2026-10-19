#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#define SIZE(A) sizeof(A)/sizeof(A[0])
struct Node{
    int data;
    struct Node *next;
};
struct list{
    struct Node *head;
};
///////////////////////////////////////////////////////////
void linkedlist_sort(struct list*);
void linkedlist_insert(struct list*,int ,int);
void linkedlist_search(struct Node**,struct list ,int);
void linkedlist_delete_val(struct list* , int);
void linkedlist_append(struct list* ,int );
void linkedlist_print(struct list* );
///////////////////////////////////////////////////////////
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
    linkedlist_delete_val(&testlist, num);
    linkedlist_print(&testlist);
    ////////////////////////////////////////////
    linkedlist_insert(&testlist, num, 4);
    printf("\nAfter insert : \n");
    linkedlist_print(&testlist);
    ////////////////////////////////////////////
    linkedlist_sort(&testlist);
    printf("\nAfter sort : \n");
    linkedlist_print(&testlist);
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
    if (base->head->data == value){
        ptr1=ptr->next;
        base->head=ptr1;
    }else{

        while(ptr->next && ptr->next->data != value)
            ptr=ptr->next;

        if (ptr->next && ptr->next->data == value){
            ptr1=ptr->next->next;
//        free(ptr->next);
            ptr->next=ptr1;
        }else {
            return;
        }

    }        
}

////////////////////////////////////////////////////////////

void linkedlist_insert(struct list*base , int value , int place){
    if (base->head == NULL){
        struct Node *ptr=malloc(sizeof(struct Node));
        base->head=ptr;
    }else{
        struct Node *ptr=base->head;
        int i;
        for (i=1 ; i<(place-1) ;i++){ // ptr allready in first value, so our loop started from '1'
            if (ptr->next)
                ptr=ptr->next;
            else
                break;
        }
        struct Node *nptr;//next ptr
        nptr=ptr->next;
        ptr->next=malloc(sizeof(struct Node));
        ptr->next->next=nptr;
        ptr->next->data=value;
        
    }
    
}

////////////////////////////////////////////////////////////

void linkedlist_sort(struct list *base){
    struct Node *ptr=base->head;
    int flag=0;
    while (ptr){
        ptr=ptr->next;
        flag++;
    }
    if (flag<2){
        return;
    }else{
        for (int i=flag ; i>1 ; i--){
            struct Node *bptr ,*aptr=base->head;
            bptr=aptr->next;

            for (int j=0 ; j<i-1 ; j++){
                if(aptr->data > bptr->data){
                    int temp=aptr->data;
                    aptr->data=bptr->data;
                    bptr->data=temp;
                }
                aptr=aptr->next;
                bptr=aptr->next;
            }
        }
    }
    
}

////////////////////////////////////////////////////////////


