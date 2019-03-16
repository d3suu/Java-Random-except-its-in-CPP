#include <stdio.h>
#include "../JavaRandom.hpp"

int main(){
	JavaRandom rnd;
	rnd.setSeed(2137);

	for(long i = 0; i<=1000000000; i++){
		rnd.nextLong();
	}
	return 0;
}
