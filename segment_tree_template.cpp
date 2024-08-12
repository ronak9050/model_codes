#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class SGtree{
    vector<int>seg;
    public:
        SGtree(int n){
            seg.resize(4*n+1);
        }
        
        void build(int ind,int low, int high,vector<int>&a){
            if(low==high){
                seg[ind]=a[low];
                return;
            } 
            int mid=(low+high)/2;
            build(2*ind+1,low,mid,a);
            build(2*ind+2,mid+1,high,a);
            seg[ind]=min(seg[2*ind+1],seg[ind*2+2]);
        }

        int query(int ind,int low,int high,int l,int r){
            if(l>high || r<low) return INT_MAX;
            if(l<=low && high<=r) return seg[ind];
            
            int mid=(low+high)/2;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2,mid+1,high,l,r);
            return min(left,right);
        }

        void update(int ind,int low,int high,int i,int val){
            if(low==high){
                seg[ind]=val;
                return;
            }

            int mid=(low+high)/2;
            if(mid>=i) update(2*ind+1,low,mid,i,val);
            else update(2*ind+2,mid+1,high,i,val);

            seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
        }
};



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    SGtree sgt1=SGtree(n);
    sgt1.build(0,0,n-1,a);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<sgt1.query(0,0,n-1,l,r)<<endl;
        }
        else{
            int ind,val;
            cin>>ind>>val;
            sgt1.update(0,0,n-1,ind,val);
            a[ind]=val;
        }
    }
    return 0;
}