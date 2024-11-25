//MARK:BFS and DFS
#include <stdio.h>
#include <stdlib.h>
#define V 100

void addEdge(int adj[][V], int i, int j) {
    adj[i][j] = 1;
    adj[j][i] = 1;
}

void createGraph(int adj[][V], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[i][j] = 0;
        }
    }
}

void printMatrix(int adj[][V], int size) {
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void DFS(int adj[][V], int visited[], int start, int size) {
    int stack[V], top = -1;
    stack[++top] = start;
    visited[start] = 1;
    printf("Depth First Traversal starting from node %d:\n", start);
    while (top != -1) {
        int node = stack[top--];
        printf("%d ", node);
        for (int i = 0; i < size; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void BFS(int adj[][V], int visited[], int start, int size) {
    int queue[V], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("Breadth First Traversal starting from node %d:\n", start);
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < size; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the graph: ");
    scanf("%d", &size);

    int adj[V][V], visited[V];
    createGraph(adj, size);

    int choice;
    while (1) {
        for (int i = 0; i < size; i++) visited[i] = 0;
        printf("\n1. Add an EDGE\n2. Print Matrix\n3. DFS\n4. BFS\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int u, v;
                printf("Enter the nodes to add an edge (u v): ");
                scanf("%d %d", &u, &v);
                addEdge(adj, u, v);
                printf("Edge added between %d and %d.\n", u, v);
                break;
            }
            case 2:
                printMatrix(adj, size);
                break;
            case 3: {
                int start;
                printf("Enter the starting node for DFS: ");
                scanf("%d", &start);
                DFS(adj, visited, start, size);
                break;
            }
            case 4: {
                int start;
                printf("Enter the starting node for BFS: ");
                scanf("%d", &start);
                BFS(adj, visited, start, size);
                break;
            }
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}



//MARK: 0/1 Knapsack
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



//MARK:Floyd warshall
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


//MARK: Transitive Closure
#include <stdio.h>

#define V 4

void warshallAlgorithm(int graph[V][V]) {
    int transitiveClosure[V][V];

    // Initialize the transitive closure matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            transitiveClosure[i][j] = graph[i][j];
        }
    }

    // Update the transitive closure matrix using Warshall's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                transitiveClosure[i][j] = transitiveClosure[i][j] ||
                    (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    // Print the transitive closure of the graph
    printf("Transitive Closure of the Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", transitiveClosure[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    warshallAlgorithm(graph);
    return 0;
}

//MARK:Huffman coding

// #include <iostream>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// struct Node {
//     char ch;
//     int freq;
//     Node* left;
//     Node* right;

//     Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
// };

// struct Compare {
//     bool operator()(Node* a, Node* b) {
//         return a->freq > b->freq;
//     }
// };

// void printCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
//     if (!root) return;

//     if (!root->left && !root->right)
//         huffmanCode[root->ch] = str;

//     printCodes(root->left, str + "0", huffmanCode);
//     printCodes(root->right, str + "1", huffmanCode);
// }

// void huffmanCoding(vector<pair<char, int>>& charFreq) {
//     priority_queue<Node*, vector<Node*>, Compare> pq;

//     for (auto& pair : charFreq)
//         pq.push(new Node(pair.first, pair.second));

//     while (pq.size() != 1) {
//         Node* left = pq.top(); pq.pop();
//         Node* right = pq.top(); pq.pop();
//         Node* sum = new Node('\0', left->freq + right->freq);
//         sum->left = left;
//         sum->right = right;
//         pq.push(sum);
//     }

//     unordered_map<char, string> huffmanCode;
//     printCodes(pq.top(), "", huffmanCode);

//     cout << "Huffman Codes:\n";
//     for (auto& pair : huffmanCode)
//         cout << pair.first << ": " << pair.second << endl;
// }

// int main() {
//     vector<pair<char, int>> charFreq = {
//         {'A', 5}, {'B', 9}, {'C', 12}, {'D', 13}, {'E', 16}, {'F', 45}
//     };

//     huffmanCoding(charFreq);
//     return 0;
// }



// MARK:Dijksta's Algo 
#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V] = {0};
    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 20},
        {10, 0, 10, 0, 0},
        {0, 10, 0, 30, 0},
        {0, 0, 30, 0, 0},
        {20, 0, 0, 0, 0}
    };
    
    int src = 0;
    dijkstra(graph, src);
    return 0;
}


//Quick Sort
// MARK: Quick Sort
#include <stdio.h>
#include <string.h>

// Define the structure for the data
typedef struct {
    char name[50];
    int score;
} Student;

// Function to swap two elements
void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(Student arr[], int low, int high) {
    int pivot = arr[high].score; // Choose the last element's score as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Sort in ascending order based on scores
        if (arr[j].score < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//Fractional Knapsack
// MARK: Fractional Knapsack
// Main function
int main() {
    // Input: Array of structures
    Student arr[] = {
        {"Alice", 50},
        {"Bob", 80},
        {"Charlie", 70},
        {"David", 90}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the array before sorting
    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Score: %d\n", arr[i].name, arr[i].score);
    }

    // Perform QuickSort
    quickSort(arr, 0, n - 1);

    // Display the array after sorting
    printf("\nArray after sorting (by score in ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Score: %d\n", arr[i].name, arr[i].score);
    }

    return 0;
}
// MARK:Merge Sort
#include <stdio.h>
#include <string.h>

void merge(char a[][20], int i1, int j1, int i2, int j2) {
    char temp[50][20]; // Temporary array for merging
    int i = i1;        // Beginning of the first subarray
    int j = i2;        // Beginning of the second subarray
    int k = 0;         // Index for temporary array

    // Merge the two arrays while comparing strings lexicographically
    while (i <= j1 && j <= j2) {
        if (strcmp(a[i], a[j]) < 0) {
            strcpy(temp[k++], a[i++]);
        } else {
            strcpy(temp[k++], a[j++]);
        }
    }

    // Copy the remaining elements of the first subarray, if any
    while (i <= j1) {
        strcpy(temp[k++], a[i++]);
    }

    // Copy the remaining elements of the second subarray, if any
    while (j <= j2) {
        strcpy(temp[k++], a[j++]);
    }

    // Transfer elements from temp[] back to a[]
    for (i = i1, k = 0; i <= j2; i++, k++) {
        strcpy(a[i], temp[k]);
    }
}

void mergesort(char a[][20], int i, int j) {
    int mid;

    if (i < j) {
        mid = (i + j) / 2;

        // Left recursion
        mergesort(a, i, mid);

        // Right recursion
        mergesort(a, mid + 1, j);

        // Merging of two sorted subarrays
        merge(a, i, mid, mid + 1, j);
    }
}

int main() {
    char a[30][20] = {"apple", "banana", "grape", "cherry", "date"};
    int n = 5; // Number of elements in the array

    printf("Unsorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");

    mergesort(a, 0, n - 1);

    printf("\nSorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");

    return 0;
}
// MARK: TOH
#include <stdio.h>

void towersOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towersOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towersOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3;
    printf("Towers of Hanoi for %d disks:\n", n);
    towersOfHanoi(n, 'A', 'C', 'B');
    return 0;
}


//MARK: BST
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* Lchild;
    int data;
    struct node* Rchild;
};

struct node* root = NULL;

// Function to create a new node
struct node* new_node_creation(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->Lchild = NULL;
    newnode->Rchild = NULL;
    return newnode;
}

// Function to insert a node into BST
void insertion(int val) {
    struct node* new_node = new_node_creation(val);
    struct node* curr = root, *parent;

    if (root == NULL) {  
        root = new_node;
    } else {
        while (1) {
            parent = curr;
            if (val < parent->data) {
                curr = curr->Lchild;
                if (curr == NULL) {
                    parent->Lchild = new_node;
                    break;
                }
            } else {
                curr = curr->Rchild;
                if (curr == NULL) {
                    parent->Rchild = new_node;
                    break;
                }
            }
        }
    }   
}

// Function to search for a key in the BST
int searchBST(struct node* root, int key) {
    if (root == NULL) {
        return 0;
    } else if (root->data == key) {
        return 1;
    } else if (key < root->data) {
        return searchBST(root->Lchild, key);
    } else {
        return searchBST(root->Rchild, key);
    }
}

// Function to find the minimum value node
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->Lchild != NULL) {
        current = current->Lchild;
    }
    return current;
}

// Function to delete a node from the BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->Lchild = deleteNode(root->Lchild, key);
    } else if (key > root->data) {
        root->Rchild = deleteNode(root->Rchild, key);
    } else {
        if (root->Lchild == NULL) {
            struct node* temp = root->Rchild;
            free(root);
            return temp;
        } else if (root->Rchild == NULL) {
            struct node* temp = root->Lchild;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->Rchild);
        root->data = temp->data;
        root->Rchild = deleteNode(root->Rchild, temp->data);
    }
    return root;
}

// Function for in-order traversal
void display_inorder(struct node* root) {
    if (root != NULL) {
        display_inorder(root->Lchild);
        printf("%d ", root->data);
        display_inorder(root->Rchild);
    }
}

// Main Function
int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display IN-ORDER\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                insertion(val);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &val);
                if (searchBST(root, val)) {
                    printf("Found\n");
                } else {
                    printf("Not found\n");
                }
                break;
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Node deleted successfully (if it existed).\n");
                break;
            case 4:
                printf("In-order Traversal: ");
                display_inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
