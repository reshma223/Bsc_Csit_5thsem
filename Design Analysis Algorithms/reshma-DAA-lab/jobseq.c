#include <stdio.h>
#include <stdlib.h>
struct Job {
char id;
int deadline;
int profit;
};
int compareJobs(const void *a, const void *b) {
return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}
int findMaxDeadline(struct Job jobs[], int n) {
int maxDeadline = -1;
for (int i = 0; i < n; i++) {
if (jobs[i].deadline > maxDeadline) {
maxDeadline = jobs[i].deadline;
}
}
return maxDeadline;
}
void jobSequencing(struct Job jobs[], int n) {
qsort(jobs, n, sizeof(struct Job), compareJobs);
int maxDeadline = findMaxDeadline(jobs, n);
char scheduledJobs[maxDeadline];
for (int i = 0; i < maxDeadline; i++) {
scheduledJobs[i] = '-';
}
for (int i = 0; i < n; i++) {
for (int j = jobs[i].deadline - 1; j >= 0; j--) {
if (scheduledJobs[j] == '-') {
scheduledJobs[j] = jobs[i].id;
break;
}
}
}
printf("Scheduled Jobs: ");
for (int i = 0; i < maxDeadline; i++) {
if (scheduledJobs[i] != '-') {
printf("%c ", scheduledJobs[i]);
}
}
printf("\n");
}
int main() {
int n;
printf("Enter the number of jobs: ");
scanf("%d", &n);
struct Job jobs[n];
for (int i = 0; i < n; i++) {
printf("Enter details for job %d (ID, Deadline, Profit): ", i + 1);
scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
}
jobSequencing(jobs, n);
return 0;
}