#include <iostream>
using namespace std;
#define V 7
#define INT_MAX 999
int adjMatrix[V][V];
bool visited[V];
int distances[V];

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
//Finding Minimum Vertex
int findMinVertex()
{
    int minVertex = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && (minVertex == -1 || distances[i] < distances[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

// Dijkstra Algorithm
void dijkystra()
{
    int minVertex;
    //Setting all the distances to infinity & Mark all the vertices unvisited by assigning it to false
    for (int i = 0; i < V; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    //Source Distance to 0.
    distances[0] = 0;
    //Finding the vertex with minimum distance
    for (int i = 0; i < V; i++)
    {
        minVertex = findMinVertex();
        visited[minVertex] = true;
        // For CHecking The Current Vertex has its neighbour or not
        for (int j = 0; j < V; j++)
        {
            if (adjMatrix[minVertex][j] != 0 && !visited[j])
            {
                //Adding previous distance to new minimum Shortest Distance
                int dist = distances[minVertex] + adjMatrix[minVertex][j];
                if (dist < distances[j])
                {
                    distances[j] = dist;
                }
            }
        }
    }
    for (int i = 1; i < V; i++)
    {
        cout << "Node: " << i << "  Distance: " << distances[i] << endl;
    }
}
int main()
{
    // Initialize the MAtrix with 0
    initialize();
    addEdges(0, 1);
    addEdges(0, 3);
    addEdges(1, 4);
    addEdges(3, 5);
    addEdges(3, 2);
    // addEdges(2, 5);
    // addEdges(2, 6);
    // addEdges(6, 4);
    // addEdges(5, 1);
    // addEdges(1, 6);
    // display();
    cout << "<<<<<<<<<<<<<<<< Dijkystra  >>>>>>>>>>>>>>> "<< endl;
    dijkystra();
    return 0;
}
