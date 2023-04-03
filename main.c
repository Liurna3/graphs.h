
#include "graph.h"

#include <stdlib.h>
#include <stdio.h>

void displayGraph(Graph *graph)
{
    int foo = graphLenght(graph);

    for (int i = 0; i < foo; i++)
    {
        for (int j = 0; j < foo; j++)
        {
            if (!graphValidPosition(graph, i, j))
            {
                printf(" - ");
                continue;
            }

            printf("%2d ", graphGetEdgeWeight(graph, i, j));
        }

        printf("\n");
    }
}

int main()
{
    /* code */
    Graph bar;
    graphInit(&bar, 6);

    //printf("a %d\n", graphEdgeIndex(&bar, 0,1));

    // A
    graphSetEdgeWeight(&bar, 0, 1, 4);
    graphSetEdgeWeight(&bar, 0, 2, 4);

    // B
    graphSetEdgeWeight(&bar, 1, 2, 2);
    graphSetEdgeWeight(&bar, 1, 4, 1);

    // C
    graphSetEdgeWeight(&bar, 2, 3, 1);

    // D
    graphSetEdgeWeight(&bar, 3, 5, 2);

    // E 
    graphSetEdgeWeight(&bar, 4, 5, 4);

    displayGraph(&bar);

    graphFree(&bar);

    // otro grafo
    graphInit(&bar, 5);

    // 1
    graphSetEdgeWeight(&bar, 0, 1, 1);
    graphSetEdgeWeight(&bar, 0, 3, 1);

    // 2
    graphSetEdgeWeight(&bar, 1, 4, 1);
    graphSetEdgeWeight(&bar, 1, 2, 1);

    // 3
    graphSetEdgeWeight(&bar, 2, 3, 1);
    displayGraph(&bar);

    return 0;
}
