#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/mount.h>

const char mainMount[PATH_MAX] = "/opt/main";

char* giveInstalledList(char* excludePackage){
	int amount = 0;
	struct dirent* fileStruct;
	DIR* tempDir = opendir("/opt/pls-install/pkgs");
	if(tempDir == NULL){
		printf("Error: opendir() failed and exited wih error code %d\n", errno);
		exit(5);
	}

	while(){
		
	}
}

char* giveInstalledMountFormat(char* excludeName){
	char* tempList = giveInstalleList(excludeName);
	static char* returnList = calloc(sizeof(tempList)/sizeof(char), sizeof(char));
}

void packageHandler(const char* packageName, int mode){
	char* absoluteName = realpath(packageName, NULL);
	char installPath[PATH_MAX] = "/opt/pls-install/pkgs/";
	char mountPath[PATH_MAX] = "/opt/pls-install/mount/";
	struct stat* tempStat;
	if(absoluteName == NULL){
		printf("Error: realpath() failed and exited with error code %d.\n", errno);
		exit(3);
	}else if(stat(installPath, tempStat)){
		printf("Error: stat() failed and exited with error code %d.\n", errno);
		exit(3);
	}
	strcat(installPath, packageName);
	strcat(mountPath, packageName);

	if(mode){
		//TODO: Remove Logic
		printf("Removing %s...", absoluteName);
		if(stat(installPath, tempStat)){
			print("Error: stat() failed and exited with error code %d.\n", errno);
			exit(4);
		}
		char* list = giveInstalledList(installPath);
		if(mount){
			
		}
	}else{
		//TODO: Install Logic
		printf("Installing %s...", absoluteName);
		if(!stat(installPath, tempStat)){
			print("Error: Package is already installed.\n");
			exit(4);
		}else if(rename(absoluteName, installPath)){
			printf("Error: rename() failed and exited with error code %d.\n", errno);
			exit(4);
		}
		mkdir(mountPath, 0755);
		if(mount(installPath, mountPath, "squashfs", MS_MGC_VAL, NULL)){
			printf("Error: mount() failed and exited with error code %d\n", errno);
			exit(4);
		}
	}
	free(absoluteName);
	free(tempStat);
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
