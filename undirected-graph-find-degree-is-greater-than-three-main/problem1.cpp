/*undirected graph as input using adjacency list and find those nodes which degree is greater than 3.*/

#include<stdio.h>
#include<vector>

using namespace std;

vector<int>g[100] ;
void simpleOrmulti(int node){
    bool flag1 = false ;
    bool flag2 = false ;

    for(int i = 0 ; i < node ; i++){
        for(int j = 0 ; j < g[i].size() ; j++){
            if(i == g[i][j]){
                flag1 = true ;
                break ;
            }

            for(int k = j ; k < g[i].size() ; k++){
                if(g[i][j] == g[i][k]){
                    flag2 = true ;
                    break ;
                }
            }
        }
    }

}
void printDegree(int node){

    int i ;
    for(i = 0 ; i < node ; i++){
        if (g[i].size()>3)

        printf("%d -> ", i) ;
        printf("%d\n", g[i].size()) ;
    }
}
void printAdjList(int node){
    int i, j ;
    for(i = 0 ; i < node ; i++){
        printf("%d -> ", i) ;
        for(j = 0 ; j < g[i].size() ; j++){
            printf("%d ", g[i][j]) ;
        }
        printf("\n") ;
    }
}
int main()
{
    int n, u, v, edge, i ;
    printf("Enter Number of node and edge: ");
    scanf("%d %d", &n, &edge) ;
    printf("Enter U and  V :  ");
    for(i = 0 ; i < edge ; i++){
        scanf("%d %d", &u, &v) ;
        if(u == v)
            g[u].push_back(v) ;
        else{
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }
    }
    printAdjList(n) ;
    printDegree(n) ;
    simpleOrmulti(n) ;
}
