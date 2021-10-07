#include<stdio.h>
#include<stdlib.h>
int *arr,*rear,*base,*front,n,k;

void createKqueues() {
    int i;
    arr = (int*)malloc(n*sizeof(int));
    front = (int*)malloc((k+1)*sizeof(int));
    rear = (int*)malloc((k+1)*sizeof(int));
    base = (int*)malloc((k+2)*sizeof(int));
    
    for(i=1;i<=k;i++)
        rear[i] = -1 + n/k*(i-1);
     for(i=1;i<=k;i++)
        front[i] = n/k*(i-1);
    for(i=1;i<=k;i++)
        base[i] = -1 + n/k*(i-1);
    base[k+1] = n-1;
    printf("An arrays of %d elements with %d queues in an array has been created\n",n,k);
}

void enqueue(int queue,int data) {
    int i;
    if(rear[queue] == base[queue+1]) {
        
        if(queue!=k && rear[queue+1]!=base[queue+2]) {
            for(i=rear[queue+1];i>=front[queue+1];i--)
                arr[i+1] = arr[i];
            base[queue+1] += 1;
            rear[queue+1] += 1;
            front[queue+1] += 1;
            arr[++rear[queue]] = data; 
            printf("element %d is enqueueed into the queue %d\n",data,queue);
        }
        else {
            printf("Overflow in queue %d\n",queue);
        }   
    }
    else {
        arr[++rear[queue]] = data;
        printf("element %d is enqueueed into the queue %d\n",data,queue);
    }
}

void dequeue(int queue) {
    if(rear[queue] < front[queue]) {
        printf("Undeflow in queue %d\n",queue);
        return;
    }
    printf("element %d is dequeuepped out from queue %d\n",arr[front[queue]++],queue);
}

int Front(int queue) {
    if(rear[queue] < front[queue]) {
        printf("Undeflow in queue %d\n",queue);
        return;
    }
    printf("element %d is currently at the rear of queue %d\n",arr[front[queue]],queue);
}

void display(int queue ,int start, int end) {
    int i;
    if(start>end) {
        printf("queue %d is empty\n",queue);
        return;
    }
    printf("Contents of the queue %d are(leftmost element is at the front) :\n",queue);
    for(i=start;i<=end;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int choice, x, y;
    printf("Enter the size of the array in which you want to make multiple queues : ");
    scanf("%d",&n);
    printf("Enter the number of queues you want to make in that array : ");
    scanf("%d",&k);
    createKqueues();
    printf("\nChoices are : \n");
    printf("1. enqueue an item into the queue :\n");
    printf("2. dequeue an item from the queue :\n");
    printf("3. Get the front element of the queue :\n");
    printf("4. Display the contents of the queue : \n");
    printf("5. Exit :\n");
    while (1)
    {
        printf("------------------------------------------------------");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the queue number(1 to 3) : ");
            scanf("%d",&y);
            printf("Enter the element you want to enqueue into the queue : ");
            scanf("%d", &x);
            enqueue(y,x);
            break;
        case 2:
            printf("Enter the queue number(1 to 3) : ");
            scanf("%d",&y);
            dequeue(y);
            break;
        case 3:
            printf("Enter the queue number(1 to 3) : ");
            scanf("%d",&y);
            Front(y);
            break;
        case 4:
            printf("Enter the queue number(1 to 3) : ");
            scanf("%d",&y);
            display(y,front[y],rear[y]);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.");
        }
        getch();
    }
}
