#include <stdlib.h>
#include <stdio.h>


struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

struct _results {
  int age1;
  double initial1;
};
  typedef struct _results results; 
  typedef struct _retire_info retire_info;

  results  godzilla(int startAgep, double initialp, retire_info play){
    results god;
    int month_count;

    for (month_count = 0; month_count < play.months ; month_count++){
      printf("Age %3d month %2d you have $%.2lf\n", ((startAgep + month_count)/12),(startAgep + month_count)%12, initialp);
    initialp += initialp * play.rate_of_return ;
    initialp += play.contribution ;

    }
    god.age1 = startAgep + month_count;
    god.initial1 = initialp;
    return god;
  }


void retirement(int startAge, double initial, retire_info working, retire_info retired){
  results ongoing;
  ongoing =  godzilla(startAge, initial, working);
  startAge = ongoing.age1 ;
  initial = ongoing.initial1;
  ongoing = godzilla(startAge, initial, retired);

  }
    
  int  main (){
  
    retire_info working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045/12;
    
    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01/12;
    
    retirement(327, 21345, working, retired); 
    return 0;
  }
