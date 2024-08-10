#include <stdio.h>
#include <stdbool.h>
#define V 4 // Number of vertices in the graph
void printSolution(int color[]);
// Utility function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
// Recursive function to solve the graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}
// Main function to solve the graph coloring problem using backtracking
void graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    if (!graphColoringUtil(graph, m, color, 0))
        printf("Solution does not exist");
    else
        printSolution(color);
}
// Utility function to print the solution
void printSolution(int color[])
{
    printf("Solution exists. The coloring of vertices is:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d: Color %d\n", i, color[i]);
}
int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}