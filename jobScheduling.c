#include <stdio.h>
#include <conio.h>
#define MAX 10

struct Job
{
    int id;
    int deadline;
    int profit;
};

void sortJobs(struct Job jobs[], int n)
{
    int i, j;
    struct Job temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void jobSequencing(struct Job jobs[], int n)
{
    int i, k;
    int maxDeadline = 0;
    int timeslot[MAX] = {0}; // Initialize all elements to 0
    int totalProfit = 0;

    // Find the maximum deadline
    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Ensure maxDeadline does not exceed MAX
    if (maxDeadline >= MAX)
    {
        maxDeadline = MAX - 1;
    }

    // Initialize timeslot array
    for (i = 1; i <= maxDeadline; i++)
    {
        timeslot[i] = -1;
    }

    // Assign jobs to timeslots
    for (i = 0; i < n; i++)
    {
        k = (jobs[i].deadline <= maxDeadline) ? jobs[i].deadline : maxDeadline;
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i;
                totalProfit += jobs[i].profit;
                break;
            }
            k--;
        }
    }

    // Print job sequence
    printf("\nJob sequence (with Deadlines): \n");
    for (i = 1; i <= maxDeadline; i++)
    {
        if (timeslot[i] != -1)
            printf("slot %d -> Job%d (profit = %d)\n", i, jobs[timeslot[i]].id, jobs[timeslot[i]].profit);
        else
            printf("slot %d -> Empty\n", i);
    }
    printf("\nTotal Profit = %d\n", totalProfit);
}

int main()
{
    struct Job jobs[MAX];
    int n, i; // Declare i here
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Job %d: \n", i + 1);
        jobs[i].id = i + 1;
        scanf("%d", &jobs[i].deadline);
        scanf("%d", &jobs[i].profit);
    }
    sortJobs(jobs, n);
    jobSequencing(jobs, n);
    getch();
    return 0; // Return 0 to indicate successful execution
}