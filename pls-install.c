#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void packageHandler(const char* packageName, int mode){
	char* absoluteName = realpath(packageName, NULL);
	char buffer[PATH_MAX] = "/opt/pkgs/";
	struct stat* tempStat;
	if(absoluteName == NULL){
		printf("Error: realpath() failed and exited with error code %d.\n", errno);
		exit(3);
	}else if(stat(buffer, tempStat)){
		printf("Error: stat() failed and exited with error code %d.\n", errno);
		exit(3);
	}
	strcat(buffer, packageName);

	if(mode){
		//TODO: Remove Logic
		printf("Removing %s...", absoluteName);
	}else{
		//TODO: Install Logic
		printf("Installing %s...", absoluteName);
		rename(absoluteName, buffer);
	}
	free(absoluteName);
}

int main(int argc, const char* argv[]){
	int currentUser = getuid();
	if(currentUser != 0){
		printf("Error: You are not root. You need to be root to use %s.\n", argv[0]);
		exit(1);
	}
	printf("Package Installer, Version 0.02\n(c)2021 pocketlinux32, Under GPLv3\n\n");
	if (argc < 3){
		printf("Usage: %s [ i | r ] { package-array }\n", argv[0]);
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
