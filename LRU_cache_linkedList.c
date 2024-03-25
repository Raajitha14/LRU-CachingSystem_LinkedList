#include <stdio.h> 
#include <stdlib.h> 
int count; 
struct node { 
int key; 
int value; 
struct node *llink; 
struct node *rlink; 
}; 
typedef struct node *NODE; 
NODE first = NULL; 
NODE getnode() { 
    NODE x; 
    x = (NODE)malloc(sizeof(struct node)); 
    return x; 
} 
void put() { 
    NODE temp; 
    int n, i; 
        temp = getnode(); 
        printf("Enter key: "); 
        scanf("%d", &(temp->key)); 
        printf("Enter value: "); 
        scanf("%d", &(temp->value)); 
        temp->llink = NULL; 
        temp->rlink = NULL; 
        count++; 
        if (first == NULL) { 
            first = temp; 
        } else { 
            temp->rlink=first; 
            first->llink=temp; 
            first=temp; 
        } 
} 
void get() { 
    if (first == NULL) { 
        printf("Linked list is empty\n"); 
return; 
    } 
    NODE cur;
    cur = first; 
    NODE prev,next; 
    int a, found = 0; 
    printf("Enter the key whose data is to be used: "); 
    scanf("%d", &a); 
    while (cur != NULL) { 
        if (cur->key == a) { 
            printf("Value is %d\n", cur->value); 
            found = 1; 
            if(cur==first){ 
                break; 
            } 
            next=cur->rlink; 
            prev=cur->llink; 
            cur->llink=NULL; 
            first->llink=cur; 
            cur->rlink=first; 
            if(prev!=NULL){ 
            prev->rlink=next; 
            } 
            if(next!=NULL){ 
            next->llink=prev; 
            } 
            first=cur; 
             
            break; 
        } 
 cur = cur->rlink; 
    } 
    if (!found) { 
    printf("Key not found\n"); 
    } 
} 
void delete_rear(){ 
    NODE cur; 
    if(first==NULL){ 
        printf("Empty\n"); 
    } 
    cur=first; 
    while(cur->rlink!=NULL){ 
        cur=cur->rlink; 
    } 
    printf("%d=>%d is deleted\n",cur->key,cur->value); 
    if(cur==first){ 
    first=NULL; 
    } 
    else{ 
    cur->llink->rlink=NULL; 
    cur->llink=NULL; 
    free(cur); 
    cur=NULL; 
    } 
    count--;   
} 
void display(){ 
    NODE cur=first; 
    if(cur==NULL){ 
printf("Empty"); 
    } 
    else{
        while(cur!=NULL){ 
        printf("%d=>%d\n",cur->key,cur->value); 
        cur=cur->rlink; 
    } 
}    
} 
int main() { 
    int choice; 
     int c; 
    printf("Enter the capacity of the cache: "); 
    scanf("%d", &c); 
    while(1){ 
    printf("1.Enter 1 to put\n"); 
    printf("2.enter 2 to get\n"); 
    printf("3.enter 3 to display\n"); 
    scanf("%d",&choice); 
    switch(choice){ 
    case 1:if(count==c){ 
         //"Can't insert the data. Cache is full. Delete the least recently    used cache 
        delete_rear();    
    } 
           put(); 
           break; 
    case 2:get(); 
           break; 
    case 3:display(); 
           break; 
    default:printf("invalid");  } 
    } return 0; 
}