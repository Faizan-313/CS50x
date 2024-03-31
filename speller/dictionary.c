// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table

const unsigned int N = 26;
int countword = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashNUm = hash(word);
    //create cursor variable
    node *cursor = table[hashNum];

    // loop until the end of the linked list
    while (cursor != NULL)
    {
        // check if the words are the same
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        // otherwise move cursor to the next node
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary file
    FILE *dic = fopen(dictionary,"r");

    // check if return value is NuLL
    if (dic == NULL)
        return false;

    // read string from file one at a time
    char str[LENGTH + 1];
    while (fscanf(dic,"%s", str) != EOF)
    {
        //create a new node for each word
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
            return false;

        //mcopy word into node using strcpy
        strcpy(temp->word, str);

        // use the hash function
        int hashNum = hash(str);

        // check if the head is pointing to NULL
        if (table[hashNum] == NULL)
        {
            // point temp to NULL
            temp->next = NULL;
        }
        else
        {
            // otherwise point temp to the first node of the linked list
            temp->next = table[hashNum]
        }
        // point the header to temp
        table[hashNum] = temp;

        countword += 1;
    }
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return countword;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}

void freenode(node *n)
{
    if (n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}
