//Page Replacements Algorithm - FIFO

#include <stdlib.h>
#include <stdio.h>
#define MaX_PAGES 12
#define FRAME_SIZE 3
void displayFrames(int frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == -1)
            printf(" ");
        else
            printf("%d", frames[i]);
    }
    printf("\n");
}
int main()
{
    int pages[MaX_PAGES] = {0, 1, 2, 3, 2, 1, 5, 2, 4, 5, 3, 2};
    int frames[FRAME_SIZE];
    int pageFaults = 0;
    int time = 0;
    for (int i = 0; i < FRAME_SIZE; i++)
        frames[i] = -1;
        printf("Page Refrence String: ");
    for (int i = 0; i < MaX_PAGES; i++)
    {
        printf("%d", pages[i]);
    }
    printf("\n");
    for(int i = 0; i < MaX_PAGES; i++)
    {
        int page = pages[i];
        int j,found = 0;
        for(j = 0; j < FRAME_SIZE; j++)
        {
            if(frames[j] == page)
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            frames[time%FRAME_SIZE] = page;
            time++;
            pageFaults++;
            displayFrames(frames, FRAME_SIZE);
        }
        if(found)
        {
            printf("Page %d already in frames\n", page);
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
