// A C++ program to check if a given graph is Eulerian or not
#include<iostream>
#include <list>
using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	Graph(int V) {this->V = V; adj = new list<int>[V]; }
	~Graph() { delete [] adj; } // To avoid memory leak

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Method to check if this graph is Eulerian or not
	int isEulerian();

	// Method to check if all non-zero degree vertices are connected
	bool isConnected();

	// Function to do DFS starting from v. Used in isConnected();
	void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
	// Mark all the vertices as not visited
	bool visited[V];
	int i;
	for (i = 0; i < V; i++)
		visited[i] = false;

	// Find a vertex with non-zero degree
	for (i = 0; i < V; i++)
		if (adj[i].size() != 0)
			break;

	// If there are no edges in the graph, return true
	if (i == V)
		return true;

	// Start DFS traversal from a vertex with non-zero degree
	DFSUtil(i, visited);

	// Check if all non-zero degree vertices are visited
	for (i = 0; i < V; i++)
	if (visited[i] == false && adj[i].size() > 0)
			return false;

	return true;
}

/* The function returns one of the following values
0 --> If grpah is not Eulerian
1 --> If graph has an Euler path (Semi-Eulerian)
2 --> If graph has an Euler Circuit (Eulerian) */
int Graph::isEulerian()
{
	// Check if all non-zero degree vertices are connected
	if (isConnected() == false)
		return 0;

	// Count vertices with odd degree
	int odd = 0;
	for (int i = 0; i < V; i++)
		if (adj[i].size() & 1)
			odd++;

	// If count is more than 2, then graph is not Eulerian
	if (odd > 2)
		return 0;

	// If odd count is 2, then semi-eulerian.
	// If odd count is 0, then eulerian
	// Note that odd count can never be 1 for undirected graph
	return (odd)? 1 : 2;
}

// Function to run test cases
void test(Graph &g)
{
	int res = g.isEulerian();
	if (res == 0)
		cout << "graph is not Eulerian\n";
	else if (res == 1)
		cout << "graph has a Euler path\n";
	else
		cout << "graph has a Euler cycle\n";
}

// Driver program to test above function
int main()
{
	// Graph with 5 edges
    int n, edge;
    cout<<"Enter the number of vertex: "<<endl;
    cin >> n;
    cout<<"Enter the number of edges: "<<endl; 
    cin>>edge;

	Graph g1(n);
    for (int i = 0; i<edge; i++) {
        int a, b, counter;
        counter = i+1 ;
        cout<<"Enter the vextex pair connected through edges: "<< counter<<endl;
        cin>>a>>b;
	g1.addEdge(a, b);
    ; 
    cout<<"Number of edges left: "<<edge - counter<< endl;
    }
	test(g1);



	return 0;
}
