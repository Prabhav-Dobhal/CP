#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *nxt;
}ll;

ll* enqueue(ll** front,ll* back)
{
    ll* new_node;
    new_node=(ll*)malloc(sizeof(ll));
    printf("Enter data to push: ");
    scanf("%d",&new_node->data);
    new_node->nxt=NULL;
    if(*front==NULL){
        *front=new_node;
        return new_node;
    }
    while(back->nxt!=NULL)back=back->nxt;
    back->nxt=new_node;
    back=new_node;
    return back;
}

ll* dequeue(ll* front,ll** back)
{
    if(front==NULL){
        printf("queue is empty\n");
        return NULL;
    }
    if(front==*back)
    {
        *back=front=NULL;
        return front;
    }
    ll* temp=front;
    front=front->nxt;
    free(temp);
    return front;
}

void Front(ll *front)
{
    if(front==NULL)printf("queue is empty\n");
    else printf("%d\n",front->data);
}

void print(ll* front,ll* back)
{
    if(front==NULL){
        printf("queue is empty\n");
        return;
    }
    ll* temp=front;
    while(temp!=back){
        printf("%d ",temp->data);
        temp=temp->nxt;
    }
    printf("%d ",temp->data);
    printf("\n");
}

int main()
{
    ll *front=NULL,*back=NULL;
    int ch;
    do{
        printf("enter \n1 to enqueue \n2 to dequeue \n3 to check front element \n4 to print \n0 to exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                back=enqueue(&front,back);
                break;
            case 2:
                front=dequeue(front,&back);
                break;
            case 3:
                Front(front);
                break;
            case 4:
                print(front,back);
                break;
            default:
                printf("Wrong Input\n");
        }
    }
    while(ch);
}