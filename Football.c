#include <stdio.h>

int points[] = {8,7,6,3,2};
char *names[] = {"TD+2pt", "TD+FG", "TD", "FG", "safety"};
int num_plays = 5;


void  possible(int score,int index, int counts[]){
	if (index == num_plays -1) {
		if(score % points[index] == 0){
			counts[index] = score / points[index];
			for (int i =0; i < num_plays; i++) {
				if (i > 0) printf(", ");
				printf("%d %s", counts[i],names[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int i =0; i <= score / points[index]; i++){
		counts[index] =i;
		possible(score -i * points[index], index +1,counts);
	}
}





int main(){
	int score;
	int counts[5];
	while (1){
		printf("Enter a score (or enter 1 or 0 to exit): ");
		scanf("%d", &score);
		if (score <= 1){
			break;
		}
		printf("\nCombinations for %d:\n",score);
		possible(score,0,counts);
	}
	return 0;
}
