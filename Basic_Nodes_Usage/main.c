#include <stdio.h>
#include <stdlib.h>

// Define a struct node as node_t
typedef struct node{
   int val;
   struct node * next;	// recursive struct node pointer named next
} node_t;		// Set the name as node_t(node type)

int main(void)
{
   node_t * head = NULL; 
   head = (node_t*) malloc(sizeof(node_t)); // Allocate for first node
   if(head == NULL){	// if head node first value is NULL
      return 1;		// Return an error
   }

   head->val = 1; // Value for the first node
   head->next = (node_t *) malloc(sizeof(node_t)); // malloc for next node
   head->next->val = 2; // Value for second node
   head->next->next = NULL; // End of node so set it to NULL

   return 0;
}
