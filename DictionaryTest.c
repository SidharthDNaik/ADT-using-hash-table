/*
* Name: Sidharth Naik
* ID: 1647945
* Class: 12B/M
* Date: March 15,2019
* Description: This is the DictionaryTest file. I used this to test the features of the ADT
* File Name: DictionaryTest
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

int main(int argc, char* argv[]){
   Dictionary A = newDictionary();
   /*char* k;
   char* v;
   char* word1[] = {"one","two","three","four","five","six","seven"};
   char* word2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
   int i;

   for(i=0; i<7; i++){
      insert(A, word1[i], word2[i]);
   }

   printDictionary(stdout, A);*/

   /*insert(A,"yaw","yeet");
   printDictionary(stdout, A);
   delete(A,"yaw");
   printDictionary(stdout, A);
   insert(A,"bob","bill");
   printDictionary(stdout,A);
   delete(A,"yaw"); // Tests non-existant key*/

   /*char* word1[] = {"one","two","three","four","five","six","seven"};
   char* word2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
   int i;

   for(i=0; i<7; i++){
      insert(A, word1[i], word2[i]);
   }

   printDictionary(stdout, A);

   for(i=0; i<6; i++){
      delete(A, word1[i]);
   }

   printDictionary(stdout, A);*/

   /*char* k;
   char* v;
   char* word1[] = {"one","two","three","four","five","six","seven"};
   char* word2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
   int i;

   for(i=0; i<7; i++){
      insert(A, word1[i], word2[i]);
   }

   printDictionary(stdout, A);

   for(i=0; i<7; i++){
      k = word1[i];
      v = lookup(A, k);
      printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
   }

   //insert(A, "five", "glow"); // error: key collision

   delete(A, "one");
   delete(A, "three");
   delete(A, "seven");

   printDictionary(stdout, A);*/

   /*char* word1[] = {"one","two","three","four","five","six","seven"};
   char* word2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
   int i;

   for(i=0; i<7; i++){
      insert(A, word1[i], word2[i]);
   }

   printDictionary(stdout, A);

   for(i=0; i<6; i++){
      delete(A, word1[i]);
   }

   printDictionary(stdout, A);

   freeDictionary(&A);*/

   /*insert(A,"1","bob");
   delete(A,"1");
   insert(A,"2","steve");
   printDictionary(stdout, A);*/

   char* word1[] = {"one","two","three","four","five","six","seven"};
   char* word2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
   int i;

   for(i=0; i<7; i++){
      insert(A, word1[i], word2[i]);
   }

   delete(A,"three");
   delete(A,"six");

   printDictionary(stdout,A);


}
