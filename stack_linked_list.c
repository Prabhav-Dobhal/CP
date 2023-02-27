#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *nxt;
}ll;

ll* push(ll* head)
{
    ll* new_node;
    new_node=(ll*)malloc(sizeof(ll));
    printf("Enter data to push: ");
    scanf("%d",&new_node->data);
    new_node->nxt=NULL;
    if(head==NULL)return new_node;
    new_node->nxt=head;
    head=new_node;
    return head;
}

ll* pop(ll* head)
{
    if(head==NULL){
        printf("stack is empty\n");
        return;
    }
    ll* temp;
    temp=head;
    head=head->nxt;
    free(temp);
    return head;
}

void peek(ll *head)
{
    if(head==NULL)printf("stack is empty\n");
    else printf("%d\n",head->data);
}

void print(ll* head)
{
    if(head==NULL){
        printf("stack is empty\n");
        return;
    }
    ll* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("\n");
}

int main()
{
    ll* head=NULL;
    int ch;
    do{
        printf("enter \n1 to push \n2 to pop \n3 to peek \n4 to print \n0 to exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=push(head);
                break;
            case 2:
                head=pop(head);
                break;
            case 3:
                peek(head);
                break;
            case 4:
                print(head);
                break;
            default:
                printf("Wrong Input\n");
        }
    }
    while(ch);
}