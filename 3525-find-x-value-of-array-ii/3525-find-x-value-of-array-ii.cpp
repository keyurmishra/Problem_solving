// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        
//     }
// };
#include <vector>

using namespace std;

struct Node {
    int prod;
    int count[5]; // k <= 5

    Node() {
        prod = 1;
        for (int i = 0; i < 5; ++i) count[i] = 0;
    }
};

class SegmentTree {
    int n, k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k;

        // Left prefix counts
        for (int r = 0; r < k; ++r) {
            res.count[r] += left.count[r];
        }

        // Right prefix counts shifted by left's total product
        for (int r = 0; r < k; ++r) {
            int new_r = (left.prod * r) % k;
            res.count[new_r] += right.count[r];
        }

        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % k;
            tree[node].prod = val;
            tree[node].count[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int mod_val = val % k;
            tree[node].prod = mod_val;
            for (int r = 0; r < k; ++r) tree[node].count[r] = 0;
            tree[node].count[mod_val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }

        Node left_res = query(2 * node, start, mid, l, r);
        Node right_res = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left_res, right_res);
    }

public:
    SegmentTree(const vector<int>& nums, int k_val) {
        n = nums.size();
        k = k_val;
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int start, int target_x) {
        Node res = query(1, 0, n - 1, start, n - 1);
        return res.count[target_x];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        SegmentTree st(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            st.update(q[0], q[1]);
            ans.push_back(st.query(q[2], q[3]));
        }

        return ans;
    }
};