#include <iostream>
#include <unordered_map>

using namespace std;

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == nullptr)
    		return head;

        unordered_map<RandomListNode *, RandomListNode *> hash;

        RandomListNode *origin = head,
        			   *head_c = new RandomListNode(head->label),
        			   *copy   = nullptr;
        copy = head_c;

        // Bijection hash
        hash[copy] = origin;
        hash[origin] = copy;

        while (origin->next != nullptr) {
        	origin = origin->next;
        	copy->next = new RandomListNode(origin->label);
        	copy = copy->next;

        	hash[copy] = origin;
        	hash[origin] = copy;
        }
        copy = head_c;
        origin = head;
        while (copy != nullptr) {
        	// copy find origin find origin->random find copy
        	copy->random = hash[hash[copy]->random];
        	copy = copy->next;
        	origin = origin->next;
        }
        return head_c;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	RandomListNode* head = new RandomListNode(0);
	RandomListNode* curr = head;
	for (int i = 1; i < 10; ++i)
	{
		curr->next = new RandomListNode(i);
		curr->random = curr->next;
		curr = curr->next;
	}

	head = s.copyRandomList(head);
	while (head != nullptr) {
		cout<<head->label<<"  ";
		head = head->random;
	}
	cout<<endl;
	return 0;
}