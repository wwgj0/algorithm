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

int main() {

    return 0;
}
