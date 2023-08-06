struct Node{
    Node* links[2];

    bool contains(int bit) {
        return links[bit] != NULL;
    }
    void put(int bit, Node* node) {
        links[bit]= node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie{
private: 
    Node* root;
public: 
    Trie() {
        root= new Node();
    }

    void insert(int num){
        Node* node= root;
        for(int i=31; i>=0; i--) {
            int bit= (num>>i) &1;
            if(!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node= node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node= root;
        int mxNum= 0;
        for(int i=31; i>=0; i--) {
            int bit= (num>>i)&1;
            if(!node->contains(1-bit)) {
                node= node->get(bit);
            }
            else {
                mxNum= mxNum | (1<<i);
                node= node->get(1-bit);
            }
        }
        return mxNum;
    }
};

bool mycomp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.second < b.second.second;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> q;
        for(int i=0; i<queries.size(); i++) {
            q.push_back(make_pair(i, make_pair(queries[i][0], queries[i][1])));
        }

        sort(q.begin(), q.end(), mycomp);

        Trie trie;
        int idx= 0;
        
        for(int i=0; i<queries.size(); i++) {
            while(idx<nums.size() && nums[idx]<=q[i].second.second) {
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0)
                ans[q[i].first]= (-1);
            else
                ans[q[i].first]= trie.getMax(q[i].second.first);
        }
        return ans;
    }
};