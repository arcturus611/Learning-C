#include <stdio.h>

int main(int argc, char** argv){
	int id, score;
	
	fscanf(stdin, "%d", &id);
	fscanf(stdin, "%d", &score);
	
	fprintf(stdout, "ID: %d\n", id);
	fprintf(stdout, "Score: %d\n", score);
	
	return 0; 
}
