#include<bits/stdc++.h>

using namespace std;

/*
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = Arr[ i ];
    }
    return i;
}

modified union function where we connect the elements by changing the root of one of the element 

int unionDsu(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}
bool findDsu(int arr[], int A,int B)
{
    if( root(arr, A)==root(arr, B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}


int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
            int v, e;
            int arr[v];
            for(int i = 0 ; i < v ; i++){
                arr[i] = i;
            }
            while(e-- != 0){
                int x, y;
                scanf("%d %d", &x, &y);
                arr
            }
    }
}*/

// { Driver Code Starts
//Initial template

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V); 
	void addEdge(int v, int w);
	bool isBridge(int u, int v);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver Program
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int s,N;
        cin>>s>>N;
        Graph *g = new Graph(s);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        int a,b;
        cin>>a>>b;
        
         if(g->isBridge(a, b))
            cout<<1<<endl;
        else
             cout<<0<<endl;
         }
}
// } Driver Code Ends
// your task is to complete this function


/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isBridge();
};*/

int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root.
    {
     i = Arr[ i ];
    }
    return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

void uniondsu(int Arr[ ] ,int A ,int B)
{
    int root_A = root(Arr, A);       
    int root_B = root(Arr, B);  
    Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}
bool find(int arr[], int A,int B)
{
    if( root(arr, A)==root(arr, B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}

bool Graph::isBridge(int u, int v )
{
    int arr[V];
    for(int i = 0 ; i < V ; i++){
        arr[i] = i;
    }
    for(int i = 0 ; i < V ; i++){
        list<int> :: iterator it = adj[i].begin();
        while(it != adj[i].end()){
            //cout << *it <<  ' ';
            if(!((i == u && v == *it) || (i == v && *it == u)))
                uniondsu(arr, i, *it);
            it++;
        }
    }
       if(root(arr, u) == root(arr, v)){
           return false;
        
       } 
       else{
           return true;
       }
    
 
}