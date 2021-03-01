#!/usr/bin/python3
import requests

def getPackageDeps(packageName):
	request.get("https://pocketlinux32.000webhostap.com/package-deps/package/" + packageName)

def getPackage(packageName):
	dependencies = getPackageDeps(packageName)

if __name__ == "__main__":
	print("Package manager, Version 0.02")
	print("(c)2021 pocketlinux32, Under GPLv3")
