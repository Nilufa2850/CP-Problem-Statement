/*Given an integer array nums , return an array answer such that answer[i] is equal to the
product of all the elements of nums except nums[i] .
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division
operation

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
#include<iostream>
#include<math.h>
using namespace std ;
int divided (int numerator , int denomirator) ;

int main ()
{
    int n ;
    cout<<"Enter size ";
    cin>>n ;

    int ary [n] , answer[n];

    int i,j ,multi=1 , countZero = 0 ;

    cout<<"Enter "<<n<<" number for array "<<endl ;

    for(i=0 ; i<n ; i++)
        cin>>ary[i] ;

    for(i=0 ; i<n ; i++)
    {
        if (ary[i] == 0)
            countZero++ ;
        else
            multi = multi*ary[i] ;   
    }

    for(i=0 ; i<n ; i++)  
    {
        if(countZero > 1)
            answer[i] = 0 ;

        else if(countZero == 1)
        {
            if(ary[i]!=0)
                answer[i]=0 ;
            else
                answer[i]=multi ;
        }
        else
            answer[i] = divided(multi , ary[i]) ;   
    }

    for(i=0 ; i<n ; i++)
        cout<<answer[i] <<" " ;
    return 0 ;
}

int divided (int numerator , int denomirator)
{
    if (numerator == 0)
        return 0 ;
    else if (denomirator == 0) 
        return 0 ;

    int sign ;
    sign = ( (numerator < 0) ^ (denomirator < 0) ) ;

    numerator = abs(numerator) ;
    denomirator = abs(denomirator) ;

    if (denomirator == 1)
        return (sign==0) ? numerator : -numerator  ;

    int ans ;
    ans = exp(log(numerator)-log(denomirator)) + 0.00000001 ;

    return (sign==0) ? ans : -ans ;

}
