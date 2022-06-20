//
#include <iostream>
using namespace std;
#define V 7
#define INT_MAX 999
int adjMatrix[V][V];
int parent[V];
int weighted[V];
bool visited[V];
// Initialize the Adjacncy Matrix to zero
void initialize()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}
// Add Edges in the graph
void addEdges(int i, int j)
{
    // Undirected Graph
    int weight;
    cout << i << " ---> " << j << " Weight>> ";
    cin >> weight;
    adjMatrix[i][j] = weight;
    adjMatrix[j][i] = weight;
    // Directed Graph
    // arr[i][j] = 1;
}
// Diplay Adjacency Matrix
void display()
{
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex: " << i << " Edges: ";
        for (int j = 0; j < V; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
// Finding Minimum Vertex
int findMinVertex()
{
    int minVertex = -1;
    for (int i = 0; i < V; i++)
    {
        //It shouldn't be visited & if minVertex is -1 then without comparison update the minVertex Because -1 is not exits as an indexx
        if (!visited[i] && (minVertex == -1 || (weighted[i] < weighted[minVertex])))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

// Prim's Algorithm
void prims()
{
    // Setting all the distances to infinity & Mark all the vertices unvisited by assigning it to false
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        weighted[i] = INT_MAX;
    }
    // This Case is for First Vertex Because zero ahs not any parent and 0--->0 is also 0(weight) that's why we mark it as 0
    parent[0] = -1;
    weighted[0] = 0;

    for (int i = 0; i < V; i++)
    {
        int minVertex = findMinVertex();
        visited[minVertex] = true;
        //Now Start Exploring Un visited Vertexes 
        for (int j = 0; j < V; j++)
        {
            //If there is an edge between minVertex and j then it will definitely be a neghbour of each other and it shouldn't be true
            if (adjMatrix[minVertex][j] != 0 && !(visited[j]))
            {
                //If the weight of this edge is better then the previous weight than now we should update it and new weight of j is this respective edge 
                if (adjMatrix[minVertex][j] < weighted[j])
                {
                    weighted[j] = adjMatrix[minVertex][j];
                    //As we come to this edge by using minVertex so now the parent of j should be j.
                    parent[j] = minVertex;
                }  
            } 
        }  
    }
    for (int i = 1; i < V; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " ---> " << i << " weight: " << weighted[i] << endl;
        }else
        {
            cout << i << " ---> " << parent[i] << " weight: " << weighted[i] << endl;
        }  
    }
    
}

int main()
{
    // Initialize the MAtrix with 0
    initialize();
    addEdges(0, 1);
    addEdges(0, 3);
    addEdges(1, 2);
    addEdges(1, 4);
    addEdges(3, 5);
    addEdges(3, 2);
    addEdges(2, 5);
    addEdges(2, 6);
    addEdges(6, 4);
    // addEdges(5, 1);
    // addEdges(1, 6);
    display();
    cout << "Prims: ";
    prims();
    return 0;
}
