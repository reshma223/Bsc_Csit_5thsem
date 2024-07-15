#include <stdio.h>
void generateFibonacci(int n) {
int first = 0, second = 1, next, i;
printf("Fibonacci Sequence up to %d terms:\n", n);
for (i = 0; i < n; i++) {
printf("%d, ", first);
next = first + second;
first = second;
second = next;
}
printf("\n");
}
int main() {
int numTerms;
printf("Enter the number of terms for the Fibonacci sequence: ");
scanf("%d", &numTerms);
generateFibonacci(numTerms);
return 0;
}