#!/usr/bin/python3
import requests, os, sys

randomSeed = seed()

def getPackage(packageName):
	request = requests.get("http://pocketlinux32.000webhostapp.com/package-deps/" + packageName)
	if request.status_code == 404:
		print("Warning: Dependencies not found in remote server, assuming it has none.")
	elif request.status_code >= 500:
		print("Error: Failed to download dependencies due to a remote server error")
		exit(3)
	elif request.status_code >= 400:
		print("Error: Failed to download dependencies due to an internal system error")
		exit(3)

	for i in request.content:
		getPackage(i)

	request = requests.get("http://pocketlinux32.000webhostapp.com/packages/" + packageName)
	if request.status_code == 404:
		print("Error: Package not found in remote server"
		exit(4)
	elif request.status_code >= 500:
		print("Error: Failed to downloads package due to a remote server error")
		print("Error Code: " + request.status_code)
		exit(4)
	elif request.status_code >= 400:
		print("Error: Failed to downloads package due to an internal system error")
		print("Error Code: " + request.status_code)
		exit(4)
	file = open(packageName, "w")
	file.write(request.content)

if __name__ == "__main__":
	print("Package manager, Version 0.02")
	print("(c)2021 pocketlinux32, Under GPLv3")

	if os.getuid() != 0:
		print("Error: You're not root. Priviledge escalation is required")
		exit(1)
	elif len(sys.argv) < 3:
		print("Usage: " + sys.argv[0] + " [install | remove] {package}")
		exit(2)

	os.mkdir("/tmp/pls-pkg" + randomSeed)
	os.chdir("/tmp/pls-pkg" + randomSeed)
	if sys.argv[2] == "install":
		getPackage(sys.argv[3])
	elif sys.argv[2] == "remove":
		os.system("/usr/bin/pls-install r" + sys.argv[3])
