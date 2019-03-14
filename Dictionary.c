/*
* Name: Sidharth Naik
* ID: 1647945
* Class: 12B/M
* Date: March 15, 2019
* Description: This is the Dictionary ADT has all the ADT methods
* File Name: Dictionary.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"


// private types --------------------------------------------------------------

// Defines the pairObject
typedef struct PairObj{
  char* key;
  char* value;
} PairObj;

// Gives PairObj* a placeholder name of Pair
typedef PairObj* Pair;

// newPair()
// Constructor for pair
Pair newPair(char* k, char* v){
  Pair P = malloc(sizeof(PairObj));
  assert(P!=NULL);
  P->key = k;
  P->value = v;
  return(P);
}

// freePair()
// deconstructor
void freePair(Pair* pP){
  if( pP!=NULL && *pP!=NULL ){
    free(*pP);
    *pP = NULL;
  }
}

// NodeObj
typedef struct NodeObj{
   struct PairObj* pair;
   struct NodeObj* next;
} NodeObj;

// Node
typedef NodeObj* Node;

// newNode()
// constructor of the Node type
Node newNode(char* key, char* value) {
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->pair = newPair(key,value);
   return(N);
}

// freeNode()
// destructor for the Node type
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

const int tableSize=101;

// Dictionary Obj
typedef struct DictionaryObj{
   Node* hashList;
   int numItems;
   int* numPairs;
} DictionaryObj;

typedef DictionaryObj* Dictionary;

// public functions -----------------------------------------------------------

// newDictionary()
// constructor for the Dictionary type
Dictionary newDictionary(void){
   Dictionary D = malloc(sizeof(DictionaryObj));
   assert(D!=NULL);
   D->hashList = calloc(tableSize, sizeof(NodeObj));
   D->numPairs = calloc(tableSize, sizeof(int));
   D->numItems = 0;
   return D;
}

// freeDictionary()
// destructor for the Dictionarytype
void freeDictionary(Dictionary* pD){
   if( pD!=NULL && *pD!=NULL ){
      if( !isEmpty(*pD) ) {
        makeEmpty(*pD);
      }
      free((*pD)->hashList);
      free((*pD)->numPairs);
      free(*pD);
      *pD = NULL;
   }
}

// rotate_left()
// rotate the bits in an unsigned int
unsigned int rotate_left(unsigned int value, int shift) {
  int sizeInBits = 8*sizeof(unsigned int);
  shift = shift & (sizeInBits - 1);
  if ( shift == 0 )
    return value;
  return (value << shift) | (value >> (sizeInBits - shift));
}
// pre_hash()
// turn a string into an unsigned int
unsigned int pre_hash(char* input) {
  unsigned int result = 0xBAE86554;
  while (*input) {
      result ^= *input++;
      result = rotate_left(result, 5);
  }
  return result;
}
// hash()
// turns a string into an int in the range 0 to tableSize-1
int hash(char* key){
  return pre_hash(key)%tableSize;
}

// ADT operations

// isEmpty()
// returns 1 (true) if D is empty, 0 (false) otherwise
// pre: none
int isEmpty(Dictionary D){
   return(D->numItems==0);
}

// size()
// returns the number of (key, value) pairs in D
// pre: none
int size(Dictionary D) {
  return D->numItems;
}

// lookup()
// returns the value v such that (k, v) is in D, or returns NULL if no
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* key){
  int index = hash(key);
  Node N = D->hashList[index];

  while (N != NULL){
      if (strcmp(N->pair->key,key) == 0){
        return N->pair->value;
      }
      N = N->next;
  }
  return NULL;
}

// insert()
// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* key, char* value){

   if( lookup(D,key) != NULL ){
      fprintf(stderr, "cannot insert duplicate keys\n");
      exit(EXIT_FAILURE);
   }

   int index = hash(key);
   Node N = D->hashList[index];
   Node P = newNode(key,value);
   P->next = N;
   D->hashList[index] = P;
   (D->numPairs[index])++;
   (D->numItems)++;

}

// delete()
// deletes pair with the key k
// pre: lookup(D, k)!=NULL
void delete(Dictionary D, char* key){

   if( lookup(D,key) == NULL ){
      fprintf(stderr, "cannot delete non-existent key\n");
      exit(EXIT_FAILURE);
   }

   int index = hash(key);
   Node N = D->hashList[index];
   Node P = NULL;

   while(N != NULL){
     if(strcmp(N->pair->key,key) == 0){
       break;
     }
     P = N;
     N = N->next;
   }
   (D->numPairs[index])--;
   (D->numItems)--;
   if(P != NULL){
     P->next = N->next;
     freePair(&(N->pair));
     freeNode(&N);
   } else {
     D->hashList[index] = N->next;
     freePair(&(N->pair));
     freeNode(&N);
   }
}

// makeEmpty()
// re-sets D to the empty state.
// pre: none
void makeEmpty(Dictionary D){
  int i = 0;
  while( D->numItems > 0 && i < tableSize-1){
    if(D->hashList[i] != NULL){
      while( D->numPairs[i] > 0){
        delete(D, D->hashList[i]->pair->key);
      }
    }
    i++;
  }
}

// printDictionary()
// pre: none
// prints a text representation of D to the file pointed to by out
void printDictionary(FILE* out, Dictionary D){
  for(int i = 0; i < tableSize; i++){
    if(D->numPairs[i] > 0){
      for(Node N=D->hashList[i]; N != NULL; N=N->next){
        fprintf(out,"%s %s\n",N->pair->key, N->pair->value);
      }
    }
  }
}
