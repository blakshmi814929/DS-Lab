struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Dummy node handles edge cases where the head itself has duplicates (e.g., Example 2)
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        // Check if the current node starts a sequence of duplicates
        if (curr->next != NULL && curr->val == curr->next->val) {
            int dupVal = curr->val;
            // Skip all nodes with this duplicate value
            while (curr != NULL && curr->val == dupVal) {
                curr = curr->next;
            }
            // Connect prev to the first non-duplicate node after the sequence
            prev->next = curr;
        } else {
            // Current node is distinct; move prev forward
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}
