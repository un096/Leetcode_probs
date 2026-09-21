class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node makes building the result easier
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current digit
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Carry for the next digit
            carry = sum / 10;
        }

        return dummy->next;
    }
};

            
