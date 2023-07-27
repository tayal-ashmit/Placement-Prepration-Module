class Solution {
public:
    int count=0;
    int kthLargest(Node root, int K) {
        if(root==null)
            return 0;

        int left= kthLargest(root.right, K);
        if(left!=0)
            return left;
        count++;

        if(count==K)
            return root.data;
        int right= kthLargest(root.left, K);

        if(right!=0)
            return right;
        return 0;        
    }
}