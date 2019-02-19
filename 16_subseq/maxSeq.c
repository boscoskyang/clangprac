#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n){
  size_t currMax = 0;
  size_t allMax;
  if (n == 0){
    allMax = currMax;
  }

  else{
       allMax = 1; 
    for (int i = 0; i < (n-1); i++){
      if (array[i] < array[i+1]){
	currMax++;
	allMax = currMax;
      }
      else{
	currMax = 1;
      }
    }
  }
  return allMax; 
}
