// implement recursive Binary Search
#include<iostream>
using namespace std;

int binary_Search(int arr[], int lower_bound, int upper_bound, int value)
{
	if (upper_bound >= lower_bound) {

		int mid_point = lower_bound + (upper_bound - lower_bound) / 2; //or (upper_bound+lower_bound)/2

		if (arr[mid_point] == value)
			return mid_point;

		else if (arr[mid_point] > value)
			return binary_Search(arr, lower_bound, mid_point - 1, value);

        else if(arr[mid_point] < value)
		   return binary_Search(arr, mid_point + 1, upper_bound, value);
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

    index = binary_Search(arr, lower_bound, upper_bound,value);

	 if(index==-1)
        cout<<"your value is not found.";
    else
        cout<<"your value is found at your position is "<< index;
	return 0;
}

