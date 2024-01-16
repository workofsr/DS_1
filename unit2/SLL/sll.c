#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;
void createLList(int n);
void deleteMid(int pos);
void display();

int main(){
    int n, data, pos;
    
    printf("Enter total nodes: ");
    scanf("%d", &n);
    createLList(n);

    printf("\nLinked list as follows\n\n");
    display();
    
    printf("Ekda Node to be deleted: ");
    scanf("%d", &pos);
    
    deleteMid(pos);
    
    printf("\nLinked list as follows\n\n");
    display();
    
    return 0;
}

void createLList(int n){
    struct node *newNode, *temp;
    int data, i;
    
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Unable to Allocate Memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        
        head->data = data;
        head->next = NULL;
        
        temp = head;
        
        for(i = 2; i<=n ; i++) {
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode == NULL) {
                printf("unable to allocate memory.");
            }
            else{
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                
                newNode->data = data;
                newNode->next = NULL;
                
                temp->next = newNode;
                temp = temp->next;
            }
        }
        printf("SINGLY LINKED LIST CREATED BY RG\n");
    }
}

void display()
{
    struct node *temp;
    if(head == NULL){
        printf("LL is empty.");
    }
    else{
        temp = head;
        while(temp!=NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            printf("->");
        }
    }
    printf("\n\n\n\n");
}

void deleteMid(int pos)
{
    struct node *toDelete, *prevNode;
    int i;
    
    if(head == NULL)
    {
        printf("LL is already empty.");
    }
    else{
        toDelete = head;
        prevNode = head;
        
        for(i = 2 ; i<=pos; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;
            
            if(toDelete == NULL)
            {
                break;
            }
        }
        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;
                
            prevNode->next = toDelete->next;
            toDelete->next = NULL;
        }
        
        printf("%d will be deleted.", toDelete->data);
        
        free(toDelete);
        
        printf("Success in Deletion.");
    }
}