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
