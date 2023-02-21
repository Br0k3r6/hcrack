#!/usr/bin/env python3

import argparse
import subprocess, os
import time

if os.geteuid() != 0: exit("Run it as root.")

version_file = open("lib/VERSION", "r")
version = version_file.read().replace("\n", "")
version_file.close()

print("Starting hcrack (v{})...".format(version))
time.sleep(1.5)

helpfile = open("lib/helpfile.txt", "r")
hcrack_help = str(helpfile.read())
helpfile.close()

def get_arguments():
	parser = argparse.ArgumentParser(add_help=False)
	parser.add_argument("-h", "--help", action="store_true")
	parser.add_argument("-f", "--format")
	parser.add_argument("-w", "--wordlist")
	parser.add_argument("-H", "--hashfile")
	parser.add_argument("-v", "--version", action="store_true")
	return parser.parse_args()

args = get_arguments()
if args.help == True: exit("\n"+hcrack_help)
if args.help == False and args.format == None and args.wordlist == None and args.hashfile == None and args.version == False: exit("\n"+hcrack_help)
if args.version == True:
	version_file = open("lib/VERSION", "r")
	version = version_file.read().replace("\n", "")
	version_file.close()
	exit("-- Hcrack version: "+version)

def basic(hashtype):
	try: hash_load = open(args.hashfile, "r")
	except: exit("[HCRACK][!] Error opening "+args.hashfile+"!")
	file_hash = hash_load.read()
	hash_load.close()
	hash_load = file_hash.split("\n")
	if len(hash_load) != 2: exit("[HCRACK][!] Hash cant loaded from "+args.hashfile+"!")
	else: hash_load = str(hash_load[0])
	print()
	input("Press [ENTER] to start the crack process...")
	print()
	exec_ = "./lib/hash/{}/{} {} {}".format(hashtype, hashtype, hash_load, args.wordlist)
	return str(exec_)

if args.format == "0000": os.system("./parser.out " + basic("md5"))
elif args.format == "0001": os.system("./parser.out " + basic("md4"))
elif args.format == "0002": os.system("./parser.out " + basic("sha256"))
elif args.format == "0003": os.system("./parser.out " + basic("sha512"))
else: exit("[HCRACK][!] The format that you specified does not exist!")
