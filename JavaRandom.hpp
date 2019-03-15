class JavaRandom {
	private:
		// Seed value (changes every next*() function call)
		long seed;

		// Initial seed value
		long initSeed;
		
		// Gaussian values
		double nextNextGaussian;
		bool haveNextNextGaussian = false;

	public:
		void Random(void);
		/* Random(void)
		Initialises seed value with milliseconds since 1970
		WORK IN PROGRESS - TODO */

		void Random(long inputSeed);
		/* Random(long inputSeed)
		Initialises seed value with inputSeed */

		void setSeed(long inputSeed);
		/* setSeed(long inputSeed)
		Same as Random(long inputSeed) */

		long getSeed(void);
		/* getSeed(void)
		Returns current seed value */

		long getInitSeed(void);
		/* getPreSeed(void)
		Returns initial seed value */

		int next(int bits);
		/* next(int bits)
		Returns next pseudorandom number */

		int nextInt(void);
		/* nextInt(void)
		Returns next pseudorandom int */

		int nextInt(int n);
		/* nextInt(int n)
		Returns next pseudorandom int in range of 0 - n */

		//void nextBytes // TODO

		long nextLong(void);
		/* nextLong(void)
		Returns next pseudorandom long */

		bool nextBoolean(void);
		/* nextBoolean(void)
		Returns next pseudorandom bool */

		float nextFloat(void);
		/* nextFloat(void)
		Returns next pseudorandom float */

		double nextDouble(void);
		/* nextDouble(void)
		Returns next pseudorandom double */

		double nextGaussian(void);
		/* nextGaussian(void)
		Returns next pseudorandom gaussian distributed double */
};
