#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    int maxTotalReward(vector<int>& r) {
        int n = r.size(), j = 0;
        sort(r.begin(), r.end());
        bitset<100000> bs(1), mask;
        cout<<bs[0]<<endl;
        for(auto ele : r){
            for(; j < ele ; j++)
                mask.set(j);  // mask[j] = 1
            bs |= (bs & mask) << ele;
        }

        for(int i = 99999 ; i >= 0 ; i--){
            if(bs.test(i)) return i; // checks whether the given index is set or not
        }
        return 0;
    }
};

int main(){
    
    return 0;
}