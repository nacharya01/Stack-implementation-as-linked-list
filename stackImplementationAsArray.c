#include <stdio.h>
#include <stdlib.h>

  struct node{
    int info;
  struct node * next;
  };
  
  struct node * createNode(){
    struct node * stack;
    stack=(struct node *) malloc(sizeof(struct node));
    return stack;
  }
  
  int pop(struct node **s){
    int item;
    if(*s==NULL){
      printf("The list is empty so it can not be popped \n");
      return 0;
    }
    else{
      struct node *t;
      t=*s;
      item=(*s)->info;
      *s=(*s)->next;
      free (t);
      printf("Popped item : %d",item);
    }
  }
  
  void push(struct node **s,int item){
    struct node * temp;
    temp=createNode();
    if(temp!=NULL){
      temp->info=item;
      temp->next=*s;
      *s=temp;
    }
  }
  
  int peek(struct node **s){
    int item;
    if(*s==NULL){
      return (0);
    }
    else {
      item=(*s)->info;
      return (item);
    }
  }
  
  void main(){
    struct node * stack=NULL;
    int item,choice;
    while(1){
      printf("\n 1.Enter to push the item ");
      printf("\n 2.Enter to pop the item");
      printf("\n 3. Enter to show the peek item");
      printf("\n 4. Enter to exit the loop\n");
      scanf("%d",&choice);
      switch(choice){
        case 1: printf("\nEnter the number that you want to push in the list ");
                scanf("%d",&item);
                push(&stack,item);
                break;
        case 2: item=pop(&stack);
                break;
        case 3: item=peek(&stack);
                if(!peek(&stack)){
                    printf("Peek value in the list : %d",item);
                }
                else{
                    printf("The given list is empty ");
                }
                break;
       default : printf("You didn't the enter number according to our requirements");
     }
    }
}
