#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *nxt;
}cll;


cll* add(cll *head)
{
    int pos,posbtw;
    cll* temp;
    printf("Enter\n1 to add in starting\n2 to add at middle\n3 to add in last: ");
    scanf("%d",&pos);
    cll* new_node;
    new_node=(cll*)malloc(sizeof(cll));
    printf("Enter data to add: ");
    scanf("%d",&new_node->data);
    new_node->nxt=new_node;
    if(head==NULL)return new_node;
    switch(pos){
        case 1:
            new_node->nxt=head;
            temp=head;
            while(temp->nxt!=head)temp=temp->nxt;
            temp->nxt=new_node;
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
            temp->nxt=new_node;
            break;
        case 3:
            temp=head;
            while(temp->nxt!=head)temp=temp->nxt;
            temp->nxt=new_node;
            new_node->nxt=head;
            break;
        default:
            printf("------------------Wrong Input-----------\n");
    }
    return head;
}

void search(cll* head)
{
    cll *temp=head;
    int key;
    printf("enter element to search: ");
    scanf("%d",&key);
    while(temp->nxt!=head)
    {
        if(temp->data==key){
            printf("element present\n");
            return;
        }
        temp=temp->nxt;
    }
    if(temp->data==key){
        printf("element is present\n");
        return;
    }
    printf("element not present\n");
}

cll* delete(cll* head)
{
    cll* temp=head;
    cll* prev;
    int key;
    printf("enter the element to delete: ");
    scanf("%d",&key);    
    if(head->data==key){
        temp=head;
        while(temp->nxt!=head)temp=temp->nxt;
        head=head->nxt;
        temp->nxt=head;
        return head;
    }
    while(temp!=NULL){
        if(temp->data==key){
            if(temp->nxt==head)prev->nxt=head;
            else prev->nxt=temp->nxt;
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->nxt;
    }
    printf("element not present\n");
}

void print(cll *head)
{
    cll* temp=head;
    while(temp->nxt!=head)
    {
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("%d",temp->data);
    printf("\n");
}

int main()
{
    cll *head=NULL;
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