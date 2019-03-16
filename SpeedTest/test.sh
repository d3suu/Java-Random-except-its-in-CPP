#!/bin/bash 

if [ ! -f ./RandomTest.class ]; then
	echo "[!] Building Java test..."
	javac RandomTest.java
fi

if [ ! -f ./RandomTestCpp ]; then
	echo "[!] Building C++ test..."
	g++ ../JavaRandom.cpp RandomTest.cpp -o RandomTestCpp
fi

echo "[!] Testing Java time..."
time java RandomTest

echo "[!] Testing C++ time..."
time ./RandomTestCpp
