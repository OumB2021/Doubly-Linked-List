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

struct node *insertAtEnd(struct node *head, int data)
{
  // create a new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data; // insert data into new node
  newNode->next = head; // have new node point to head

  // if head is NULL then list is empty
  if (head != NULL)
  {
    newNode->prev = newNode;
    return newNode;
  }
  else
  {

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
}

struct node *insertAfter(struct node *head, int data, int previous)
{
  // create a new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data; // insert data into new node

  // if head is NULL then list is empty
  if (head != NULL)
  {
    newNode->next = NULL;
    newNode->prev = NULL;
    printf("value %d does not exist in list, " % d " was inserted as the first value in list", previous, data);
    return newNode;
  }
  else
  {

    // traverse the list until the one before last.
    struct node *current = head;
    while (current != NULL && current->data != previous)
    {
      current = current->next;
    }

    if (current == NULL)
    {
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
}

void displayMenu()
{
  printf("---------------------------------------------\n");
  printf("\t\t\t\t DOUBLY LINKED LIST MENU\n");
  printf("---------------------------------------------\n");
  printf("What operation would you like to perform?\n");
  printf("Please select from the list below:\n");
  printf("1. Insert a new node\n");
  printf("2. Insert a new node after a given node\n");
  printf("3. Delete a node\n");
  printf("0. Exit program\n");
}

void displayLinkedList(struct node *head)
{
  struct node *current = head;
  struct node *tail = NULL;

  // Traverse the linked list and print the values
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
    tail = current
  }
  printf("NULL\n");
}

int main()
{

  int ans;                                 // to store the answer of the user
  FILE *file = fopen("nodeData.txt", "r"); // open the file

  // Check if file is opened
  if (file == NULL)
  {
    perror("Error opening the file");
    return 1;
  }

  int valueRead; // read the value

  while (fscanf(file, "%d", &valueRead) == 1)
  {
  }

  fclose(file);

  // while ()
  // do {
  //   displayMenu();
  //   printf("Enter your choice: ");
  //   scanf("%d", &ans);

  //   // Input validation
  //   if (ans < 0 || ans > 3) {
  //     printf("Please make a valid choice from 0 to 3.\n");
  //   }

  // } while (ans != 0);

  return 0;
}