#!/usr/bin/python3
import requests os

randomSeed = seed()

def getPackage(packageName):
	request = requests.get("http://pocketlinux32.000webhostapp.com/package-deps/" + packageName)
	if request.status_code == 404:
		print("Warning: Failed to download dependencies (not found), assuming it has none.")
	elif request.status_code >= 500:
		print("Error: Failed to download dependencies due to a remote server error")
		exit(3)
	elif request.status_code >= 400:
		print("Error: Failed to download dependencies due to a internal system error")
		exit(3)

	for i in request:
		getPackage(i)

	request = requests.get("http://pocketlinux32.000webhostapp.com/packages/" + packageName)
	if request.status_code == 404:
		print("Error: Package not found in remote server"
		exit(4)
	elif request.status_code >= 500:
		print("Error: Failed to downloads package")
	file = open(packageName, "w")

print("Package manager, Version 0.02")
print("(c)2021 pocketlinux32, Under GPLv3")

