#include<stdio.h>
#include<stdlib.h>

int sticks[5] = {1, 1, 1, 1, 1};
int eating[5] = {0, 0, 0, 0, 0};
int mutex = 1;
int phil = 5;


void pick_chopsticks(int phil)
{
    --mutex;
    if(eating[phil]==1)
    {
        printf("Philosopher %d is already eating.They cannot pick up chopsticks again\n", phil+1);
    }
    else if(sticks[phil]==1 && sticks[(phil+1)%5]==1)
    {
        sticks[phil] = 0;
        sticks[(phil+1)%5] = 0;
        eating[phil] = 1;
        printf("Philosopher %d picks up chopsticks %d and %d \n", phil+1,phil+1,(phil+1)%5+1);
        printf("Philosopher %d is eating\n", phil+1);
    }
    else
    {
        printf("Philosopher %d is waiting for chopsticks\n", phil+1);
    }
    ++mutex;
}
int main()
{
    int ch,philosopher;
    printf("Dining Philosopher's Problem\n");
    printf("1. Philosopher 1\n2. Philosopher 2\n3. Philosopher 3\n4. Philosopher 4\n5. Philosopher 5\n6. Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("Enter the philosopher number\n");
                scanf("%d",&philosopher);
                if(phil<1||phil>5)
                {
                    printf("Invalid Philosopher number\n");
                }
                else
                {
                    pick_chopsticks(philosopher-1);
                }
            break;
            case 2: 
                printf("Enter the philosopher number\n");
                scanf("%d",&philosopher);
                if(phil<1||phil>5)
                {
                    printf("Invalid Philosopher number\n");
                }
                else
                {
                    pick_chopsticks(philosopher-1);
                }
            break;
            case 3:
                exit(0);
            break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}