#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue <pii , vector<pii> , greater<pii>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto num : mp){
            pq.push({num.second , num.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
