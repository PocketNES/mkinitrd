#!/usr/bin/python3
import requests os

randomSeed = seed()

def getPackage(packageName):
	deps = requests.get("https://pocketlinux32.000webhostap.com/package-deps/" + packageName)
	if deps.status_code == 404:
		print("Warning: Failed to download dependencies (not found), assuming it has none.")
	elif deps.status_code >= 500:
		print("Error: Failed to download dependencies due to a remote server error")
		exit(3)
	elif deps.status_code >= 400:
		print("Error: Failed to download dependencies due to a internal system error")
		exit(3)

	for i in deps:
		getPackage(i)

print("Package manager, Version 0.02")
print("(c)2021 pocketlinux32, Under GPLv3")

