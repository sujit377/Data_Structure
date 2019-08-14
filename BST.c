#include<stdlib.h>
#include<stdio.h>
struct node{
	int key;
	struct node *left,*right;
};

struct node *newnode(int key){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d \n",root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* root, int key){
	if(root == NULL){
		return newnode(key);
	}
	
	if(root->key > key){
		root->left = insert(root->left,key);
	}
	else if(root->key < key){
		root->right = insert(root->right,key);
	}
	return root;
}

struct node *min(struct node *node){
	struct node *cur = node;
	if(cur->left != NULL){
		cur = cur->left;
	}
	return cur;
}

struct node *del(struct node *root,int key){
	if(root == NULL)
		return root;
	if(key < root->key){
		root->left = del(root->left,key);
	}
	else if(key > root->key){
		root->right = del(root->right,key);
	}
	
	else{
		if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		
		struct node *temp = min(root->right);
		root->key = temp->key;
		root->right = del(root->right,temp->key);
	}
	return root;
}

int main(){
	struct node *root = NULL;
	root = insert(root,32);
	insert(root,33);
	insert(root,34);
	insert(root,73);
	insert(root,45);
	insert(root,15);
	insert(root,18);
	insert(root,53);
	insert(root,30); 

	printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = del(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 45\n"); 
    root = del(root, 45); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 18\n"); 
    root = del(root, 18); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
	
	return 0;
}
