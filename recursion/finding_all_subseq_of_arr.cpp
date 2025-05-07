//for finding all subseq of an array

#include <bits/stdc++.h>
using namespace std;

void sub(int index,vector<int> &seq, vector<int> &a, int n){
    if(index==n){
        for(auto it:seq){
            cout<<it<<' ';
        }
        cout<<endl;
        return;
    }
    seq.push_back(a[index]);
    sub(index+1,seq,a,3);
    seq.pop_back();
    sub(index+1,seq,a,3);
}

int main() {
    vector<int> a={3,1,2};
    vector<int>seq;
    sub(0,seq,a,3);

}
