// since the edges are not weighed so i have considered that each edge is of same length
#include<iostream> 
#include<vector>
#include<list>

using namespace std;
vector<vector<int> > v;// to store paths in between two vertices

// Graph class represents a graph using adjacency list representation 
class Graph 
{ 
    int V;// No. of vertices  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by printAllPaths()
    void findAllPathsUtil(int v1, int v2, bool visited[], int path[], int index); 
public: 
    Graph(int V);   // Constructor 
    bool pathExist; //variable to indicate if path exist or not
    // function to add an edge to graph 
    void addEdge(int v, int w); 
    void findAllPaths(int v1, int v2);
    
};
 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
}
 
void Graph::findAllPathsUtil(int v1, int v2, bool visited[], int path[], int index) 
{ 
    // Mark the current node as visited and store it in path[] 
    visited[v1] = true;
    path[index]=v1;
    index++;
    // If current vertex is same as v2, then print 
	// current path[] 
    if(v1==v2){
        int i;
		pathExist=true;
        vector<int> temp; // temporary vector to store nodes
        for(i=0;i<index-1;i++)
        {
			temp.push_back(path[i]); // adding nodes to temporaray vector
		}
        temp.push_back(path[i]);
        v.push_back(temp);// adding path to the original vector
    }
    else{ // If current vertex is not v2 Recur for all the vertices adjacent  to this vertex 
        list<int>::iterator i; 
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i) 
            if (!visited[*i]) 
                findAllPathsUtil(*i, v2, visited, path, index); 
    }
    // Remove current vertex from path[] and mark it as unvisited 
    index--;
    visited[v1]=false;
} 

void Graph::findAllPaths(int v1, int v2) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
        
    // Create an array to store paths 
    int *path = new int[V];
    
    // Initialize path[] as empty 
    int index = 0;
    
    pathExist=false;
    
    // Call the recursive helper function to find all paths 
    findAllPathsUtil(v1,v2,visited,path,index);   
} 
// Driver code 
int main() 
{
    // Creating a graph with 8 vertices
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1, 3); 
	g.addEdge(2, 1); 
	g.addEdge(3, 2); 
	g.addEdge(3, 4); 
	g.addEdge(4, 5); 
	g.addEdge(6, 4);
	g.addEdge(5,7);
	g.addEdge(7,6);
	g.addEdge(0,2);
	g.addEdge(2,6);
	int v1=0, v2=6;
	int a,b,len;// for source , destination and length n specifically
	cout<<"Enter the source : ";
	cin>>a;
	cout<<"Enter the destination : ";
	cin>>b;
	cout<<"Enter the length n : ";
	cin>>len;
	g.findAllPaths(a,b);
int count=0;
for(int i=0;i<v.size();i++)// for comparing lengths of all paths with the entered length 'len'
{
	vector<int > temp;
	temp=v[i];
	if((temp.size()-1)==len)
	count++;
	temp.pop_back();
}
cout<<endl;
if(count)
cout<<"Number of paths exists of length "<<len<<" between "<<a<<" and "<<b<<" are : "<<count<<endl;
else
cout<<"No such path exists!"<<endl;
}
