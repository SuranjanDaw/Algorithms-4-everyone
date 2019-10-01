#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

struct node {
  int num;
  node* link;
};

node* push(node* head, int num)
{
  if(head != NULL)
  {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->num = num;
    ptr->link = head;
    head = ptr;
    return head;
  } else{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->num = num;
    ptr->link = NULL;
    return ptr;
  }
}

node* pop(node *head)
{
  if(head != NULL)
  {
    int num = head->num;
    node* ptr = head;
    head = head->link;
    free(ptr);
    return head;
  } else {
    return NULL;
  }
}

void display(node* head)
{
  while(head != NULL)
  {
    printf("%d-->",head->num );
    head = head->link;
  }
}
int main()
{
  int ip= 0,ip1 = 0 ,m=0;
  node* head = NULL;
  printf("Welcome to HacktoberFest Stack Implemented in C\n" );
  while(ip != 4)
  {

    printf("1->push\n2->pop\n3->Display\n4->exit" );
    scanf("%d",&ip);
    printf("%d\n",ip );
    switch(ip)
    {
      case 1: printf("Enter the number to push:"); scanf("%d",&ip1);head = push(head,ip1); break;
      case 2: head = pop(head); printf("Poped:%d",m);break;
      case 4: printf("Terminated\n");break;
      case 3: display(head); printf("\n" );break;
      default: printf("Wrong Input\n" );
    }
  }

}
