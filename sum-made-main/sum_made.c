/*Take n numbers of input from user as well as a sum. Now determine whether the sum is made using the numbers. If yes print the number.*/

#include <stdio.h>

int sum_find(int Set[], int number, int sum){

	int set[number + 1][sum + 1];

	for (int i = 0; i <= number; i++){
        set[i][0] = 1;
	}

	for (int j = 1; j <= sum; j++){
        set[0][j] = 0;
	}

	for (int i = 1; i <= number; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < Set[i - 1])
                set[i][j] = set[i - 1][j];
            else {
                set[i][j] = set[i - 1][j]|| set[i - 1][j - Set[i - 1]];
		      }
		}
	}
	return set[number][sum];


}

int main()
{

    int i,set[100], sum,number;

    printf("Enter number of items: ");
    scanf("%d", &number);

    printf("Enter number element of items :\n");
    for(i = 0;i < number; i++){
    	scanf("%d", &set[i]);
    }

    printf("Enter the sum is made using number : ");
    scanf("%d", &sum);

	if (sum_find(set, number, sum) == 1){
        printf("\n YES. sum of %d  is made.\n",sum);
	}
	else{
        printf("\n No. sum of %d can't be made.\n",sum);
	}

	return 0;
}

