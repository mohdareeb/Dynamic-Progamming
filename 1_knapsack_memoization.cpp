#include<bits/stdc++.h>
using namespace std;
int matrix[102][1002];
int knapsack(int wt[],int val[],int W,int n){
    if(n==0 || W==0){
        return 0;
    }
    if(matrix[n][W]!=-1){
        return matrix[n][W];
    }
    if(wt[n-1]<=W){
        return matrix[n][W] = max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1) , knapsack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W){
        return matrix[n][W] = knapsack(wt,val,W,n-1);
    }
}
int main(){
    int n=4;
    int w=7;
    int wt[4]={1,3,4,5};
    int val[4]={1,4,5,7};
    memset(matrix,-1,sizeof(matrix));
    cout<<knapsack(wt,val,w,n);
}