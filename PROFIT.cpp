#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int num;
	cin>>num;
	
	vector<pair<int,int>>vec;
	for(int i=0;i<num;i++){
	    int a,b;
	    cin>>a;
	    cin>>b;
	    
	    vec.push_back({a,b});
	}
	
	
	for(int j=0;j<num;j++){
	    int temp=vec[j].second;
	    int t_n=vec[j].first;
	    
	    
	    int cost=0;
	    int sales=0;
	    for(int k=1;k<=t_n;k++){
	        if(k>=temp){
	            cost+=temp;
	            sales+=k;
	        }
	    }
	    
	    cout<<sales-cost<<endl;
	}
	
	
	return 0;

}
