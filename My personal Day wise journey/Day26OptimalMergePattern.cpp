#include<bits/stdc++.h>
using namespace std;
int getOptimalCount(int arr[],int size){
   //create minHeap
   priority_queue<int,vector<int>,greater<int>> pq;
   for(int i=0;i<size;i++)pq.push(arr[i]);
   int count=0;
   while(pq.size()>1){
       int least = pq.top();
       pq.pop();
       int secLeast = pq.top();
       pq.pop();
       int merge = least + secLeast;
       pq.push(merge);
       count+=merge;
   }
   return count;
}

int main(){
    int files[] = { 2, 3, 4, 5, 6, 7 };
    int size = 6;
    int optimalCount = getOptimalCount(files,size);
    cout<<"Optimal merge count is "<<optimalCount;
    return 0;
}