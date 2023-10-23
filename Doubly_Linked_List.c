#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

// insert a new node at the beginning of the linked list
struct node *insertAtBeginning(struct node *head, int data)
{
  // create a new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data; // insert data into new node
  newNode->next = head; // have new node point to head
  newNode->prev = NULL; // new node prev point to null

  // make the new node to be head
  if (head != NULL)
  {
    head->prev = newNode;
  }

  return newNode; // return the new node
}

// insert a new node at the head of the linked list
struct node *insertAtEnd(struct node *head, int data)
{
  // create a new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data; // insert data into new node
  newNode->next = NULL; // have new node point to head

  // if head is NULL then list is empty
  if (head == NULL)
  {
    newNode->prev = newNode;
    return newNode;
  }
  // traverse the list until the one before last.
  struct node *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  // have the current-next point to the new node
  // and the prev node to point to the last node in the list
  current->next = newNode;
  newNode->prev = current;

  return head;
}

// Insert a node after a given node.
struct node *insertAfter(struct node *head, int data, int previous)
{
  // create a new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data; // insert data into new node

  // if head is NULL then list is empty
  if (head == NULL)
  {
    newNode->next = NULL;
    newNode->prev = NULL;
    printf("value %d does not exist in list, %d  was inserted as the first value in list", previous, data);
    return newNode;
  }
  // traverse the list until the one before last.
  struct node *current = head;
  while (current != NULL && current->data != previous)
  {
    current = current->next;
  }

  // Handle cases where the previous value wasn't found
  if (current == NULL)
  {
    system("cls"); // clear the console output
    printf("Value %d not found in the list. Node not inserted.\n", previous);
    free(newNode); // Free the new node as it won't be inserted
    return head;
  }

  // Insert the new node after 'current'
  newNode->next = current->next;
  newNode->prev = current;
  if (current->next != NULL)
  {
    current->next->prev = newNode;
  }
  current->next = newNode;

  return head;
}

struct node *deleteNode(struct node *head, int data)
{
  if (head == NULL)
  {
    printf("The list is empty, no nodes to be deleted.\n");
    return head;
  }

  struct node *current = head;

  while (current != NULL && current->data != data)
    current = current->next;

  if (current == NULL)
  {
    printf("Node does not exist in the list.\n");
    return head;
  }

  // in case the node to be deleted is the first one.
  if (current == head)
  {
    head = current->next;
    if (head != NULL)
      head->prev = NULL
  }
  else
  {
    current->prev->next = current->next;
    if (current->next != NULL)
      current->next->prev = current->prev;
  }

  free(current);
  return head;
}

// Display menu for user
void displayMenu()
{
  printf("---------------------------------------------\n");
  printf("\tDOUBLY LINKED LIST MENU\n");
  printf("---------------------------------------------\n");
  printf("What operation would you like to perform?\n");
  printf("Please select from the list below:\n");
  printf("1. Insert a new node\n");
  printf("2. Insert a new node after a given node\n");
  printf("3. Delete a node\n");
  printf("4. Print the list\n");
  printf("0. Exit program\n");
}

// dDisplay linked list
void displayLinkedList(struct node *head)
{
  struct node *current = head;
  struct node *tail = NULL;
  // Traverse the linked list and print the values
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    tail = current;
    current = current->next;
  }
  printf("NULL\n");
}

int main()
{

  int ans;                                 // to store the answer of the user
  FILE *file = fopen("nodeData.txt", "r"); // open the file
  int valueRead;                           // read the value
  struct node *head = NULL;                // Create an empty doubly linked list

  // Check if file is opened
  if (file == NULL)
  {
    perror("Error opening the file");
    return 1;
  }

  while (fscanf(file, "%d", &valueRead) == 1)
    head = insertAtEnd(head, valueRead);

  displayLinkedList(head);
  fclose(file);

  // while ()
  do
  {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &ans);

    // Input validation
    while (ans < 0 || ans > 4)
    {
      printf("Please make a valid choice from 0 to 4: ");
      scanf("%d", &ans);
    }

    int userData, prevData;
    switch (ans)
    {
    case 1:
      printf("Please insert your node data: ");
      scanf("%d", &userData);
      head = insertAtEnd(head, userData);
      break;

    case 2:
      printf("Please insert your node data: ");
      scanf("%d", &userData);
      printf("Now insert your previous data: ");
      scanf("%d", &prevData);
      head = insertAfter(head, userData, prevData);
      break;

    case 4:
      system("cls");
      displayLinkedList(head);
      break;
    }
  } while (ans != 0);

  printf("You have now existed the program.\nGoodbye!\n");
  return 0;
}