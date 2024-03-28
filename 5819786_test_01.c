#include <stdio.h>
#define MAX_DEGREE 101

struct polynomial {
	int degree;
	float coef[MAX_DEGREE];
};

void print_poly(struct polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}


struct polynomial poly_mult(struct polynomial A, struct polynomial B) {
	struct polynomial C;
	C.degree = A.degree + B.degree;

	for (int i = 0; i <= C.degree; i++) {
		C.coef[i] = 0.0;
	}

	// °ö¼À ¼öÇà
	for (int i = 0; i <= A.degree; i++) {
		for (int j = 0; j <= B.degree; j++) {
			C.coef[i + j] += A.coef[i] * B.coef[j];
		}
	}

	return C;
}

int main() {
	struct polynomial a = { 3, {4,3,2,1} };
	struct polynomial b = { 2, {3,2,8} };

	print_poly(a);
	print_poly(b);
	printf("----------------------------------------------------------------------------------\n");
	struct polynomial c = poly_mult(a, b);
	print_poly(c);

	return 0;
}