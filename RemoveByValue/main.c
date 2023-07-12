#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

// Prints all the values of a node
void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

// Pops the beginning node item
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

// Removes an item from node by the value you passed
int remove_by_value(node_t ** head, int val) {
    /* TODO: fill in your code here */
   node_t *previous, *current;

   // If head starts with NULL then just exit function
   if(head == NULL)
   {
      return -1;
   }

   // If the first value of the node is the same as val
   if((*head)->val == val)
   {
      return pop(head); // pop it
   }

   previous = *head;
   current = (*head)->next;

   while(current)
   {
      // If current matches the value
      if(current->val == val)
      {
         // Make the previous next, the next of current since current will be freed
         previous->next = current->next;
         free(current);  // frees the current's current. Do not access its memory.
         return val; // return the value to return an int and also for a fun printf()
      }

      // Through each of the while loop
      // If it doesn't match the val then previous is current
      // current becomes the next iteration
      previous = current;
      current = current->next;
   }

   // Return function if all else fails
   return -1;
}

int main() {

    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
}
