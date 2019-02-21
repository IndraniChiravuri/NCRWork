long int product(long int x, long int y) {
	extern long int mul;
	mul = x * y;
	return mul;
}