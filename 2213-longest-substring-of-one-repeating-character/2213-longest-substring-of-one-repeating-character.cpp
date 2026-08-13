class Solution {
public:
    
    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;

      Node() {
        len = pref = suff = best = 0;
        leftChar = rightChar = '#';
      }
    };
    
    vector<Node> tree;
    Node merge(Node left, Node right) {
        Node parent;
        parent.len = left.len + right.len;

        parent.leftChar = left.leftChar;
        parent.rightChar = right.rightChar;

        parent.pref = left.pref;
        parent.suff = right.suff;

        parent.best = max(left.best, right.best);
        if (left.rightChar == right.leftChar) {
            parent.best = max(
                parent.best,
                left.suff + right.pref
            );

            if (left.pref == left.len) {
                parent.pref =
                    left.len + right.pref;
            }

            if (right.suff == right.len) {
                parent.suff =
                    right.len + left.suff;
            }
        }

        return parent;
    }
    void build(int node,int start,int end,string& s) {
        if (start == end) {
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node,start,mid,s);

        build(2 * node + 1,mid + 1,end,s);

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }
    void update(int node,int start,int end,int idx,char ch) {

        if (start == end) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node,start,mid,idx,ch);
        }
        else {
            update(2 * node + 1,mid + 1,end,idx,ch);
        }

        // recompute parent after update
        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    vector<int> longestRepeating(string s,string queryCharacters,vector<int>& queryIndices) {

        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1,0,n - 1,idx,ch);
            ans.push_back(tree[1].best);
        }

        return ans;
        
    }
};