void removeLoop(Node* head)
    {
        if (head == NULL || head -> next == NULL) {
            return;
        }
        bool isCycle = false;
        Node *slow = head;
        Node *fast = head;
        
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if (fast == slow) {
                isCycle = true;
                break;
            }
        }
        
        if (isCycle) {
            if (slow == head) {
                while (slow -> next != fast) {
                    slow = slow -> next; //fast will not move since both will be at head, only slow will traverse and comeback to fast.
                }
                slow -> next = NULL;
            }
            else {
                fast = head;
                while (fast -> next != slow -> next) {
                    fast = fast -> next;
                    slow = slow -> next;
                }
                slow -> next = NULL;
            }
        }
    }