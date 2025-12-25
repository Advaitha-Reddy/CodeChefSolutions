#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(vector<int>& array){

    int m=array.size()-1;

    vector<long long> res(m+1);
    vector<int> a(m+1),k(m+1);

    long long a_sum=0,k_sum=0;
    long long ac=0,kc=0;

    for(int i=1;i<=m;i++){
        if(array[i]==1){
            a[i]=1;
            ac++;
            a_sum+=i;
        }
        else if(array[i]==2){
            k[i]=1;
            kc++;
            k_sum+=i;
        }
        else if(array[i]==3){
            a[i]=1;
            k[i]=1;
            ac++;
            kc++;
            a_sum+=i;
            k_sum+=i;
        }
    }

    vector<long long> aarsi(m+1),krypto(m+1);

    long long left_arsi=0,left_krypto=0;
    long long lt_arsi_sum=0,lt_krypto_sum=0;

    // Aarsi
    for(int line=1;line<=m;line++){
        long long d=0,w=0;
        if(a[line]){
            left_arsi++;
            lt_arsi_sum+=line;
            d=1;
            w=line;
        }

        long long left_score=left_arsi*line-lt_arsi_sum;
        long long right_score=
            (a_sum-lt_arsi_sum+w)-(ac-left_arsi+d)*line;

        aarsi[line]=left_score+right_score;
    }

    // Krypto
    for(int line=1;line<=m;line++){
        long long d=0,w=0;
        if(k[line]){
            left_krypto++;
            lt_krypto_sum+=line;
            d=1;
            w=line;
        }

        long long left_score=left_krypto*line-lt_krypto_sum;
        long long right_score=
            (k_sum-lt_krypto_sum+w)-(kc-left_krypto+d)*line;

        krypto[line]=left_score+right_score;
    }

    for(int i=1;i<=m;i++){
        res[i]=llabs(aarsi[i]-krypto[i]);
    }

    return res;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int dummy,m;
        cin>>dummy>>m;

        vector<int> array(m+1);
        for(int i=1;i<=m;i++){
            cin>>array[i];
        }

        vector<long long> res=solve(array);
        for(int i=1;i<=m;i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}
