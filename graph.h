
#include <stdlib.h>
#include <stdio.h>

#define GRAPH_DATA_TYPE int

struct Graph
{
    int *data;
    int lenght;
};

typedef struct Graph Graph;

int graphLenght(Graph *graph)
{
    return graph->lenght;
}

/**
 * Inicializacion del nodo
 * @param graph puntero al nodo
 * @param nodes numero de nodos del grafo
 */
void graphInit(Graph *graph, int nodes)
{
    // numero de nodos necesarios para representar
    // el grafo = (nNodos**2-nNodos)/2
    int foo = (nodes * (nodes - 1)) / 2;
    graph->data = malloc(foo*sizeof(int));

    graph->lenght = nodes;
}

int graphValidPosition(Graph *graph, int origin, int destiny)
{
    // encontrar el minimo
    int minn = origin < destiny ? origin : destiny;
    // encontrar el maximo
    int maxn = origin > destiny ? origin : destiny;
    int nodes = graph->lenght;

    if (minn == maxn)
    {
        // nodo conectado a si mismo
        return 0;
    }

    if (maxn >= nodes || minn < 0)
    {
        // nodo mas grande que la cantidad de espacio disponible
        return 0;
    }

    return 1;
}

/**
 * Conveierte las posiciones de 2 nodos en el indice numerico
 * que representa su arista,
 *
 * @note el orden de origin y destiny no es importante.
 *
 * @param graph direccion al grafo
 * @param origin indice del nodo de origen
 * @param destiny indice del nodo destino
 * @return int
 */
int graphEdgeIndex(Graph *graph, int origin, int destiny)
{
    // encontrar el minimo
    int minn = origin < destiny ? origin : destiny;
    // encontrar el maximo
    int maxn = origin > destiny ? origin : destiny;
    int nodes = graph->lenght;

    if (!graphValidPosition(graph, maxn, minn))
    {
        puts("graphEdgeIndex: Posicion invalida");
        exit(EXIT_FAILURE);
    }

    
    int a = nodes - 1;
    int b = a - minn;
    int c = 0;
    for (int i = a; i > b; i--) {
        // NOTE: quiza esto se puede replazar por una serie de sumas aritmeticas
        c += i;
    }
    return c + (maxn - minn) - 1;
}

void graphSetEdgeWeight(Graph *graph, int origin, int destiny, int weigth)
{
    graph->data[graphEdgeIndex(graph, origin, destiny)] = weigth;
}

GRAPH_DATA_TYPE grapthGetEdgeWeight(Graph *graph, int origin, int destiny)
{
    return graph->data[graphEdgeIndex(graph, origin, destiny)];
}