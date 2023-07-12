#include <stdio.h>
#include <stdlib.h>

// typdef struct node
typedef struct node{
   int val;
   struct node * next;
} node_t;

// Prints all the nodes
void print_list(node_t *head);

// Two pointers to modify a pointer, puts the new element to the beginning
void push(node_t **head, int val);

// Pop the first item
int pop(node_t **head);

// Removes the last item of the list
int remove_last(node_t *head);

int main(void)
{
   node_t *head = NULL;

   push(&head, 1);
   push(&head, 5);

   // pops the first element
   pop(&head);

   push(&head, 8);

   printf("Removed the last node: %d\n",remove_last(head));

   push(&head, 7);
   
   print_list(head);

   return 0;
}

// Prints the node's value(s)
void print_list(node_t *head)
{
   node_t *current = head;

   printf("[ ");
   while(current != NULL)
   {
      printf("%d ", current->val);
      current = current->next;
   }
   printf("]");
}


// Pushes the node to the beginning
void push(node_t **head, int val)
{
   node_t* new_node = NULL;
   new_node = (node_t *) malloc(sizeof(node_t));

   new_node->val = val;
   new_node->next = *head;
   *head = new_node;
}

// Removes the first item
int pop(node_t **head)
{
   int retval = -1;
   node_t * next_node = NULL;

   // If *head is NULL return an error
   if(*head == NULL)
   {
      return -1;
   }

   next_node = (*head)->next;	// Dereference it twice and make next head be next_node
   
   retval = (*head)->val;	// Return value becomes the current head value
   free(*head);		// Free the current head from memory
   *head = next_node;		// Head points to the memory address of next node

   return retval;		// Return the return value
}

// Removes the last item of the list
int remove_last(node_t *head)
{
   int retval = 0;
   /**IF THERE IS ONLY ONE ITEM IN THE LIST, REMOVE IT**/
   if(head->next == NULL)
   {
      retval = head->val;
      free(head);
      return retval;
   }

   /**GET TO THE SECOND TO LAST NODE IN THE LIST*/
   node_t *current = head;
   while (current->next->next != NULL)
   {
      current = current->next;
   }

   /**NOW current POINTS TO THE SECOND TO LAST ITEM OF THE LIST, SO REMOVE current**/
   retval = current->next->val;
   free(current->next);
   current->next = NULL;
   return retval;
}
