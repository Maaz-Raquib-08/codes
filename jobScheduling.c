#include <stdio.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};
int main()
{
    int n, maxDeadline = 0, maxProfit = 0;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the deadline and profit of Job-%d: ", (i + 1));
        jobs[i].id = i + 1;
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }
    // sort jobs according to max profit
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    // claculate max deadline
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    // making a slot for jobs and an array to show job sequences
    int timeSlot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
    timeSlot[i] = 0;


    for (int i = 0; i < n; ++i)
    {
        if (timeSlot[jobs[i].deadline] == 0)
        {
            maxProfit += jobs[i].profit;
            timeSlot[jobs[i].deadline] = jobs[i].id;
        }
        else
        {
            int j = jobs[i].deadline;
            while (j > 0)
            {
                if (timeSlot[j] == 0)
                {
                    maxProfit += jobs[i].profit;
                    timeSlot[j] = jobs[i].id;
                    break;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    printf("\nMax profit = %d\n", maxProfit);
    printf("Job Sequences:\n");
    for (int i = 1; i <= maxDeadline; ++i)
    {
        printf("%d-->%d : J%d \n", i - 1, i, timeSlot[i]);
    }
    printf("\n");
    return 0;
}


