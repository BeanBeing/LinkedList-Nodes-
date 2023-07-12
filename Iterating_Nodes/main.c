#include <stdio.h>
#include <stdlib.h>

// Implement node as node_t with a recursive struct node to node inside as next node
typedef struct node{
   int val;
   struct node * next;
} node_t;

/**Iterate through the LinkedList all the nodes vaue**/
void print_list(node_t *head)
{
   node_t *current = head; // Set current to the first node of head

   while(current != NULL) // if current is not at the end of a node (NULL)
   {
      printf("%d\n", current->val);	// print the node value
      current = current->next;			// switch to next node
   }

}


/**Adds item to the end of the list**/
void push(node_t * head, int val)
{
   node_t * current = head;	// Make current node be beginning node of head

   while (current->next != NULL)// If the next node of current is not end(NULL)
   {
      current = current->next;	// Make the current node become next node
   }

   // allocate memory for the next node
   current->next = (node_t *) malloc(sizeof(node_t));
   
   current->next->val = val;	// Give the next node a value
   current->next->next = NULL;	// Make the next of the next node end(NULL)
}

int main(void)
{
   node_t * head = NULL;

   head = (node_t *) malloc(sizeof(node_t));
   head->val = 1;

   push(head, 3);

   print_list(head);

   // Just incase, frees the memory of head
   free(head);

   return 0;
}
