/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2]
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
        //in max heap first field is frequency of element
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        //in map first field is element and second field is frequency
        map<int,int> m;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end())
                m[nums[i]]++;
            else
                m[nums[i]]=1;
        }
        map<int,int>::iterator itr=m.begin();
        while(itr!=m.end()){
            pq.push({itr->second,itr->first});
            itr++;
        }
        for(int i=0;i<k;i++){
            pair<int,int> p=pq.top();
            pq.pop();
            result.push_back(p.second);
        }
        return result;
    }
