#include "../heads.h"

#include <list>
#include <vector>

/* flights[i] = [from-i, to-i, price-i]
 */

int dfs_visit(){};


int f(int n,vector<vector<int>>& flight,
      int src, int dst, int k){
 /* at most k stops
  * n cites
  * return cheapest price
  */
    
    /* adj_matrix 
     * idk whether sparse or dense
     */ 
    /*
    int** adj_matrix = new int*[n];
    for(int i=0; i<n; i++){
        adj_matrix[n] = new int[n]{0};
    }
    for(int i=0; i<flight.size(); i++){
        int c1 = flight[i][0];
        int c2 = flight[i][1];
        adj_matrix[c1][c2] = flight[i][2];
    }
    */
    
    /* adj_list */
    struct adj_info {
        int dst;
        int weight;
    };
    
    list<adj_info>* vinfo = new list<adj_info>[n];
    for(int i=0; i<flight.size(); i++){
        int c1 = flight[i][0];
        int c2 = flight[i][1];
        int w  = flight[i][2];
        vinfo[c1].push_back(adj_info{c2, w});
    }

    /* DFS */
    /* 0=white, 1=gray, -1=black*/
    vector<int> u_color(n,0);
    vector<int> u_pi(n,0);
    vector<int> u_d(n,0);
    int time = 0;

    for(int i=0; i<n; i++){
        if(u_color[i]==0) {
            /* DFS-VISIT */
            time++;
            /*
             * here i need a recall DFS-vist;
             */
        }
    }
                


     
    





}
