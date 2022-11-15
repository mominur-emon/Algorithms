/*Given two integers x and n, write a function to compute xn. */
/* We may assume that x and n 
are small and overflow doesn’t happen. You can’t use any built in power function and 
loops. Use divide and conquer approach to solve the problem.*/

#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int temp =1;
        temp = power(x, n / 2);
        if (n > 0)
        {
            if (n % 2 == 0)
            {
                return temp * temp;
            }
            else
            {
                return x * temp * temp;
            }
        }
        else
        {
            return 1/power(x,-n);
        }
    }
}
int main()
{       int x , n ;
        cout<<"Input X :";
        cin>>x;
        cout<<"Input N :";
        cin>>n;
        cout <<"\n"<<"Output :"<< power(x, n)<<"\n";
}
