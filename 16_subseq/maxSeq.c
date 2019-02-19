#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n){
  size_t currMax = 0;
  size_t allMax;
  size_t currSeq = 0;
  if (n == 0){
    allMax = currMax;
  }

  else{
       allMax = 1;
       currMax = 1;
       currSeq = 1;
    for (int i = 0; i < (n-1); i++){
      if (array[i] < array[i+1]){
	currSeq++;
	currMax = currSeq;

	if(currMax > allMax){
	  allMax = currMax;
	}
      }
      else{
	currSeq =1;
	currMax = currSeq;
      }
    }
  }
  return allMax; 
}
