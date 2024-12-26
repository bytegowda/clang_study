#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_PLANET	8

int main(int argc, char *argv[]) {
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
	int i=0, j=0;

	if(argc == 1) {
		printf("Usage: %s <planets>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for(i=1; i<argc; i++) {
		for(j=0; j<NUM_PLANET; j++) {
			if(!strcmp(argv[i], planets[j])) {
				printf("%s is a Planet\n", argv[i]);
				break;
			}
		}
		if(j == NUM_PLANET) 
			printf("%s is not a Planet\n", argv[i]);
	}

	return 0;
}
