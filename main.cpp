#include <iostream>
#include <vector>
using namespace std;

#两数之和
class Solution {
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
class Solution {
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
class Solution {
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


int main() {

    return 0;
}
