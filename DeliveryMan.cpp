#include <bits/stdc++.h>
#include <functional>
#include <algorithm>
using namespace std;

bool isfeasible(int x1,int y1,int x,int y){
    if(x1<=x && y1<=y) return true;
    return false;
}

int sum_array(vector<int>&b){
    int sum=0;
    int n=b.size();
    for(int i=0;i<n;i++){
        sum+=b[i];
    }
    return sum;
}

int sum_selected(vector<int>&c,int k){
    int sum1=0;
    for(int i=0;i<k;i++){
        sum1+=c[i];
    }
    
    return sum1;
}

int max_profit(vector<int>&a,vector<int>&b,int x,int y){
    int n=a.size();
    vector<int>c(n);
    for(int j=0;j<n;j++){
        c[j]=a[j]-b[j];
    }
    int base_profit=sum_array(b);
    int profit=base_profit;
    
    sort(c.begin(),c.end(),greater<int>());
    for(int i=0;i<=x;i++){
        int x1=i;
        int y1=n-x1;
        if(isfeasible(x1,y1,x,y)){
            profit=max(profit,base_profit+sum_selected(c,x1));
        }
        else{
            continue;
        }
    }
    
    return profit;
}

int main() {
	int n;
	cin>>n;
	int x,y;
	cin>>x;
	cin>>y;
	vector<int>a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    
	}
	for(int i=0;i<n;i++){
	   cin>>b[i];
	}
	cout<<max_profit(a,b,x,y)<<endl;
	
	
	

}
