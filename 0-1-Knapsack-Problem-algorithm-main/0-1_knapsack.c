/*Input the number of item. enter weights and values of  items, put these items in a knapsack of capacity  to get the maximum total value in the knapsack.*/

#include<stdio.h>

int max(int p , int q ) {
   if (p>q)
    return p;
   else
    return q;
}


void print_knapsack(int weight, int wt[], int v[], int Number){

    int i, j;
    int pf [Number+1][weight+1];


    for(int i=0; i <= Number; i++)
            pf[i][0] = 0;
     for(int j=0; j <= weight; j++)
            pf[0][j] = 0;


    for (i = 1; i <= Number; i++){

        for (j = 1; j <= weight; j++){

            if (wt[i-1] <= j){
                pf[i][j] = max(v[i-1] + pf[i-1][j-wt[i-1]],  pf[i-1][j]);
            }
            else{
               pf[i][j] = pf[i-1][j];
            }
        }
    }
    int result = pf[Number][weight];
    printf("%d\n", result);

    j = weight;
    for (i = Number; i > 0 && result > 0; i--)
    {
        if (result == pf[i - 1][j])
            continue;
        else
        {
            printf("%d ", wt[i - 1]);
            result = result - v[i - 1];
            j = j - wt[i - 1];
        }
    }
}

int main()
{
    int i, Number, v[100], wt[100], weight;

    printf("Enter number of items: ");
    scanf("%d", &Number);

    printf("Enter value and weight :\n");
    for(i = 0;i < Number; i++){
    	scanf("%d%d", &v[i], &wt[i]);
    }

    printf("Enter size of knapsack: ");
    scanf("%d", &weight);


    printf("Maximum profit are: ");
    print_knapsack(weight, wt, v,Number);


    return 0;
}

