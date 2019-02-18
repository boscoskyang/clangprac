#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n);

void test(int * array, size_t n, size_t correct_ans){
  if (maxSeq(array, n) != correct_ans){
    exit(EXIT_FAILURE);
  }
}
int main(){
  int arrayA[] = {1,2,3,4};
  test(arrayA, 4,4);

  int arrayB[] = {1,2,3,3,4,5};
  test(arrayB, 6, 3);

  int arrayC[] = {9,8,7,6,5};
  test(arrayC, 5, 1);

    int arrayD[] = {};
    test(arrayD, 0,0);

      int arrayE[] = {1};
      test(arrayE, 1,1);

      int arrayF[] = {1,2,-5,-4,-3};
      test(arrayF,5,3 );

      return(EXIT_SUCCESS);
}

  
