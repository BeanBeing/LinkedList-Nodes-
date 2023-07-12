#include <stdio.h>
#include <stdlib.h>

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

/**REMOVES A SPECIFC ITEM FROM LIST**/
int remove_by_index(node_t ** head, int n);


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

   push(&head, 9);

   print_list(head);

   printf("Desired item to remove: %d\n", remove_by_index(&head, 2));
   
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

/**REMOVES A SPECIFC ITEM FROM LIST**/
int remove_by_index(node_t ** head, int n)
{
   int retval = -1;
   node_t *current = *head;
   node_t *temp_node = NULL;

   if(n == 0)
   {
      return pop(head);
   }

   for(int i = 0; i < n - 1; i++)
   {
      if(current->next == NULL)
      {
         return -1;
      }
      current = current->next;
   }

   // If the node after the foor loop is end to a node(NULL)
   // Return as -1
   if(current->next == NULL)
   {
      return -1;
   }

   temp_node = current->next;	// Temp node contains value of current->next
   retval = temp_node->val;	// retval becomes the value of the temp_node
   current->next = temp_node->next;	// current-> becomes the next of temp
   free(temp_node);		// frees temp_node

   return retval;		// returns the value, can be used in printf()
}
