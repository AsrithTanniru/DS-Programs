#include<stdio.h>
#include<stdlib.h>
#define V 100

void addEDGE(int adj[][V], int i, int j) {
    adj[i][j] = 1;
    adj[j][i] = 1;
}

void PrintMAT(int adj[][V], int size) {
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < size; i++) {
        // printf("Neighbours of node %d are: ", i);
        for (int j = 0; j < size; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void createGraph(int adj[][V], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[i][j] = 0; 
        }
    }
}
void DFS(int adj[][V],int visited[],int start,int size){
    int stack[V],top=-1,i;
    stack[++top]=start;
    visited[start]=1;
    printf("Depth First Traversal starting from node %d:\n", start);
    while (top!=-1)
    {
        start=stack[top--];
        printf("%d ",start);
        for(i=0;i<size;i++){
            if(adj[start][i]==1&&visited[i]==0){
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
    

}



int main() {
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);

    int adj[V][V] = {0};
    int visited[V] = {0};

    int choice = 0;
    while (choice != 5) { 
        printf("\n1.Create\n2.Add an EDGE \n3.Depth First Traversal\n4.Print the Matrix\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph(adj, size);
                printf("Created graph with size %d\n", size);
                break;
            case 2:
                {
                    int index1, index2;
                    printf("Enter the indices of the nodes to add an edge for node1 and node2: ");
                    scanf("%d %d", &index1, &index2);
                    addEDGE(adj, index1, index2);
                    printf("Edge added between nodes %d and %d.\n", index1, index2);
                    break;
                }
            case 3:
                {
                    int start;
                    printf("Enter the starting node for Breadth First Traversal: ");
                    scanf("%d", &start);
                    DFS(adj, visited, start, size);
                    break;
                }
            case 4:
                PrintMAT(adj, size);
                break;
            
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Choose between 1 and 5.\n");
        }
    }

    return 0;
}

// 0/1 Knapsack
// // #include <iostream>
// // #include <vector>
// // using namespace std;

// int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
//     int n = weights.size();
//     vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

//     for (int i = 1; i <= n; i++) {
//         for (int w = 1; w <= capacity; w++) {
//             if (weights[i - 1] <= w)
//                 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
//             else
//                 dp[i][w] = dp[i - 1][w];
//         }
//     }
//     return dp[n][capacity];
// }

// int main() {
//     vector<int> weights1 = {1, 3, 4, 5}, values1 = {1, 4, 5, 7};
//     cout << "Max value (Test Case 1): " << knapsack(weights1, values1, 7) << endl;

//     vector<int> weights2 = {2, 3, 4}, values2 = {3, 4, 5};
//     cout << "Max value (Test Case 2): " << knapsack(weights2, values2, 5) << endl;

//     return 0;
// }



//Floyd warshall
#include <stdio.h>

#define V 4
#define INF 99999

void floydAlgorithm(int graph[V][V]) {
    int dist[V][V];

    // Initialize the distance matrix with the graph's weights
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the distances using the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest Distance Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floydAlgorithm(graph);
    return 0;
}
