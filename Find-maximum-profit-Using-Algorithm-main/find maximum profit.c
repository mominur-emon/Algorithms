/*Given n number of products with their weight and price. find maximum profit that can be made from those product having a sack with fixed capacity. Capacity of the sack is also given as input.  And may take product partially.*/

# include<stdio.h>

void knapsack(int n, float weight[], float price[], float capacity)
{
   float x[20], tp = 0;
   int i, j, C;
   C = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;
   for (i = 0; i < n; i++)
 {
      if (weight[i] > C)
         break;

      else
     {
         x[i] = 1.0;
         tp = tp + price[i];
         C = C - weight[i];
      }
   }

   if (i < n)
      x[i] = C / weight[i];
   tp = tp + (x[i] * price[i]);

   printf("\n Maximum profit that can be made from those product: %f", tp);
   printf("\n");

}

int main() {
   float weight[20], price[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\n Enter the given n number of products: ");
   scanf("%d", &num);

   printf("\nEnter the weight and price of each products: ");
   for (i = 0; i < num; i++)
  {
      scanf(" %f %f", &weight[i], &price[i]);
   }

   printf("\n Enter the fixed capacity :  ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++)
  {
      ratio[i] = price[i] / weight[i];
   }

   for (i = 0; i < num; i++)
 {
      for (j = i + 1; j < num; j++)
    {
         if (ratio[i] < ratio[j])
        {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = price[j];
            price[j] = price[i];
            price[i] = temp;
         }
      }
   }

   knapsack(num, weight, price, capacity);

   return(0);


}
