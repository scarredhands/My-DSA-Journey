//https://leetcode.com/problems/merge-k-sorted-lists/

//tc= Nlog(K) where n is total nodes and k is size of list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(auto it:lists){
            if(it){
                pq.push(it);
            }
        }
        ListNode* ans=new ListNode(0);
        ListNode* dummy= ans;
        while(!pq.empty()){
            dummy->next= pq.top();
            dummy=dummy->next;
            pq.pop();
            if(dummy->next){
                pq.push(dummy->next);
            }
        }
        return ans->next;

    }
};