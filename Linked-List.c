#include<stdio.h>
#include<stdlib.h>

struct node // Creating List
{
  int data;
  struct node *link;
  struct node *info;
};
struct node *start=NULL;

// Create The Linked List
void createlist()
{
  if(start==NULL)
  {
    int i, n;
    printf("Enter the number of Nodes : ");
    scanf("%d", &n);
    if (n!=0)
    {
      int data;
      struct node *newnode;
      struct node *temp;
      newnode = (struct node*)malloc(sizeof(struct node));
      start = newnode;
      temp = start;
      printf("Enter the element of Head : ");
      scanf("%d", &data);
      start -> info = data;
      for ( i = 2; i <= n; i++)
      {
        newnode = (struct node*)malloc(sizeof(struct node));
        temp -> link = newnode;
        printf("Enter [%d] number to be Inserted : ", i);
        scanf("%d", &data);
        newnode -> info = data;
        newnode -> link = NULL; // Nj Told
        temp = temp -> link;
      }
    }
    printf("The list is created.");
  }
  else
  {
    printf("The list is already created.");
  }
}

// To Traversing All Elements
void Traverse()
{
  struct node *temp;
  if (start==NULL)
  {
    printf("\n List is Empty..");
  }
  else
  {
    int i = 1;
    temp = start;
    while(temp != NULL)
    {
      printf("Data [%d] = [%d] \n", i, temp -> info);
      temp = temp -> link;
      i++;
    }
  }
}

// To Insert Elements
void Insertion()
{
  struct node *temp, *newnode;
  int pos, data, i=1;
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("\n Enter the Position and Data : ");
  scanf("%d %d", &pos, &data);
  temp = start;
  newnode -> info = data;
  newnode -> link = 0;
  while (i < pos-1)
  {
    temp = temp -> link;
    i++;
  }
  newnode -> link = temp -> link;
  temp -> link = newnode;  
  Traverse();
}

// To Delete Elements
void Deletion()
{
  struct node *temp,*newnode;
  int pos,i=1;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter the position : ");
  scanf("%d",&pos);
  temp = start;
  newnode = start->link;
  while(i<pos-1)
  {
    temp = temp ->link;
    newnode = newnode->link;
    i++;
  }
  temp->link = newnode->link;
  free(newnode);
  Traverse();
}

// Main Body
int main()
{
  int ch, i;
  createlist();
  printf("Enter Your Choice : \n 1. Traverse \n 2. Insertion \n 3. Deletion \n 4. Exit \n Enter here : ");
  scanf("%d", &ch);
  switch (ch)
  {
  case 1:
    Traverse();
    break;
  case 2:
    Insertion();
    break;
  case 3:
    Deletion();
    break;
  case 4:
    break;
  default:
    printf("Invalid Choice....");
    break;
  }
}
