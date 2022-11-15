//***Linear Search implementation****//

#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int value)
{
	for (int i = 0; i < n; i++){
		if (arr[i] == value)
			return i;
	}
        return -1;

}


int main()
{
    int i,n,value;
    cout<<"Enter the number of element : ";
    cin>>n;
    cout<<"Enter your element : \n";
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"\nEnter search item in your list : ";
    cin>>value;

    int index = linear_search(arr,n,value);

    if(index == -1)
       cout<<" \nItem is not found.\n";
    else
        cout<<"\nItem is found at Index "<<index<<"\n";


    return 0;

}
