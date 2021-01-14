//Ezekial Page
//Dijkstra's algorithm

//import libraries
#include <stdio.h>
#include <limits.h>

//creates function
int small(int x[], int y[]);
main(){
    int inf = INT_MAX;

    //set up matrix
    int matrix[4][4] = {{ inf ,  3  , inf ,  7  },
                        {  3  , inf ,  8  , inf },
                        { inf ,  8  , inf ,  2  },
                        {  7  , inf ,  2  , inf}};

    //set up tables
    int visited[] = {-1, -1, -1, -1};
    int shortest[] = {0, inf, inf, inf};
    int prev[] = {0, -1, -1, -1};

    //create loop variables
    int i;
    int j;
    int prevNode = 0;
    int s;
    int l;
    int p;

    //loop through to find unvisited nodes
    for(i = 0; i < 4; i++){
        //determine pivot node
        s = small(shortest, visited);
        visited[s] = 0;
        printf("%d\n",s);

        prevNode = s;
        //find node distances
        for(j = 0;j < 4;j++){
            //if shorter path is found replace in shortest array
            printf("%d %d %d %d\n",matrix[s][j],shortest[j], prevNode ,shortest[prevNode]);
            if((matrix[s][j] < shortest[j])&&(visited[j] == -1)){
                //printf("%d %d\n",matrix[s][j],prevNode);
                p = matrix[s][j] + shortest[prevNode];
                if(p < shortest[j]){
                    printf("replaced %d with %d\n", shortest[j], matrix[s][j] + shortest[prevNode]);
                    shortest[j] = matrix[s][j] + shortest[prevNode];
                }
            }
        }
        //label previous node before changing to next node
        //[i] = s;
        //prevNode = s;
        printf("p %d %d\n", prevNode, shortest[prevNode]);
    }

    for(l = 2; l<5;l++){
        printf("Shortest path from node 1 to node %d is: %d\n",l,shortest[l-1]);
    }
}

//calculates the smallest value in an array
int small(int x[4], int y[4]){
    int z;
    int ret;
    int k;
    int low = INT_MAX;

    for(k = 0; k < 4;k++){
        if((x[k]<low)&&(y[k] == -1)){
            low = x[k];
        }
    }

    for(z = 0; z < 4; z++){
        if(x[z]==low){
            ret = z;
        }
    }
    return ret;
}
