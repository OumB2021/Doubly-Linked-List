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

void insertAtBeginning(int data)
{
}

void insertAtEnd(int data)
{
}

void insertAfter(int data, int previous)
{
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

int main()
{

  int ans; // to store the answer of the user
  FILE *file = fopen("nodeData.txt", "r");

  if (file == NULL)
  {
    perror("Error opening the file");
    return 1;
  }

  int valueRead;
  while (fscanf(file, "%d", &valueRead) == 1)
  {
    }

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