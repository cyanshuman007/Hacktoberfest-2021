// program to implement k stacks in a single array
#include<stdio.h>
#include<stdlib.h>
int *arr,*top,*base,n,k;
// fucntion to initialise K stacks in an array
void createKstacks()
{
    int i;
    arr = (int*)malloc(n*sizeof(int));
    top = (int*)malloc((k+1)*sizeof(int));
    base = (int*)malloc((k+2)*sizeof(int));
    //intialising the top and base arrays for each stack
    for(i=1;i<=k;i++)
        top[i] = -1 + n/k*(i-1);
    for(i=1;i<=k;i++)
        base[i] = -1 + n/k*(i-1);
    base[k+1] = n-1;
    printf("An arrays of %d elements with %d stacks in an arrays has been created\n",n,k);
}
//function to push an item into one of the K stacks
// given the stack number
void push(int stack,int data)
{
    int i;
    if(top[stack] == base[stack+1]) 
    {
        //check space in (i+1)th stack
        if(stack!=k && top[stack+1]!=base[stack+2])
        {
            for(i=top[stack+1];i>base[stack+1];i--)
                arr[i+1] = arr[i];
            base[stack+1] += 1;
            top[stack+1] +=1;
            arr[++top[stack]] = data; 
            printf("element %d is pushed into the stack %d\n",data,stack);
        }
        //check space in (i-1)th stack
        else if(stack!=1 && top[stack-1]!=base[stack])
        {
             for(i=base[stack];i<top[stack];i++)
                arr[i] = arr[i+1];
            base[stack] -= 1;
            arr[top[stack]] = data;
            printf("element %d is pushed into the stack %d\n",data,stack);
        }
        else
        {
            printf("Overflow in stack %d\n",stack);
        }   
    }
    else{
        arr[++top[stack]] = data;
        printf("element %d is pushed into the stack %d\n",data,stack);
    }
}
//function to pop ot an element from the stack
// given the stack number
void pop(int stack)
{
    if(top[stack] == base[stack])
    {
        printf("Undeflow in stack %d\n",stack);
        return;
    }
    printf("element %d is poppped out from stack %d\n",arr[top[stack]--],stack);
}
int Top(int stack)
{
    if(top[stack] == base[stack])
    {
        printf("Undeflow in stack %d\n",stack);
        return;
    }
    printf("The element currently at the top of the stack %d is %d\n",stack,arr[top[stack]]);
}
void display(int stack ,int start, int end)
{
    int i;
    if(start==end)
    {
        printf("Stack %d is empty\n",stack);
        return;
    }
    printf("Contents of the stack %d are(rightmost element is at the top) :\n",stack);
    for(i=start+1;i<=end;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    int choice, x, y;
    printf("Enter the size of the array in which you want to make multiple stacks : ");
    scanf("%d",&n);
    printf("Enter the number of stacks you want to make in that array : ");
    scanf("%d",&k);
    createKstacks();
    printf("\nChoices are : \n");
    printf("1. Push an item into the stack :\n");
    printf("2. Pop an item from the stack :\n");
    printf("3. Get the top element of the stack :\n");
    printf("4. Display the contents of the stack : \n");
    printf("5. Exit :\n");
    while (1)
    {
        printf("------------------------------------------------------");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the stack number(1 to %d) : ",k);
            scanf("%d",&y);
            printf("Enter the element you want to push into the stack : ");
            scanf("%d", &x);
            push(y,x);
            break;
        case 2:
            printf("Enter the stack number(1 to %d) : ",k);
            scanf("%d",&y);
            pop(y);
            break;
        case 3:
            printf("Enter the stack number(1 to %d) : ",k);
            scanf("%d",&y);
            Top(y);
            break;
        case 4:
            printf("Enter the stack number(1 to %d) : ",k);
            scanf("%d",&y);
            display(y,base[y],top[y]);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.");
        }
        getch();
    }
}
