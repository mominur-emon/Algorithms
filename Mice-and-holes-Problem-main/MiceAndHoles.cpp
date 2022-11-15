/*There are N Mice and N holes are placed in a straight line. Each hole only 1 mouse. A  mouse can stay at his position, move one step right from x to x + 1, or move one step left  from x to x-1. */
/* Any of these moves consumes 1minute. Assign mice to holes so that the  time when the last mouse gets inside a hole is minimized.*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mice_and_holes (int mice_positions[],int hole_positions[],int n)
{
    sort (mice_positions,mice_positions + n);
    sort (hole_positions, hole_positions + n);

    int ans = 0;

    for(int i=0; i<n; i++)
    {
        int temp=abs(mice_positions[i]-hole_positions[i]);
        ans = max(ans,temp);
    }
    return ans;

}

int main()
{
    int n,arr1[100],arr2[100];

    cout<<"Enter The Number of Mice & Holes ' N ':";
    cin>> n;

    cout<<"\n"<<"Enter The positions of mice are: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];

    }
    cout<<"Enter The positions of holes are: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];

    }

    cout<<"\n" << "The last mouse gets into the hole in time : " << mice_and_holes(arr1,arr2,n)<<"\n"<<endl;

    return 0;
}
