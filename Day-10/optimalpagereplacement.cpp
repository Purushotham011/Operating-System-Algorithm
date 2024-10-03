//Optimal page replacement algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

int findOptimalPage(int pages[], int page_count, int frame[], int frame_count, int current_index)
{
    int i,j,farthest = current_index,replace_index=-1;
    for(i=0;i<frame_count;i++)
    {
        int found =0;
        for(j=current_index;j<page_count;j++)
        {
            if(frame[i]==pages[j])
            {
                found = 1;
                if(j>farthest)
                {
                    farthest = j;
                    replace_index = i;
                }
                break;
            }
        }
        if(found==0)
        {
            return i;
        }
    }
    return (replace_index==-1)?0:replace_index;
}

void optimalPageReplacement(int pages[], int page_count, int frame_count)
{
    int i,j,frame[MAX_FRAMES],faults=0;
    for(i=0;i<frame_count;i++)
    {
        frame[i] = -1;
    }
    printf("Refrence String: ");
    for(i=0;i<page_count;i++)
    {
        printf("%d ",pages[i]);
    }
    printf("\n");

    for(i=0;i<page_count;i++)
    {
        int page=pages[i];
        int found = 0;
        for(j=0;j<frame_count;j++)
        {
            if(frame[j]==page)
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            
            int replace_index = findOptimalPage(pages,page_count,frame,frame_count,i);
            frame[replace_index] = page;
            faults++;

            printf("Page Fault: %d -> ",page);
            for(j=0;j<frame_count;j++)
            {
                printf("%d ",frame[j]);
            }
            printf("\n");
        }
    }
    printf("Total Page Faults: %d\n",faults);
}

int main()
{
    int pages[MAX_PAGES],page_count,frame_count,i;
    printf("Enter the number of pages: ");
    scanf("%d",&page_count);
    printf("Enter the reference string (space separated): ");
    for(i=0;i<page_count;i++)
    {
        scanf("%d",&pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d",&frame_count);
    optimalPageReplacement(pages,page_count,frame_count);
    return 0;
}