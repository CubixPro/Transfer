#include<bits/stdc++.h>
using namespace std;
#define null NULL
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> storelist;
        Node* head2 = new Node(-1);
        Node* head3 = head2;
        Node* head4 = head;
        int i = 0;
        while(head != null){
            head2->val = head->val;
            head2->next = new Node(-1); 
            storelist.insert({head, head2});
            head2 = head2->next;
            i++; 
            head = head->next;
            
        }
        Node* head5 = head3;
        while(head4 != null){
            if(head4->random == null){
                head3->random = null;
            }
            else{
                int value = head4->random->val;
                head3->random = storelist[head4->random];
            }
            head3 = head3->next;
            head4 = head4->next;
        } 
        Node* head6 = head5;
        if(head6->next == null && head6->val == -1){
            return null;
        } 
        while(!(head6->next->val == -1 && head6->next->next == null)){
            head6 = head6->next;
        }
            head6->next = null;
        return head5;
    }
};

int main(){
   Node* h1 = new Node(7);
   Node* h2 = new Node(13);
   Node* h3 = new Node(11);
   Node* h4 = new Node(10);
   Node* h5 = new Node(1);
   h1->next = h2;
   h2->next = h3;
   h3->next = h4;
   h4->next = h5;
   h2->random = h1;
   h3->random = h5;
   h4->random = h3;
   h5->random = h1;
   Solution s;
   Node* hf = s.copyRandomList(h1);
   cout << hf;
    
    
}