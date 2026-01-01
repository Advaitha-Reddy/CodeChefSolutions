#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ans=0;

array<int,21>solve(int node,int parent,vector<vector<int>>&graph,vector<int>tot,vector<int>group){
	int n=graph.size();
	array<int,21>cur{};
	
	cur[group[node]]=1;
	for(auto child:graph[node]){
		if(child==parent){
			continue;
		}
		
		auto c=solve(child,node,graph,tot,group);
		
		for(int i=1;i<=20;i++){
			if(tot[i]){
				ans+=c[i]*(tot[i]-c[i]);
			}
			
			cur[i]+=c[i];
		}
	}
	
	return cur;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>graph(n);
	vector<int>group(n);
	vector<int>tot(21);
	
	int m=n-1;
	int i=1;
	while(i<=m){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		i++;
	}
	
	for(int j=0;j<n;i++){
		cin>>group[j];
	}
	
	for(auto x:group){
		tot[x]++;
	}
	
	solve(0,-1,graph,tot,group);
	cout<<ans<<endl;
}