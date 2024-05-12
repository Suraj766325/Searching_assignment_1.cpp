// Q1) Given a sorted array of n elements and a target ‘x’. Find the last occurrence of ‘x’ in the array. If ‘x’ does not exist return -1.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={1,2,3,3,4,4,4,5};
    int target=6,l=0,r=v.size()-1,mid,checking=1;
    bool flag=false;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(target==v[mid]) 
        {
            flag=true;
            break;
        }
        else if(target>v[mid]) l=mid+1;
        else                   r=mid-1;
    }
    if(flag==true)
    {
        while(mid<v.size() && target==v[mid])
        mid++;
        cout<<"last occurence = "<<mid-1;
    }
    else
    cout<<-1;
}




// Q2) Given a sorted binary array, efficiently count the total number of 1’s in it.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={0,0,0,0,1,1};
    int target=0,l=0,r=v.size()-1,mid,x,count=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(target==v[mid]) break;
        else if(target>=v[mid]) l=mid+1;
        else                 r=mid-1;
    }
    x=mid;
    //countijng left side
    while(mid>=0 && target==v[mid]) 
    {
        count++;
        mid--;
    }
    //counting right side
    while(x<v.size()&& target==v[x])
    {
        count++;
        x++;
    }
    cout<<"total number = "<<count-1;
}




// Q3) Given a matrix having 0-1 only where each row is sorted in increasing order, find the row with the maximum number of 1’s.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int countt(vector<vector<int>>&v,int j)
{
    int n=v[j].size(),l=0,r=n-1,mid;
    bool flag=false;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(1==v[j][mid])
        {
            flag=true;
            break;
        }
        else
            l=mid+1;
    }
    if(flag==true){
        //min index of 1
        while(mid>=0 && 1==v[j][mid])
        mid--;
        return n-1-mid;
    }
    else return 0;
}
int main()
{
    vector<vector<int>>v={{0,0,1,1},{1,1,1,1},{0,0,0,0},{1,1,1,1,1,1}};
    int n=v.size(),i,m=INT_MIN,x,count,l;
    for(i=0;i<n;i++)
    {
        count=countt(v,i);
        if(count>m)
        {
            m=count;
            x=i;
         
        }
    }
    cout<<"row having maximum 1's = "<<x+1<<endl;
    cout<<"max 1's = "<<m;
}


//Q4) Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n]inclusive in sorted order.There is only one repeated number in nums, return this repeated number.
#include<iostream>
#include<vector>
using namespace std;
int main ()
{
    vector<int>v={1,2,3,4,4};
    int l=0,r=v.size()-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(v[mid]==mid+1) l=mid+1;
        else            r=mid-1; 
    }
    cout<<v[l-1];
}




//Q5) Given a number ‘n’. Predict whether ‘n’ is a valid perfect square or not.
#include<iostream>
using namespace std;
int main()
{
    int n=35,l=0,r=n,mid;
    bool flag= false;
    while(l<=r)
    {
        mid=(r+l)/2;
        if(n==mid*mid) 
        {
            flag=true;
            break;
        }
        else if(n>mid*mid) l=mid+1;
        else               r=mid-1;
    }
    if(flag==true) cout<<"perfect square";
    else           cout<<"not prefect square";
}




//Q6) You have n coins and you want to build a staircase with these coins. The staircase consists of krows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
//Given the integer n, return the number of complete rows of the staircase you will build.
#include<iostream>
using namespace std;
int main()
{
    int n=16,l=0,r=n,mid;
    bool flag=false;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(n==(mid*(mid+1))/2) 
        {
            flag=true;
            break;
        }
        else if(n>(mid*(mid+1))/2) l=mid+1;
        else                       r=mid-1;
    }
    if(flag==true) cout<<mid;
    else           cout<<r;
}
