///Umme Kawser Sinthia
///Roll: 201136

#include<iostream>
#define size 10
using namespace std;

void Read_Input();
void Visit();

void DFS();
void Dfs_Traversal(int i);
void push(int a);

void ArrTranspose();
void Count_Finish();
void DFS2();
void Dfs_Traversal2(int i);



int arr[size][size], visited[size], vertex, source, arrT[size][size];
int top = -1, Topo[size], scc[size];


int main()
{
    Read_Input();           //User input the graph by adjacent matrix

    cout << "The Strongly Connected Components of the Graph : ";


    Visit();               // initially for all vertex of a graph is 0 (white)
    DFS();                // Calling DFS for the given graph
    ArrTranspose();      // Transposing the given graph
    Count_Finish();     // Based on finishing time inserting into a Stack
    Visit ();

    DFS2();           // Calling DFS again for the transpose graph and
                     //checking if its based on the finishing time of the first DFS

    return 0;
}

void Visit ()
{
 for(int i = 0 ; i < vertex ; i++)          //initially visited for all vertices is zero
        visited[i]=0;
}

void ArrTranspose ()
{
    for(int i = 0; i < vertex; i++)
    {
        for(int j = 0; j < vertex; j++)
        {
            arrT[i][j] = arr[j][i];
        }
    }

}


void DFS ()
{
    for ( int i = 0 ; i < vertex ; i++ )
        if(visited[i] == 0)             //for all vertices calling the traverse function
        {
            Dfs_Traversal(i);
        }
}


void Dfs_Traversal(int i)
{
    int j;
    visited[i] = 1;         //identifying black vertex by 1

	for( j = 0 ; j < vertex ; j++)
    {
        if(visited[j] != 1 && arr[i][j] == 1 )    // If vertex not visited and has an edge
            Dfs_Traversal(j);
    }

    push(i);
}


void DFS2 ()
{
    for ( int i = 0 ; i < vertex ; i++ )
        if(visited[i] == 0)             //for all vertices calling the traverse function
        {
            cout << endl;
            Dfs_Traversal2(i);
        }
}

void Dfs_Traversal2(int i)
{
    int j, count=0;
	cout << i << " ";
    visited[i] = 1;         //identifying black vertex by 1

	for( j = 0 ; j < vertex ; j++)
    {
        if(visited[j] != 1 && arrT[i][j] == 1)    // If vertex not visited and has an edge
        {
           for(int k = 0; k < vertex; k++)       //if that node is in scc[]
           {
                if(scc[k] == i)                  //considering vertices in order of decreasing finish time
                    if(vertex-1 >= k)
                        Dfs_Traversal2(j);
           }

        }

    }

}



void Count_Finish ()
{
    int j = 0;
    for(int i = vertex-1 ; i >= 0 ; i--)
    {
        scc[j] = Topo[i];               //scc[] has elements in decreasing finishing order (as per index)
        j++;
    }
}

void push (int a)
{
    top++;
    Topo[top] = a;
}


void Read_Input ()
{
    int i,j;
    cout << "Enter number of vertices: ";
    cin >> vertex;

	cout << "Enter the adjecency matrix of the graph: " << endl;

	for( i = 0 ; i < vertex ; i++ )
    {
        for( j = 0 ; j < vertex ; j++ )
		{
		    cin >> arr[i][j];
		}
    }
}

/*
5
0 0 1 1 0
1 0 0 0 0
0 1 0 0 0
0 0 0 0 1
0 0 0 0 0

*/





