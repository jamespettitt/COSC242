#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
  double n, a, b, c;
  double highest_score, temp_score;
  double winning_competitor, temp_winner;

  fflush(stdout);
  while(4 == scanf("%lg%lg%lg%lg", &n, &a, &b, &c)){
      temp_score = ("%f", ((a+b+c)/3));
      temp_winner = ("%f", n);
      if(temp_score > highest_score){
	highest_score = temp_score;
	winning_competitor = temp_winner;
      }

    }

    printf("%f %f\n", highest_score, winning_competitor);
    return EXIT_SUCCESS;

}
