#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void maxi_sum(vector<int>&array,string st,vector<int>&reloc,vector<int>&noreloc){
	int n=array.size();
	for(int i=0;i<n;i++){
		if(st[i]=='1'){
			if(i==0){
				reloc[i]=0;
				noreloc[i]=array[i];
			}
			else{
				if(st[i-1]=='1'){
					reloc[i]=reloc[i-1]+array[i-1];
					noreloc[i]=max(reloc[i-1],noreloc[i-1])+array[i];
				}
				
				else{
					int prev;
					if(i>=2){
						prev=max(reloc[i-1],noreloc[i-1]);
					}
					else{
						prev=0;
					}
					
					reloc[i]=prev+array[i-1];
					noreloc[i]=max(reloc[i-1],noreloc[i-1])+array[i];
				}
			}
		}
		
		else{
			if(i>0){
				reloc[i]=max(reloc[i-1],noreloc[i-1]);
				noreloc[i]=max(reloc[i-1],noreloc[i-1]);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>array(n);
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	string st;
	cin>>st;
	
	vector<int>reloc(n,0);
	vector<int>noreloc(n,0);
	
	maxi_sum(array,st,reloc,noreloc);
	cout<<max(reloc[n-1],noreloc[n-1])<<endl;
	return 0;
}