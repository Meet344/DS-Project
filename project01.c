#include<stdio.h>
#include<stdlib.h>
void insert();
void delet();
void display();
struct node
{
    int priority;
    int info;
    char name[10];
    struct node *next;
}*front = NULL;

int main()
{
    int choice;

    int choice;
   
    while(1)
    {
        printf("\n\n--------------------------- HOSPITAL TOKEN MANAGEMENT SYSTEM-------------------------------------\n\n");
        printf("1.ADMISSION BASED ON PRIORITY\n\n");
        printf("2.REMOVE VISITED PATIENT\n\n");
        printf("3.DISPLAY THE LIST ALONG WITH THEIR PRIORITY\n\n");
        printf("4.EXIT.\n\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                    insert();
                    break;
            case 2:
                    delet();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(1);
            default :
                    printf("INVALID CHOICE TRY A\n");
        }
    }
}
void insert()
{
    struct node *tmp,*ptr;
    int token,ip;
  
    
    tmp = (struct node *)malloc(sizeof(struct node));
    
     printf("\n ENTER NAME: ");
    scanf("%s",tmp->name);
    
    printf("\nENTER THE TOKEN NUMBER : ");
    scanf("%d",&token);
   
    printf("\n\nENTER THE PRIORITY \n1 for emergency\n2 for visiting\n3 for regulsr checkup \n4 for medicine\n ENTER : ");
    scanf("%d",&ip);
    
    tmp->info = token;
    tmp->priority = ip;
    
    if( front == NULL || ip < front->priority )
    {
        tmp->next = front;
        front = tmp;
    }
    else 
    {
        ptr = front;
        while( ptr->next != NULL && ptr->next->priority <= ip ) 
            ptr=ptr->next;
        tmp->next = ptr->next;
        ptr->next = tmp;
    }
}
void delet()
{
    struct node *tmp;
    if(front == NULL)
    {
        printf("\n\nNO MORE PATIENTS\n");
    }
    else
    {
        tmp = front;
        printf("\n\nDELETED TOKEN NUMBER  %d\n",tmp->info);
        front = front->next;
        free(tmp);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\n\nLIST IS EMPTY,NO PATIENTS\n");
    }
    else
    {
        printf("PRIORITY\tNAME\tTOKEN NUMBER\n\n");
        while(ptr != NULL)
        {
            printf("%d \t\t%s\t\t%d\n\n",ptr->priority,ptr->name,ptr->info);
            ptr = ptr->next;
        }
    }
} 

