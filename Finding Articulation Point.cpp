///Umme Kawser Sinthia
///Roll: 201136

#include <bits/stdc++.h>
#define MAX 9999
using namespace std;

void Read_Input();
void Dfs(int i);
void Root_Specialcase();
void Print_All ();
void Dfs(int);

int vertex, edge, root[MAX], child[MAX], low[MAX], time1[MAX];
bool visited[MAX], ap[MAX];

vector <vector <int> > arr(MAX);       //adjacency graph

int main()
{
    Read_Input();

    root[1] = -1;
    Dfs(1);

    Root_Specialcase();
    Print_All ();

    return 0;
}


void Root_Specialcase()              //root must have atleast two independent children
{
    if (child[1] > 1)
        ap[1] = true;
    else
        ap[1] = false;
}

void Dfs(int i)
{
    static int count1=0;
    int temp;

    visited[i] = true;                  // visited (root from where we starting)

    low[i] = count1++;
    time1[i] = count1++;
    //time1[i] = ;

    for(int j = 0; j < arr[i].size(); j++)
    {
        temp = arr[i][j];

        if(temp == root[i])
            continue;               // Skip if temp is its root

        if(!visited[temp])
        {
            child[i]++;             // another  child of i
            root[temp] = i;
            Dfs(temp);

            low[i] = min(low[i], low[temp]);


            if(low[temp] >= time1[i])
                ap[i] = true;
        }
        else
            low[i] = min(low[i],time1[temp]);

    }
}


void Read_Input ()
{
    int u, v;

    cout << "Enter Number of Vertices: ";
    cin >> vertex;
    cout << "Enter Number of Edges: ";
    cin >> edge;

    cout << "Enter vertices that has an edge between them:  " << endl;
    for(int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
}


void Print_All ()
{
    cout << "Articulation Points in the Graph:  "<< endl;

    for (int i = 0; i < vertex; i++)
    {
        if(ap[i])
            cout << i << " "<< endl;
    }

}

/*
4
3
0 1
1 2
2 3


5
5
1 0
0 2
2 1
0 3
3 4

7
8
0 1
1 2
2 0
1 3
1 4
1 6
3 5
4 5

*/


