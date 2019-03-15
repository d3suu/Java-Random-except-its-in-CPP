# Java Random except its in CPP
Implementation of Java Random class in C++

## Usage
You have to create object of ```JavaRandom``` class, and then initialise it with ```Random()```, ```Random(long seed)```, or ```setSeed(long seed)```.

```cpp
JavaRandom rnd;
rnd.setSeed(1234L);
```

## Development
All comments about functions are in header file. If something doesnt work, grep files with "TODO", to check if its in development stage.

Unstable files will be probably in "devel" branch.

## Testing
Build ```test_all.cpp``` using ```g++ test_all.cpp JavaRandom.cpp -o test_all```, and check its output with Java code inside it.

## Sources
Random class source - [http://developer.classpath.org/doc/java/util/Random-source.html](http://developer.classpath.org/doc/java/util/Random-source.html)<br />
Random class documentation - [https://docs.oracle.com/javase/7/docs/api/java/util/Random.html](https://docs.oracle.com/javase/7/docs/api/java/util/Random.html)

## FAQ
Q: Why tho?<br />
A: I wanted to port some application from Java to C/C++, but it used Random class. There is probably better solution than this project ¯\\\_(ツ)\_/¯
