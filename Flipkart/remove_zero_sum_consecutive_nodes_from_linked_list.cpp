class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        bool sumZeroFound = true;
        while(sumZeroFound){ 
            sumZeroFound = false; 
            
            ListNode* iter = &dummy;
            unordered_map<int, ListNode*> prefixSumTable;
            prefixSumTable.insert({0, iter});
            iter = iter->next; 
            int currSum = 0;

            while(iter){
                currSum += iter->val;
                if(prefixSumTable.find(currSum) != prefixSumTable.end()){
                    ListNode* start = prefixSumTable[currSum];
                    start->next = iter->next;
                    sumZeroFound = true; 
                }
                else{
                    prefixSumTable.insert({currSum, iter});
                }
                iter = iter->next;
            }
        }
        return dummy.next;
    }
};
