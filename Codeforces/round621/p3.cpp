#include<bits/stdc++.h>

using namespace std;
// Program to find Dijkstra's shortest path using STL set 

# define INF 0x3f3f3f3f 

// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// In a weighted graph, we need to store vertex 
	// and weight pair for every edge 
	list< pair<int, int> > *adj; 

public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int u, int v, int w); 

	// prints shortest path from s 
	void shortestPath(int s, vector<int> &dist); 
}; 

// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list< pair<int, int> >[V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src, vector<int> &dist) 
{ 
	// Create a set to store vertices that are being 
	// prerocessed 
	set< pair<int, int> > setds; 

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 

	// Insert source itself in Set and initialize its 
	// distance as 0. 
	setds.insert(make_pair(0, src)); 
	dist[src] = 0; 

	/* Looping till all shortest distance are finalized 
	then setds will become empty */
	while (!setds.empty()) 
	{ 
		// The first vertex in Set is the minimum distance 
		// vertex, extract it from set. 
		pair<int, int> tmp = *(setds.begin()); 
		setds.erase(setds.begin()); 

		// vertex label is stored in second of pair (it 
		// has to be done this way to keep the vertices 
		// sorted distance (distance must be first item 
		// in pair) 
		int u = tmp.second; 

		// 'i' is used to get all adjacent vertices of a vertex 
		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is shorter path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				/* If distance of v is not INF then it must be in 
					our set, so removing it and inserting again 
					with updated less distance. 
					Note : We extract only those vertices from Set 
					for which distance is finalized. So for them, 
					we would never reach here. */
				if (dist[v] != INF) 
					setds.erase(setds.find(make_pair(dist[v], v))); 

				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				setds.insert(make_pair(dist[v], v)); 
			} 
		} 
	} 

	// Print shortest distances stored in dist[] 
	
} 

// Driver program to test methods of graph class 


int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> graph[n + 1];
    int special[k];
    set<int> sf;
    for(int i = 0 ; i <  k ; i++){
        scanf("%d", &special[i]);
        sf.insert(special[i]);
    }
    bool exists = false;
    Graph g(n + 1);
    
    for(int i = 0 ;  i < m ; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
        g.addEdge(x, y, 1);
        if(sf.find(x) != sf.end() && sf.find(y) != sf.end()){
            exists = true;
        }

    }
    if(exists){


        vector<int> dist1(n + 1, INF);
        g.shortestPath(1, dist1);
        int min_dist = dist1[n];
        printf("%d\n", min_dist);
    }
    else{
        
	        vector<int> dist1(n + 1, INF); 
            g.shortestPath(1, dist1);
            vector<int> distn(n + 1, INF);
            g.shortestPath(n, distn);
            int min_dist = distn[1];
            int max = 0 ;
            for(int i = 0 ; i < k ; i++){
                for(int j = i + 1 ; j < k ; j ++){
                    int temp = min(dist1[special[i]] + 1 + distn[special[j]], dist1[special[j]] + 1 + distn[special[i]]);
                    if(temp >= min_dist){
                        goto outer; 
                    }
                    if(max < temp){
                        max = temp;
                    }
                    
                }
            }
            if(max < min_dist){
                min_dist = max;
            }
            outer : printf("%d\n", min_dist);
    }

}