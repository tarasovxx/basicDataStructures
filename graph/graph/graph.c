#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (visited[adjVertex] == 0) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int queue[MAX_VERTICES];
int front = -1, rear = -1;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
}

void addEdge(int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

void BFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    enqueue(vertex);

    while (front != -1 && front <= rear) {
        int currVertex = dequeue();

        struct Node* temp = adjList[currVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                printf("%d ", adjVertex);
                enqueue(adjVertex);
            }
            temp = temp->next;
        }
    }
}

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Node* adjList[MAX_VERTICES];
int distance[MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i] = NULL;
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
}

int getMinimumDistance() {
    int minDistance = INT_MAX;
    int minVertex;

    for (int i = 0; i < numVertices; i++) {
        if (visited[i] == 0 && distance[i] < minDistance) {
            minDistance = distance[i];
            minVertex = i;
        }
    }

    return minVertex;
}

void Dijkstra(int startVertex) {
    distance[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int currentVertex = getMinimumDistance();
        visited[currentVertex] = 1;

        struct Node* temp = adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            int weight = temp->weight;

            if (visited[adjVertex] == 0 && distance[currentVertex] != INT_MAX &&
                distance[currentVertex] + weight < distance[adjVertex]) {
                distance[adjVertex] = distance[currentVertex] + weight;
            }

            temp = temp->next;
        }
    }
}

void BellmanFord(int startVertex) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        distance[i] = INT_MAX;
    }
    distance[startVertex] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            int src = edges[j].src;
            int dest = edges[j].dest;
            int weight = edges[j].weight;

            if (distance[src] != INT_MAX && distance[src] + weight < distance[dest]) {
                distance[dest] = distance[src] + weight;
            }
        }
    }

    // Проверка наличия отрицательных циклов
    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        if (distance[src] != INT_MAX && distance[src] + weight < distance[dest]) {
            printf("Граф содержит отрицательный цикл.\n");
            return;
        }
    }

    printf("Кратчайшие расстояния от вершины %d:\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        printf("Вершина %d: %d\n", i, distance[i]);
    }
}

void FloydWarshall() {
    int dist[MAX_VERTICES][MAX_VERTICES];
    int pred[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INT_MAX && i != j) {
                pred[i][j] = i;
            } else {
                pred[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }


    printf("Матрица кратчайших расстояний:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    printf("Восстановленные пути:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j && pred[i][j] != -1) {
                printf("Путь от вершины %d к вершине %d: ", i, j);
                printf("%d ", j);
                int p = pred[i][j];
                while (p != i) {
                    printf("%d ", p);
                    p = pred[i][p];
                }
                printf("%d\n", i);
            }
        }
    }
}

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void primMST() {
    int parent[MAX_VERTICES]; // Массив для хранения MST
    int key[MAX_VERTICES]; // Массив для хранения ключей
    bool mstSet[MAX_VERTICES]; // Массив, отмечающий вершины, включенные в MST

    // Инициализация ключей и mstSet
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Ключ первой вершины равен 0, чтобы она была выбрана первой
    key[0] = 0;
    parent[0] = -1; // Начальная вершина не имеет родителя

    // Построение MST
    for (int count = 0; count < numVertices - 1; count++) {
        // Находим вершину с минимальным ключом из непосещенных вершин
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < numVertices; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Включаем вершину в MST
        mstSet[minIndex] = true;

        // Обновляем ключи и родителей соседних вершин
        for (int v = 0; v < numVertices; v++) {
            if (graph[minIndex][v] && !mstSet[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    // Вывод MST
    printf("Ребро \tВес\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

typedef struct {
    int src, dest, weight;
} Edge;

int parent[MAX_VERTICES];
Edge edges[MAX_VERTICES];
int numVertices, numEdges;

int find(int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return find(parent[vertex]);
}

void unionSets(int x, int y) {
    int xSet = find(x);
    int ySet = find(y);
    parent[xSet] = ySet;
}

int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

void kruskalMST() {
    Edge mst[MAX_VERTICES];
    int mstSize = 0;

    qsort(edges, numEdges, sizeof(Edge), compare); // Сортировка ребер по возрастанию весов

    // Инициализация каждой вершины в отдельное множество
    for (int i = 0; i < numVertices; i++)
        parent[i] = -1;

    int edgeCount = 0;
    while (mstSize < numVertices - 1 && edgeCount < numEdges) {
        Edge nextEdge = edges[edgeCount++];

        int x = find(nextEdge.src);
        int y = find(nextEdge.dest);

        // Если ребро не создает цикл, добавляем его в MST
        if (x != y) {
            mst[mstSize++] = nextEdge;
            unionSets(x, y);
        }
    }

    // Вывод MST
    printf("Ребро \tВес\n");
    for (int i = 0; i < mstSize; i++) {
        printf("%d - %d \t%d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
}


int graph[MAX_VERTICES][MAX_VERTICES];
int residualGraph[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;

int min(int a, int b) {
    return (a < b) ? a : b;
}

bool bfs(int source, int sink) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    visited[source] = true;
    parent[source] = -1;

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = source;

    while (front != rear) {
        int u = queue[front++];

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;

    // Создаем остаточный граф, равный исходному графу
    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    while (bfs(source, sink)) {
        int pathFlow = INT_MAX;

        // Находим минимальную пропускную способность ребер на пути
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Обновляем остаточный граф и обратные ребра
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}