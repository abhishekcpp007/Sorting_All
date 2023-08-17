#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:

    int val;
    Node*prev;
    Node*next;
    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
    

};

class Doublylinkedlist{
public:
Node* head;
Node* tail;
Doublylinkedlist(){
    head=NULL;
    tail=NULL;
}

// insertion at begin  node

void InsertatStart(int val){
    Node* new_node= new Node(val);
    if(head==NULL){
        head=new_node;
        tail=new_node;
    
    return;
    }
   new_node->next=head;
   head->prev=new_node;
   head=new_node;   
}

// display functon for linked list
void display(){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    
    
        
    }
    cout<<endl;
    
}

void insertatTheEnd(int val){
    Node* new_node=new Node(val);
    if(tail==NULL){
        tail=new_node;
        head=new_node;
    }
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;
}

// insertion at the kth node
void insertatKthnode(int val,int k){
    Node* temp=head;
    int c=1;
    while(c<k-1){
        temp=temp->next;
        c++;
    }


    Node* new_node= new Node(val);
    new_node->next=temp->next;
    temp->next=new_node;
    new_node->next->prev=new_node;
    return;
}
//deleting at he start
void deleteatstart(){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    head=head->next;
    if(head==NULL){
        tail=NULL;
    }
    else{
        head->prev=NULL;

    }
    free(temp);
    return ;
}
// deleting at the end
void deleteatEnd(){
    if(head==NULL){
        return;
    }
    Node*temp=tail;
    tail=tail->prev;
    if(tail==NULL){
        head=NULL;
    }else{
        tail->next=NULL;
    }
    free(temp);
    return;

}
// delete the element at the kth position
void deleteelementAtKth(int k){
    Node*temp=head;
    int count=1;
    while (count<k){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return;
    
    
}




};
void reverseDll(Node* &head , Node* &tail){
   
   Node* currPtr = head;
   while(currPtr){
    currPtr=currPtr->next;
    Node* nextPtr=currPtr->next;
    currPtr->next=currPtr->prev;
    
   }
   Node* newHead=tail;
   tail=head;
   head=newHead;
}
bool ispalendromedll(Node* head,Node*tail){
    while (head != tail && tail!= head->prev){
        if(head->val != tail->val){
            return false;
            
        }
        head=head->next;
        tail=tail->prev;

    }
    return true;
    
    
}

void deletesameneighbour(Node* &head,Node* &tail){
    Node* currptr=tail->prev;

    while (currptr!=head)
    {
        Node* prevNode=currptr->prev;
        Node* nextNode=currptr->next;
        if(prevNode->val==nextNode->val){
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
        }
       currptr=prevNode;
    }
    

}

bool isCriticalPoint(Node* &currNode){
    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val){
        return true;
    }
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val){
        return true;
    }
    return false;
}
vector<int> distanceBetweenCriticalpoints(Node* &head,Node* &tail){
    vector<int>ans(2,1000);
   int firstCP=-1;
   int lastCP=-1;
   Node*currNode=tail->prev;
   if(currNode==NULL){
    ans[0]=ans[1]=-1;
    return ans;
   }
   int currPos=0;
while (currNode->prev!=NULL)
{
    if(isCriticalPoint(currNode)){
        if(firstCP==-1){
            firstCP=lastCP=currPos;
        }
        else{ans[0]=min(ans[0],currPos-lastCP);
        ans[1]=currPos-firstCP;

        }
    }
    currPos++;
    currNode=currNode->next;
    
}

if(ans[0]==1000){
  ans[0]=ans[1]=-1;   
}
return ans;

}




int main(){
    
    Doublylinkedlist dll;
 //   dll.InsertatStart(1);
   // dll.InsertatStart(2);
    //dll.InsertatStart(3);
    //dll.InsertatStart(4);
    //dll.InsertatStart(5);
   // dll.display();

   // dll.head=new_node;
    //dll.tail=new_node;
    //cout<<dll.head->val<<endl;
    dll.insertatTheEnd(1);
    dll.insertatTheEnd(5);
    dll.insertatTheEnd(2);
    dll.insertatTheEnd(6);
    dll.insertatTheEnd(3);
   // dll.insertatKthnode(3,3);
   // dll.display();
   // dll.deleteatstart();
   //dll.deleteatEnd();
  // dll.deleteelementAtKth(3);
  dll.display();
      // reverseDll(dll.head , dll.tail);
      //cout<<ispalendromedll(dll.head,dll.tail);
  //deletesameneighbour(dll.head,dll.tail);
  vector<int>ans=distanceBetweenCriticalpoints(dll.head,dll.tail);
  //dll.display();
  cout<<ans[0]<<" "<<ans[1];
    return 0;
}