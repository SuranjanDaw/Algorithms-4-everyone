#include<stdio.h>
#include<stdlib.h>
typedef struct node node;

struct node {
  int num;
  node* link;
  node* link1;
};

node* enque(node* head, int num)
{
  if(head != NULL)
  {
    node* ptr = (node*)malloc(sizeof(node));
    ptr->num = num;
    ptr->link1 = head;
    ptr->link = NULL;
    head->link = ptr;
    head = ptr;
    return head;
  } else{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->num = num;
    ptr->link = NULL;
    ptr->link1 = NULL;
    return ptr;
  }
}

node* deque(node *tail)
{
  if(tail != NULL)
  {

    node* ptr = tail;
    tail = tail->link;
    tail->link1 = NULL;
    free(ptr);
    return tail;
  } else {
    return NULL;
  }
}

void display(node* head)
{
  while(head != NULL)
  {
    printf("%d-->",head->num );
    head = head->link1;
  }
}
int main()
{
  int ip= 0,ip1 = 0 ,m=0;
  node* head = NULL, *tail = NULL;
  printf("Welcome to HacktoberFest Stack Implemented in C\n" );
  while(ip != 4)
  {

    printf("1->enque\n2->deque\n3->Display\n4->exit" );
    scanf("%d",&ip);
    printf("%d\n",ip );
    switch(ip)
    {
      case 1: printf("Enter the number to insert:");
              scanf("%d",&ip1);
              if(head != NULL)
                head = enque(head,ip1);
              else {
                head = enque(head,ip1);
                tail = head;
              }
             break;
      case 2: if(tail != NULL)
                tail = deque(tail);
              printf("Deleted");break;
      case 4: printf("Terminated\n");break;
      case 3: display(head); printf("\n" );break;
      default: printf("Wrong Input\n" );
    }
  }

}
