#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;

    int area(vector<int>& r){
        return (r[2]-r[0]+1) * (r[3]-r[1]+1);
    }

    Solution(vector<vector<int>>& rect) {
        rects=rect;
        int totalArea=0;
        for(auto r: rects){ //vector por vector
            totalArea+=area(r);
            v.push_back(totalArea);
        }

    }
    
    vector<int> pick() {
        int rnd=rand() % v.back();
        int idx=upper_bound(v.begin(), v.end(), rnd) - v.begin();

        auto r=rects[idx];
        int x=rand()%(r[2]-r[0]+1) + r[0];
        int y=rand()%(r[3]-r[1]+1) + r[1]; 
        return {x,y};
    }
};

int main(){
    return 0;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */