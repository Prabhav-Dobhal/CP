#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *prev,*nxt;
}dll;


dll* add(dll *head)
{
    int pos,posbtw;
    dll* temp;
    printf("Enter\n1 to add in starting\n2 to add at middle\n3 to add in last: ");
    scanf("%d",&pos);
    dll* new_node;
    new_node=(dll*)malloc(sizeof(dll));
    printf("Enter data to add: ");
    scanf("%d",&new_node->data);
    new_node->nxt=NULL;
    new_node->prev=NULL;
    if(head==NULL)return new_node;
    switch(pos){
        case 1:
            new_node->nxt=head;
            head=new_node;
            break;
        case 2:
            printf("enter the position: ");
            scanf("%d",&posbtw);
            posbtw--;
            int count=1;
            temp=head;
            while(count!=posbtw){
                temp=temp->nxt;
                count++;
            }
            new_node->nxt=temp->nxt;
            new_node->prev=temp;
            temp->nxt=new_node;
            break;
        case 3:
            temp=head;
            while(temp->nxt!=NULL)temp=temp->nxt;
            temp->nxt=new_node;
            new_node->prev=temp;
            break;
        default:
            printf("------------------Wrong Input-----------\n");
    }
    return head;
}

void search(dll* head)
{
    dll *temp=head;
    int key;
    printf("enter element to search: ");
    scanf("%d",&key);
    while(temp!=NULL)
    {
        if(temp->data==key){
            printf("element present\n");
            return;
        }
        temp=temp->nxt;
    }
    printf("element not present\n");
}

dll* delete(dll* head)
{
    dll* temp=head;
    dll* previ;
    int key;
    printf("enter the element to delete: ");
    scanf("%d",&key);    
    if(head->data==key){
        head=head->nxt;
        head->prev=NULL;
        free(temp);
        return head;
    }
    while(temp!=NULL){
        if(temp->data==key){
            if(temp->nxt==NULL)previ->nxt=NULL;
            else{
                previ->nxt=temp->nxt;
                temp->nxt->prev=previ;
            }
            free(temp);
            return head;
        }
        previ=temp;
        temp=temp->nxt;
    }
    printf("element not present\n");
}

void print(dll *head)
{
    dll* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("\n");
}

int main()
{
    dll *head=NULL;
    int ch;
    do{
        printf("enter \n1 to add\n2 to delete\n3 to search \n4 to print\n0 to exit: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                head=add(head);
                break;
            case 2:
                head=delete(head);
                break;
            case 3:
                search(head);
                break;
            case 4:
                print(head);
                break;
            default:
                printf("--------------Wrong Input--------------\n");
                
        }
    }
    while(ch);
}