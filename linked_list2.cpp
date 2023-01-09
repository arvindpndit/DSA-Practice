//BASICS OF LINKED LIST

#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

};

//traversing linked list using while loop
void print(Node* n){
    
    while (n!=NULL){
        cout<< n->data << " ";
        // n ko aage badado
        n= n->next ;
    }

}

//traversing the linked list using recursion 
void display(Node* p){

    //base condition
    if(p!=NULL){
        cout<< p->data <<" ";
        //we can write the recursive call here or down below
        display(p->next);
    }

    //recursive call
    //display(p->next);
}

//printing the linked list in reverse using recursion
void display2(Node* p){
    //base condition
    if(p!=NULL){        
        display2(p->next);
        cout<< p->data <<" ";
    }   
}

//counting the nodes of linked list using while loop
int count(Node* p){

    int count =0;

    while(p!=0){
        count++;
        p=p->next;
    }

    return count;
}

//counting the nodes of linked list using recursion
int count2(Node* p){

    //base case
    if(p==0) 
        return 0;

    else                             //if we don't write "else", it'll work completely fine.
        return count2(p->next) + 1; //can be also written as return 1 + count2(p->next);

}

//calculated the sum of data of the nodes using while loop
int addition(Node* p){

    int sum=0;
    while(p!=NULL){
        sum+=p->data;
       
        p=p->next;
    }
    return sum;
}

//calculate the sum of data using recursion
int addition2(Node* p){

    //base case
    if(p==0){
        return 0;
    }

    else{
        return addition2(p->next) + p->data;  //recursive call
    }
}

//finding the maximum element in linked list using while loop
int max(Node* p){

    int max=INT16_MIN;

    while(p!=0){    //the statement while(p!=0) can also be written as while(p)
        if(max < p->data){
            max = p-> data;           
        }
        p=p->next;
    }

    return max;

}

//finding the maximum element in linked list using recursion
int max2(Node* p){
    int maxi=0;

    //base case
    if(p==0)
        return INT16_MIN;

    else{
        maxi=max(p->next);
        if(maxi>p->data){
            return maxi;
        }
        else{
            return p->data;
        }
    }
}

//finding the max in the linked list using recursion but with cleaner code
int max3(Node* p){
    int maxi=0;

    if (p==0) return INT16_MIN;

    maxi=max(p->next);
    return maxi > p->data ? maxi: p->data;  //ternary operator
}

//function for linear search
bool linearSearch(Node* p, int target){
    
    while(p!=0){
        if(p->data == target) 
            return true;
        else           //if i don't write else , the code will run fine
            p=p->next;    
    }

    return false;
}

//function for linear search using recursion
bool linearSearch2(Node* p, int target){
    
    // base case
    if(p==NULL)
        return false;

    if(p->data == target)
        return true;
    
    //recursive call
    return linearSearch2(p->next, target);
}

int main (){

    //creating three nodes in heap memory
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    //assining data to the head node 
    head -> data =4;
    //linking first node with second
    head -> next = second;

    second -> data =7;
    second -> next = third;

    third -> data =3;
    third -> next = NULL;

    //printing with the help of while loop
    print(head);

    cout<<endl;
    //printing with the help of recursion
    display(head);

    cout<<endl;
    //printing in reverse
    display2(head);

    cout<<endl;
    //counting the elements of linked list
    cout<<count(head)<<endl;

    //counting the nodes of linked list using recursion
    cout<< count2(head) <<endl;

    //calculating the sum of all the data in the nodes
    cout<< addition(head)<<endl;

    //calculated the sum using recursion 
    cout<< addition2(head) <<endl;

    //finding the maximum element using while loop
    cout<< max(head) <<endl;

    //finding the maximum element using while loop
    cout<< max2(head) <<endl;

    //linear searching in the linked list 
    cout<< linearSearch(head, 3) <<endl;
    cout<< linearSearch2(head, 7) <<endl;

    return 0;
}