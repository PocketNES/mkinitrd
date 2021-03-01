#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void packageHandler(const char* packageNames[], int mode){
	if(mode){
		//TODO: Remove Logic
	}else{
		//TODO: Install Logic
	}
}

int main(int argc, const char* argv[]){
	int currentUser = getuid();
	if(currentUser != 0){
		printf("You are not root. You need to be root to use %s.", argv[0]);
		exit(1);
	}
	printf("Package Installer, Version 0.02\n(c)2021 pocketlinux32, Under GPLv3\n\n");
	if (argc < 2){
		printf("Usage: %s [ i | r ] { package-array }", argv[0]);
		exit(1);
	}
	switch(argv[1][0]){
		case 'i':
			break;
		case 'r':
			break;
		default:
			printf("Error: Invalid Option.");
			exit(2);
	}
}
