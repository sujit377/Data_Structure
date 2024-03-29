#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};

struct linkedlist{
	node* head;
	linkedlist(){
		head = NULL;
	}
	
	void reverse(){
		node* curr = head;
		node* prev = NULL; node* next = NULL;
		while(curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			
		}
		head = prev;
	}
	
	void print(){
		struct node* temp = head;
		while(temp != NULL){
			cout<< temp->data << " ";
			temp = temp->next;
		}
	}
	
	void push(int data){
		node* temp = new node(data);
		temp->next = head;
		head = temp;
	}
};

main(){
	linkedlist ll; 
	ll.push(20); 
	ll.push(4); 
	ll.push(15); 
	ll.push(85); 
	ll.print();	
	ll.reverse();
	ll.print();	
}
