// Implements a dictionary's functionality
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>


#include "dictionary.h"
int  counter = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1500000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int key = hash(word);
    node *cursor = table[key];
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
      if (strcasecmp(temp->word,word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    
    FILE *read = fopen(dictionary, "r");
    
    if (read == NULL)
    {
        return fclose(read);
    }

  
    char file[LENGTH + 1];
 
    while (fscanf(read, "%s", file) != EOF)
    {
        
        counter++;
     
        node *n = malloc(sizeof(node));
     
        if (n == NULL)
        {
            return 1;
        }
       
        strcpy(n->word, file);
        n->next = NULL;
        int out = hash(file);
        if (table[out] == NULL)
        {
            table[out] = n;
        }
        
        else
        {
            
            n->next = table[out];
            table[out] = n;
        }
    }
    fclose(read);
    return true;
    
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
     // TODO
     return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
     node *temp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N ; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
          temp = cursor;
          cursor = cursor->next;
          free(temp);
        }
    }
    return true;
    
}
