
#include <stdio.h>
#include <math.h>



int osiagnieto_dokladnosc = 0;
double ln(double x,int M, double epsilon){
	double y = 0.0;
	double temp;
	for (int k=0;k < M;k++) {
		temp = pow((x - 1) / (x + 1), 2 * k + 1) / (2 * k + 1);
		if (fabs(temp) < epsilon) {
			osiagnieto_dokladnosc = 1;
			return 2 * y;
		}
		y += temp;
		
	}
	
	return 2 * y;
}




int main(){
	double a, b, n,y,epsilon;
	int M;
	
	printf("Podaj poczatek przedzialu \n");
	scanf_s("%lf", &a);
	if (a <= 0) {
		printf("zly poczatek przedzialu");
		return 0;
	}
	printf("Podaj koniec przedzialu \n");
	scanf_s("%lf", &b);
	if (a >= b) {
		printf("poczatek jest wiekszy od konca");
		return 0;
	}
	printf("Podaj liczbe punktow podzialu \n");
	scanf_s("%lf", &n);
	if (n < 0) {
		printf("ujemna liczba punktow przedzialu");
		return 0;
	}

	printf("podaj maksymalna liczbe iteracji \n");
	scanf_s("%d", &M);
	if (M <= 0) {
		printf("Maksymalna liczba iteracji musi byc wieksza od zera\n");
		return 0;
	}
	printf("Podaj epsilon\n");
	scanf_s("%lf", &epsilon);
	if (epsilon < 0) {
		printf("epsilon jest mniejszy od zera\n");
		return 0;
	}
	 
	
	

	
	double step = (b - a) / n;
	double x = a;
	while (x<=b) {
		y=ln(x,M, epsilon);
		printf("(%lf, %lf), osiagnieto dokladnosc: %d \n", x, y, osiagnieto_dokladnosc);
		osiagnieto_dokladnosc = 0;
		x += step;
		
	}
	
	y = ln(b, M, epsilon);
	printf("(%lf, %lf), osiagnieto dokladnosc: %d \n", b, y, osiagnieto_dokladnosc);
	
	return 0;
}
	
	

