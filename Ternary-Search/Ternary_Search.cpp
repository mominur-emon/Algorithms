// implement ternary Search
#include<iostream>
using namespace std;

int Ternary_Search(int arr[], int lower_bound, int upper_bound, int value)
{
	if (upper_bound >= lower_bound) {

		int mid_point1 = lower_bound + (upper_bound - lower_bound) / 3;
		int mid_point2 = mid_point1 + (upper_bound - lower_bound) / 3;

		if (arr[mid_point1] == value)
			return mid_point1;

        else if (arr[mid_point2] == value)
			return mid_point2;

		else if (arr[mid_point1] > value)
			return Ternary_Search(arr, lower_bound, mid_point1 - 1, value);

        else if(arr[mid_point2] < value)
		   return Ternary_Search(arr, mid_point2 + 1, upper_bound, value);

        else
            return Ternary_Search(arr, mid_point1 + 1, mid_point2 - 1, value);//3rd mid point part
	}
	return -1;
}

int main()
{

	int i,n,index,value;

    cout<<"Enter the number of element : ";
    cin>>n;
    cout<<"Enter your element by sorted order: \n";
    int arr[n];//create an array of size n
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter your search Value : ";
    cin>>value;

    int lower_bound=0,upper_bound=n-1;

    index = Ternary_Search(arr, lower_bound, upper_bound,value);

	 if(index==-1)
        cout<<"your value is not found.";
    else
        cout<<"your value is found at your position is "<< index;
	return 0;
}


