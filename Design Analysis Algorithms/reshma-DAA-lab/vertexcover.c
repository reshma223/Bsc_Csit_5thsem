#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
struct Edge {
int src, dest;
};
struct Graph {
int V, E;
struct Edge* edges;
};
struct Graph* createGraph(int V, int E) {
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
graph->V = V;
graph->E = E;
graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
graph->edges[graph->E].src = src;
graph->edges[graph->E].dest = dest;
graph->E++;
}
void findVertexCover(struct Graph* graph) {
bool visited[MAX_VERTICES] = {false};
for (int i = 0; i < graph->E; i++) {
int src = graph->edges[i].src;
int dest = graph->edges[i].dest;
if (!visited[src] && !visited[dest]) {
visited[src] = true;
visited[dest] = true;
}
}
printf("Vertex Cover: ");
for (int i = 0; i < graph->V; i++) {
if (visited[i]) {
printf("%d ", i);
}
}
printf("\n");
}
int main() {
int V = 5;
int E = 4;
struct Graph* graph = createGraph(V, E);
addEdge(graph, 0, 1);
addEdge(graph, 1, 2);
addEdge(graph, 2, 3);
addEdge(graph, 3, 4);
findVertexCover(graph);
free(graph->edges);
free(graph);
return 0;
}