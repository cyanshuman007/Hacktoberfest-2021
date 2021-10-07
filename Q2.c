#include<stdio.h>
#include<conio.h>
#define max 20

int tos1=-1,tos2=-1;
int stack1[max],stack2[max];

void push(int *S,int ele, int *top) {
    if(*top<max-1) {
        (*top)++;
        *(S+*top)=ele;
    }
    else
        printf("\nStack is full.\n");
}

int pop(int *S, int *top) {
    int value=*(S+*top);
    (*top)--;
    return(value);
}

void display(int *S, int top) {
    printf("\nElements in the Queue are:\n");
    if(top==-1)
        printf("\nStack is empty.\n");
    else {
        for(int i=0;i<=top;i++) {
            printf("%d ",*(S+i));
        }
    }
}

void main() {
    int choice,ele,temp;
    printf("\n\t[1] Enqueue");
    printf("\n\t[2] Dequeue");
    printf("\n\t[3] Display");
    printf("\n\t[7] Exit");

    do {
        printf("\nEnter your choice= ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: 
                if(tos1>=max-1)
                    printf("\nQueue is full.\n");
                else {
                    printf("Enter the element to insert= ");
                    scanf("%d",&ele);
                    push(stack1,ele,&tos1);
                }
                break;
            case 2: 
                if(tos1==-1)
                    printf("\nQueue is Empty.You can't dequeue.\n");
                else {
                    while(tos1!=0) {
                        ele=pop(stack1,&tos1);
                        push(stack2,ele,&tos2);
                    }
                    ele=pop(stack1,&tos1);
                    printf("\nDeleted Element from Queue= %d",ele);
                    while(tos2!=-1) {
                    ele=pop(stack2,&tos2);
                    push(stack1,ele,&tos1);
                    }
                }
                break;
            case 3: 
                display(stack1,tos1);
        }
    }
    while(choice!=7);
    getch();
}