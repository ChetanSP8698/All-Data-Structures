#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "queue.h"
int printmenu() {
	int choice;
	printf("1. New patient \n");
	printf("2. Send patient to doctor\n");
	printf("3. Exit\n");
	scanf("%d", &choice);
	return choice;
}
int main(int argc, char *argv[]) {
	queue q;	
	char name[16], *p;
	int choice;

	qinit(&q);
	while(1) {
		choice = printmenu();		
		switch(choice) {
			case 1: // new patient
				scanf("%s", name);
				if(!qfull(&q))
					enq(&q, name);
				else {
					printf("Too many patinets. New patient go home\n");
					continue;
				}
				break;
			case 2: // send patient to doctor
				if(!qempty(&q)) {
					p = deq(&q);	
					printf("%s Go to doctor\n", p);
				} else {
					printf("Go home doctor\n");
					continue;
				}
				break;
			case 3: // exit
				while(!qempty(&q)) {
					p = deq(&q);
					printf("Go home Patient %s\n", p);
				}
				break;
			default:
				break;	
		}
	}
	return 0;
}
