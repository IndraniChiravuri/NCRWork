long int product(int x, int y) {
	extern long int mul;
	mul = x * y;
	return mul;
}