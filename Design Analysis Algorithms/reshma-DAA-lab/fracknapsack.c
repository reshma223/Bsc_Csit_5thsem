#include <stdio.h>
#include <stdlib.h>
struct Item {
int weight;
int value;
double ratio; // Value-to-weight ratio
};
int compareItems(const void *a, const void *b) {
double ratioA = ((struct Item *)a)->ratio;
double ratioB = ((struct Item *)b)->ratio;
return (ratioB > ratioA) - (ratioB < ratioA);
}
void fractionalKnapsack(struct Item items[], int n, int capacity) {
for (int i = 0; i < n; i++) {
items[i].ratio = (double)items[i].value / items[i].weight;
}
qsort(items, n, sizeof(struct Item), compareItems);
double totalValue = 0.0;
int remainingCapacity = capacity;
for (int i = 0; i < n; i++) {
if (items[i].weight <= remainingCapacity) {
totalValue += items[i].value;
remainingCapacity -= items[i].weight;
} else {
totalValue += (double)remainingCapacity / items[i].weight * items[i].value;
break;
}
}
printf("Maximum value in the knapsack: %.2f\n", totalValue);
}
int main() {
int n, capacity;
printf("Enter the number of items: ");
scanf("%d", &n);
struct Item items[n];
for (int i = 0; i < n; i++) {
printf("Enter weight and value for item %d (separated by space): ", i + 1);
scanf("%d %d", &items[i].weight, &items[i].value);
}
printf("Enter the capacity of the knapsack: ");
scanf("%d", &capacity);
fractionalKnapsack(items, n, capacity);
return 0;
}