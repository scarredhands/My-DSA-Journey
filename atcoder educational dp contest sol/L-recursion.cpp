//https://atcoder.jp/contests/dp/tasks/dp_l

//recursion solution

#include <bits/stdc++.h>
using namespace std;

long long func(vector<int>&arr, int i, int j, long long x, long long y, bool flag){
    if(arr.size()==1){
        if(!flag){
            return arr[0];
        }
        else{
            return -arr[0];
        }
    }
    if(i>j){
        return x-y;
    }
    
    if(!flag){
        return max(func(arr,i+1,j,x+arr[i],y,!flag), func(arr,i,j-1,x+arr[j],y,!flag));
    }
    else{
        return min(func(arr,i+1,j,x,y+arr[i],!flag), func(arr,i,j-1,x,y+arr[j],!flag));
    }
}

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;++i){
	    cin>>arr[i];
	}
	
	long long ans= func(arr,0,n-1,0,0,0);
	cout<<ans<<endl;

}
