#include <iostream>
#include <vector>
using namespace std;

#两数之和
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a=nums.size(),i,j;
        for(i=0;i<a-1;i++)
       {
            for(j=i+1;j<a;j++)
            {
                if(nums[i]+nums[j]==target)
                return {i,j};
             }
        }
        return {i,j};
    }
};

#移动零
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j;
        for(j=0;j<nums.size();j++)
        {
            if(nums[j]!=0)
           {
             swap(nums[j],nums[i]);
             i++;
            }
        }
    }
};

#相交链表
class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return b;
    }
};

#反转链表
class Solution4 {
public:
    ListNode* reverseList(ListNode* head) {
            ListNode* a=head,*b=nullptr;
        while(a)
        {
             ListNode* c=a->next;
             a->next=b;
             b=a;
             a=c;
        }
        return b;
    }
};

#回文链表
class Solution5 {
public:
    bool isPalindrome(ListNode* head) {
    vector<int> i;
    while(head)
    {
        i.push_back(head->val);
        head=head->next;
    }
    int left=0,right=i.size()-1;
    while(left<right)
    {
        if(i[left]!=i[right])
            return false;
        left++;
        right--;
    }
    return true;
    }
};

#环形链表
class Solution6 {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
         {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

#合并两个有序链表
class Solution7 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
          if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};

#二叉树的中序遍历
class Solution8 {
public:
    void inorder(TreeNode* root, vector<int>& a) {
         if (!root)
        {
            return;
        }
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        inorder(root,a);
        return a;
    }
};

#二叉树的最大深度
class Solution9 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#二叉树的最小深度
class Solution10 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        return 0;
        else if(root->left&&!root->right)
        return minDepth(root->left)+1;
        else if(root->right&&!root->left)
        return minDepth(root->right)+1;
        else
        return min(minDepth(root->left), minDepth(root->right)) +1;
    }
};

#二叉树的翻转
class Solution11 {
public:
    TreeNode* invertTree(TreeNode* root) {
         if (!root)
        {
            return 0;
        }
        TreeNode* a=nullptr;
        a=root->left;
        root->left=root->right;
        root->right=a;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

#对称二叉树
class Solution12 {
public:
    void inorderleft(TreeNode* root, vector<int>& a) {
         if (!root)
        {
            a.push_back(101);
            return;
        }
        a.push_back(root->val);
        inorderleft(root->left,a);
        inorderleft(root->right,a);
    }
    void inorderright(TreeNode* root, vector<int>& a) {
         if (!root)
        {
            a.push_back(101);
            return;
        }
        a.push_back(root->val);
        inorderright(root->right,a);
        inorderright(root->left,a);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> a,b;
        inorderleft(root->left,a);
        inorderright(root->right,b);
        if (a == b)
            return true;
        else
            return false;
    }
};

#二叉树的直径
class Solution13 {
public:
    int maxDepth(TreeNode* root,int &a)
    {
        if (root == nullptr) return 0;
        int b=maxDepth(root->left,a),c=maxDepth(root->right,a);
        if(a<b+c)
        a=b+c;
        return max(b, c) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a=0;
        maxDepth(root,a);
        return a;
    }
};

#有序数组转换为二叉搜索树
class Solution14 {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

#搜索插入位置
class Solution15 {
public:
    int searchInsert(vector<int>& nums, int target){
        int i=0,j=nums.size()-1,mid,a=nums.size();
        if(target>nums[j])
        {
            return j+1;
        }
        if(target<=nums[i])
        {
            return 0;
        }
        while(i<=j)
        {
            mid=i+(j-i)/2;
            if(target<=nums[mid])
            {
                j=mid-1;
            }
            else if(target>nums[mid])
            {
                i=mid+1;
            }
        }
        return i;
    }
};

#有效的括号
class Solution16 {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
        return false;
        stack<char> st;

        for (char c : s)
        {
            if (c == '(')
            st.push(')');
            else if (c == '[')
            st.push(']');
            else if (c == '{')
            st.push('}');
            else
            {
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

#买卖股票的最佳时机
class Solution17 {
public:
    int maxProfit(vector<int>& prices) {
        int n=0,m=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            m=min(m,prices[i]);
            n=max(n,prices[i]-m);
        }
        return n;
    }
};

#爬楼梯
class Solution18 {
public:
    int climbStairs(int n) {
     int a=0,b=0,c=1;
        for (int i=1;i<=n;i++)
        {
            a=b;
            b=c;
            c=a+b;
        }
        return c;
    }
};

#杨辉三角
class Solution19 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        vector<int> b;
        b.push_back(1);
        a.push_back(b);
        for(int i=2;i<=numRows;i++)
        {
            vector<int> c;
            for(int j=1;j<=i;j++)
            {

                if(j==1||j==i)
                c.push_back(1);
                else
                c.push_back(b[j-2]+b[j-1]);
            }
            b=c;
            a.push_back(c);
        }
        return a;
    }
};

#只出现一次的数字
class Solution20 {
public:
    int singleNumber(vector<int>& nums) {
        int i=nums.size(),a=0;
        while(i--)
        {
            a^=nums[i];
        }
        return a;
    }
};

#多数元素
class Solution21 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        for (int x : nums) {
            cnt[x]++;
        }
        for (auto& pair : cnt) {
            if (pair.second > n / 2) {
                return pair.first;
            }
        }
        return -1;
    }
};

#最长连续序列
class Solution22 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
        return 0;
        std::sort(nums.begin(), nums.end());
        vector<int> n=nums,m;
        m.push_back(nums[0]);
        int i,j=0,maxn=0;
        for(i=1;i<nums.size();i++)
        {
            if (nums[i]==nums[i-1])
            {
                continue;
            }
            if(m[j]==nums[i]-1)
            {
                m.push_back(nums[i]);
                j++;
            }
            else
            {
                maxn=max(maxn,j+1);
                j=0;
                m.clear();
                m.push_back(nums[i]);
            }
        }
        maxn = max(maxn, j + 1);
        return maxn;
    }
};

#盛最多水的容器
class Solution23 {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int Max = 0;
        while (left < right)
        {
            int width = right - left;
            int h = min(height[left], height[right]);
            Max = max(Max, width * h);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return Max;
    }
};

#三数之和
class Solution24 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > 0)
                break;

            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                } else if (sum < 0)
                {
                    left++;
                } else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};

#找出字符串中所有字母异位词
class Solution25 {
public:
    vector<int> findAnagrams(string s, string p) {
vector<int> res;
        int sLen = s.size(), pLen = p.size();
        if (pLen > sLen) return res;
        vector<int> cntP(26, 0), cntS(26, 0);
        for (int i = 0; i < pLen; i++) {
            cntP[p[i] - 'a']++;
            cntS[s[i] - 'a']++;
        }
        if (cntP == cntS) res.push_back(0);
        for (int i = pLen; i < sLen; i++) {
            cntS[s[i - pLen] - 'a']--;
            cntS[s[i] - 'a']++;
            if (cntS == cntP) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};
int main()
{

    return 0;
}
