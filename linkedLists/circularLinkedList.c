#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node, *NodePtr;

/* Parameters: value of a new node
 * Returns: a pointer to the newly created node
 * creates a new node and puts the given data into it
 */
NodePtr makeNode(int n) {
    NodePtr np = (NodePtr)malloc(sizeof(Node)); // allocate memory
    np->data = n;       // input the data into the new node
    np->next = NULL;    // points to NULL for now  
    return np;          // return the newly created node
}   

/* Parameters: Pointer to top, value of new node
 * Returns: nothing
 * creates a new node and adds it to the linked list
 */
void insert(NodePtr *top, int n) {
    NodePtr np = makeNode(n);       // create node
    if (*top == NULL) {             // if it's the first node in the list
        *top = np;                  // set top to point to new node
        np->next = *top;            // node points to what top does (itself)
    } else {                        // if there are other nodes in the list
        np->next = (*top)->next;    // node points to what the first node did
        (*top)->next = np;          // first node now points to new node
    }
}

/* Parameters: pointer to top of list, value to search for
 * Returns: Pointer to the found pointer
 * Searches through the list to find a given value, then returns a pointer to it
 */
NodePtr searchList(NodePtr top, int n) {
    NodePtr np;
    np = top;
    while(np->data != n) {              // while data isn't in current node
        np = np->next;                  // go to the next node
        if (np == top) return NULL;     // reached end of the list, reutrn null
    }
    return np;                          // return pointer to the found node
}

/* Parameters: pointer to top of list, value that you want to find the the 
 * prevoius node of
 * Returns: pointer to the previous node, or NULL if the current node doesn't
 * exist
 * Walks through the list to find the node that points to the node that 
 * contains value 'n'
 */
NodePtr findPrev(NodePtr top, int n) {
    NodePtr np, prev;
    prev = top;                     // will be starting at top of the list
    np = searchList(top, n);        // search for the node with value n
    if (np == NULL) return NULL;    // if not found, return NULL

    while (prev->next->data != n)   // walk through the list until the previous
        prev = prev->next;          // node is found

    return prev;                    // return found node
}

/* Parameters: pointer to top of the list, value to delete
 * Returns: 0 if value not found, 1 if opperation was a success
 * searches through a list to find the value to delete, fixes pointers of nodes
 * around the node, and then frees its place in memory
 */
int delete(NodePtr top, int n) {
    NodePtr np, prev;
    np = searchList(top, n);    // search for element to delete
   
    // case the node doesn't exist
    if (np == NULL)             // if the element wasn't found
        return 0;               // it doesn't exist

    prev = findPrev(top, n);    // find the previous node
    
    // case that node is at top of the list
    if (np == top) {            // if the node to be deleted is the first node
        
        // case that node is the only node
        if (np->next == top) {  // check if only node
            top = NULL;         // if it is, set top to point to nothing
            free(np);           // free the node
            return 1;           // return success
        } else {                // otherwise, if np isn't the only node
 
            prev->next = top->next;
            top = prev;
            free(np);
            return 1;
        }
    } else if (np == top->next) {
        // case the node is at the tail of the list
        top->next = np->next;
        free(np);
        return 1;

    } else {
        // case that node is in the middle of the list
        prev->next = np->next;  //
        free(np);   
        return 1;                 // return success!
    }
}

/* Parameters: pointer to top of list
 * Returns: none
 * iterates through a linked list and prints each node out
 */
void printList(NodePtr top) {
    NodePtr np = top;               // create new node pointer that is top
    if (np == NULL)                 // if the pointer is empty
        printf("List is empty\n");  // the list is empty

    while(np != NULL) {     // so long as it isn't empty print the items        
        np = np->next;              // walk through the list
        printf("node: %p\tdata: %d\tnext: %p\n", np, np->data, np->next);
        if (np == top) break;       // once we reach the end, break
    }
}

int main(void) {
    NodePtr top;
    top = NULL;

    int i;
    for (i=0;i<5;i++)
        insert(&top, i);
    printList(top);
    printf("top: %p\n", top);
    for (i=4;i>=0;i--) {
        printf("\n%d\n", i);
        delete(top, i);
        printList(top);
    }
    printf("\n");
    printList(top);
    printf("%p\n", searchList(top, 12));

}  
