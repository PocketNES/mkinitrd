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
	char* packageList[argc-2];
	for(int i = 0; i < argc - 2; i++){
		packageList[i] = argv[i + 2];
	}
	switch(argv[1][0]){
		case 'i':
			packageHandler(packageList, 0);
			break;
		case 'r':
			packageHandler(packageList, 1);
			break;
		default:
			printf("Error: Invalid Option.");
			exit(2);
	}
}
