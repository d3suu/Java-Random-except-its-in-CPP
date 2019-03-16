#include "JavaRandom.hpp"
#include <stdio.h>

// build with 'g++ test_all.cpp JavaRandom.cpp -o test_all'

int main(){
	JavaRandom rnd;
	rnd.Random(2137L);
	printf("first seed = %ld\n", rnd.getSeed());
	printf("random int: %d\n", rnd.nextInt());
	printf("random int (max 100): %d\n", rnd.nextInt(100));
	//printf("random bytes
	printf("random long: %ld\n", rnd.nextLong());
	printf("random bool: %s\n", rnd.nextBoolean() ? "true" : "false");
	printf("random float: %f\n", rnd.nextFloat());
	printf("random double: %f\n", rnd.nextDouble());
	printf("random gaussian: %f\n", rnd.nextGaussian());

	rnd.Random();
	printf("first seed (1970 time) = %ld\n", rnd.getSeed());
	printf("random int (1970 time): %d\n", rnd.nextInt());
	return 0;
}

/*
This code is equivalent to this Java code:

import java.util.*;

public class RandomTest {
   public static void main( String args[] ) {

      // create random object
      Random rnd = new Random(2137);

      // check next int value  
      System.out.println("random int: " + rnd.nextInt());
      System.out.println("random int (max 100): " + rnd.nextInt(100));
      //System.out.println("random bytes")
      System.out.println("random long: " + rnd.nextLong());
      System.out.println("random bool: " + rnd.nextBoolean());
      System.out.println("random float: " + rnd.nextFloat());
      System.out.println("random double: " + rnd.nextDouble());
      System.out.println("random gaussian: " + rnd.nextGaussian());
      
      Random rnd_a = new Random();
      System.out.println("random int (1970 time): " + rnd_a.nextInt());
   }    
}
*/
