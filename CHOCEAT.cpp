#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int num;
    cin>>num;
    
    
    //Input for the problem
    vector<pair<int,int>>vec;
    for(int i=0;i<num;i++){
        int a,b;
        cin>>a;
        cin>>b;
        
        vec.push_back({a,b});
    }
    
    
    
    for(int i=0;i<num;i++){
        auto it=vec[i];
        
        int m=it.first;
        int d=it.second;
        
        if(m==d) cout<<m+d-1<<endl;
        
        else{
            cout<<m+d<<endl;
        }
        
        
        
    }
    
    
}
