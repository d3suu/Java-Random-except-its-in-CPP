# Java Random except its in CPP
Implementation of Java Random class in C++

## Usage
You have to create object of ```JavaRandom``` class, and then initialise it with ```Random()```, ```Random(long seed)```, or ```setSeed(long seed)```.

```cpp
JavaRandom rnd;
rnd.setSeed(1234L);
```

For more, refer to Java's Random class documentation

## Development
All comments about functions are in header file. If something doesnt work, grep files with "TODO", to check if its in development stage.

```bash
grep -Rn "TODO" .
```

Unstable (untested) files are in "devel" branch. See pull requests for current changes.

## Testing
Build ```test_all.cpp``` using
```bash
g++ test_all.cpp JavaRandom.cpp -o test_all
./test_all
```

For speed test, use ```SpeedTest/test.sh``` script
```
Java-Random-except-its-in-CPP/speed-test$ ./test.sh
[!] Building Java test...
[!] Building C++ test...
[!] Testing Java time...

real	0m41,680s
user	0m41,471s
sys	0m0,040s
[!] Testing C++ time...

real	0m16,452s
user	0m16,356s
sys	0m0,016s
```

## Sources
Java Random class source - [http://developer.classpath.org/doc/java/util/Random-source.html](http://developer.classpath.org/doc/java/util/Random-source.html)<br />
Java Random class documentation - [https://docs.oracle.com/javase/7/docs/api/java/util/Random.html](https://docs.oracle.com/javase/7/docs/api/java/util/Random.html)

## Known bugs, differences
### ...and probably unknown bugs too
 - ```void nextBytes()``` needs two arguments instead of one:
   - ```char* bytes``` - a pointer to char array
   - ```int n``` - number of bytes in array
 - There is no class constructor. ```Random()``` and ```setSeed()``` takes care of that.
 - There is *probably* bug with ```next()``` function, becouse of unsigned right shift.
 - JavaRandom has two more functions:
   - ```long getSeed()``` - returns current seed
   - ```long getInitSeed()``` - returns initial seed

## FAQ
Q: Why tho?<br />
A: I wanted to port some application from Java to C/C++, but it used Random class. ¯\\\_(ツ)\_/¯
