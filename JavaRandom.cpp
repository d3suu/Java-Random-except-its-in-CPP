#include <chrono> // system_clock::now, time_since_epoch
#include <math.h> // sqrt, log
#include <algorithm> // std::min

#include "JavaRandom.hpp"

void JavaRandom::Random(void){
	using namespace std::chrono;
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	this->seed = ms.count();
};

void JavaRandom::Random(long inputSeed){
	this->initSeed = inputSeed;
	this->seed = (inputSeed ^ 0x5DEECE66DL) & ((1L << 48) - 1);
};

void JavaRandom::setSeed(long inputSeed){
	this->Random(inputSeed);
};

long JavaRandom::getSeed(void){
	return this->seed;
};

long JavaRandom::getInitSeed(void){
	return this->initSeed;
};

int JavaRandom::next(int bits){
	this->seed = (this->seed * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
	return (int)(this->seed >> (48 - bits));
};

int JavaRandom::nextInt(void){
	return this->next(32);
};

int JavaRandom::nextInt(int n){
	if(n<=0){
		return -1; // Error
	}
	if((n & -n) == n){
		return (int)((n * (long)next(31)) >> 31);
	}

	int bits, val;
	do{
		bits = next(31);
		val = bits % n;
	}
	while(bits - val + (n-1) < 0);

	return val;
};

void JavaRandom::nextBytes(char* bytes, int n){ // TODO: fix-me plz
	/*		Old method
	bytes = new char[n];
	for(int i = 0; i<n;){
		for(int rnd = this->nextInt(), n = std::min(n-i, 4); n-- > 0; rnd >>= 8){
			bytes[i++] = (char)rnd;
		}
	}
	*/
	
	///*		New method
	bytes = new char[n];
	int random;
	int max = n & 0xfffffffc; // n & ~0x3
	for(int i = 0; i < max; i += 4){
		random = this->next(32);
		bytes[i] = (char)random;
		bytes[i+1] = (char)(random >> 8);
		bytes[i+2] = (char)(random >> 16);
		bytes[i+3] = (char)(random >> 24);
	}
	if(max < n){
		random = this->next(32);
		for(int j = max; j < n; j++){
			bytes[j] = (char)random;
			random >>= 8;
		}
	}
	//*/
};

long JavaRandom::nextLong(void){
	return ((long)this->next(32) << 32) + this->next(32);
};

bool JavaRandom::nextBoolean(void){
	return this->next(1) != 0;
};

float JavaRandom::nextFloat(void){
	return this->next(24) / ((float)(1 << 24));
};

double JavaRandom::nextDouble(void){
	return (((long)this->next(26) << 27) + this->next(27)) / (double)(1L << 53);
};

double JavaRandom::nextGaussian(void){
	if(this->haveNextNextGaussian){
		this->haveNextNextGaussian = false;
		return nextNextGaussian;
	}else{
		double v1, v2, s;
		do{
			v1 = 2 * this->nextDouble() - 1;
			v2 = 2 * this->nextDouble() - 1;
			s = v1 * v1 + v2 * v2;
		}while(s >= 1 || s == 0);

		double multiplier = sqrt(-2 * log(s)/s);
		this->nextNextGaussian = v2 * multiplier;
		this->haveNextNextGaussian = true;
		return v1 * multiplier;
	}
};
