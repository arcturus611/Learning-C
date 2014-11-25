	//expertcprogramming
	//chapter Introduction; exercises on time
	
	#include<stdio.h>
	#include<time.h>
	
	int main(int argc, char* argv[]){
		time_t now = time(NULL);
		printf("Current time is %s", ctime(&now));
		printf("Size of time_t is %lu\n", sizeof(time_t));
		time_t biggest = 0x7fffffffffffff;
		printf("Time at (possibly) largest value of time_t is %s", asctime(gmtime(&biggest)));
		printf("Difference between now and biggest time is %f seconds\n", difftime(biggest, now));
		return 0;
	}
