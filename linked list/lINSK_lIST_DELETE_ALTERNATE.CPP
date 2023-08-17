#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int data) {
        val = data;
        next = NULL;
    }
};

class linked_list {
public:
    node* head;
    linked_list() {
        head = NULL;
    }

    void insertAtTail(int val) {
        node* new_node = new node(val);
        if (head == NULL) {
            head = new_node;
            return;
        }

        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }
    
void RemoveDuplicate(node*& head) {
    node* current_node = head;
    while (current_node) {
        while (current_node->next && current_node->val == current_node->next->val) {
            node* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
        }
        current_node = current_node->next;
    }
}

    void reverse(node* head){
        if(head == NULL){
            return;
        }
        reverse(head->next);
        cout<<head->val<<" ";
    }

};

void deleteAlternate_node(node*& head) {
    node* currentNode = head;
    while (currentNode != NULL && currentNode->next != NULL) {
        node* temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        free(temp);
        currentNode = currentNode->next;
    }
}



//GIVEN the head of linked list, determine if the linkedlist is a palindrome or not.
bool ispalendrome(node*head){
    node* slow=head;
    node*fast=head;
    while(fast && slow->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    // now slow is pointing to middle element
    // break the linkedlist in the middle
    node*curr=slow->next;
   node*prev= slow;
   slow->next=NULL;
   while(curr){
    node*nextNode=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nextNode;
   }
   node* head1=head;
   node*head2=prev;
   while(head2){
    if(head1->val != head2->val){
        return false;
    }
    head1=head1->next;
    head2=head2->next;
    
   }
   return true;


}
//Given thehead of a linked list, rotate the list tothe right by k places.
node* rotatebyk(node* &head,int k){
int n=0;
node*tail=head;
while (tail->next){
    n++;
    tail=tail->next;
}
n++;//for including last node
k=k%n;
if(k==0){
    return head;
}
//3 too reaverse n-k node
   tail->next=head;
   node*temp=head;
   for(int i=1;i<n-k;i++){
    temp = temp->next;

   }
   node* newhead=temp->next;
   temp->next=NULL;
   return newhead;






}
node* OddEvenlinklist(node* &head){
   if(!head){
    return head;
   }
   
    node* oddptr=head;
    node* evenhead=head->next;
    node*evenptr=evenhead;

    while (evenptr && evenptr->next)
    {
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        oddptr=oddptr->next;
        evenptr=evenptr->next;
    }
    oddptr->next=evenhead;
    return head;


}



int main() {
    linked_list l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3); // Duplicate value
    l.insertAtTail(6);
    l.insertAtTail(7);
    l.insertAtTail(8); // Duplicate value
   // l.insertAtTail(5);
    //l.insertAtTail(6);
   // l.display();
   // l.reverse(l.head);
   // l.display();
  
    // deleteAlternate_node(l.head);
   // l.RemoveDuplicate(l.head);
    //l.display();
   // cout<<endl<<ispalendrome(l.head);
  // l.head=rotatebyk(l.head,3);
  l.head=OddEvenlinklist(l.head);
   l.display();

    return 0;
}
