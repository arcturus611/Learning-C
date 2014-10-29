	//expertcprogramming
	//chapter 1; exercises on time
	
	#include<stdio.h>
	#include<time.h>
	
	int main(int argc, char* argv[]){
		time_t timer = time(NULL);
		printf("Current time is %s\n", ctime(&timer));
		return 0;
	}
