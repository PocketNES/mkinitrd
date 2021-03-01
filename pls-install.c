#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

void packageHandler(const char* packageName, int mode){
	char* absoluteName = realpath(packageName, NULL);
	char buffer[PATH_MAX] = "/opt/pkgs/";
	strcat(buffer, packageName);
	if(absoluteName == NULL){
		printf("Error: realpath() exited with an error.\n");
		exit(3);
	}

	if(mode){
		//TODO: Remove Logic
	}else{
		//TODO: Install Logic
		rename(absoluteName, buffer);
	}
}

int main(int argc, const char* argv[]){
	int currentUser = getuid();
	if(currentUser != 0){
		printf("Error: You are not root. You need to be root to use %s.\n", argv[0]);
		exit(1);
	}
	printf("Package Installer, Version 0.02\n(c)2021 pocketlinux32, Under GPLv3\n\n");
	if (argc < 2){
		printf("Usage: %s [ i | r ] { package-array }", argv[0]);
		exit(1);
	}
	switch(argv[1][0]){
		case 'i':
			for(int i = 2; i < argc; i++){
				packageHandler(argv[i], 0);
			}
			break;
		case 'r':
			for(int i = 2; i < argc; i++){
				packageHandler(argv[i], 1);
			}
			break;
		default:
			printf("Error: Invalid Option.\n");
			exit(2);
	}
}
