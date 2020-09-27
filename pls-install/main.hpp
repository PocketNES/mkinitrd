#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;

class Package{
	protected:
		string name;
		string type;
		vector<string> dependencies;
	public:
		Package(string tempName, string tempType, vector<string> deps){
			name = tempName;
			type = tempType;
			dependencies = deps;
		}
		string getName(){
			return name;
		}
		string getType(){
			return type;
		}
		vector<string> getDependencies(){
			return dependencies;
		}
};

int installPackage(Package package, int argc, const char* argv[]){
	vector<string> deps = package.getDependencies();
	string installPath;
	if(package.getType() == "tar"){
		installPath = "/";
	}else if(package.getType() == "sb" && stat("/opt/sistema/initramfs", F_OK)){
		installPath = "/opt/sistema/initramfs/memoria/boot/modulos";
	}else{
		installPath = "/opt/sistema/modulos";
	}
	if(!stat(installPath.c_str(), F_OK)){
		cerr << "No se pudo encontrar " << installPath << ".";
		return -1;
	}
}
