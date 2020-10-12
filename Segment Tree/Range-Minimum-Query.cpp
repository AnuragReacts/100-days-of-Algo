// LINK:https://practice.geeksforgeeks.org/problems/range-minimum-query/1/?category[]=Segment-Tree&problemStatus=solved&page=1&query=category[]Segment-TreeproblemStatussolvedpage1
// PROBLEM STATEMENT:
// Given an array A[ ] and its size N your task is to
// complete two functions,a constructST function 
// which builds the segment tree and a function RMQ
// which finds range minimum query in a segment tree 
// Example:
// Input
// 1
// 4
// 1 2 3 4
// 2
// 0 2 2 3
//
// Output
// 1 3


#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;
        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */

int constructSTUtil(int arr[],int* st,int start,int end,int treeNode){
    if(start==end){
        st[treeNode]=arr[start];
        return st[treeNode];
    }
    int mid=(start+end)/2;
    st[treeNode]=min(constructSTUtil(arr,st,start,mid,2*treeNode),constructSTUtil(arr,st,mid+1,end,2*treeNode+1));
    return st[treeNode];
}

int *constructST(int arr[],int n)
{
  //Your code here
  //int size=pow(2,ceil(log2(n)));
  int* st=new int[2*n];
  constructSTUtil(arr,st,0,n-1,1);
  return st;
}

int RMQUtil(int st[],int start,int end,int a,int b,int treeNode){
    if(start>=a&&end<=b){
        return st[treeNode];
    }else if(a>end||b<start)
    return INT_MAX;
    int mid=(start+end)/2;
    return min(RMQUtil(st,start,mid,a,b,2*treeNode),RMQUtil(st,mid+1,end,a,b,2*treeNode+1));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return RMQUtil(st,0,n-1,a,b,1);
}