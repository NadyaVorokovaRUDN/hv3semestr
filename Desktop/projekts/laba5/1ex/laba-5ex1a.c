#include <stdio.h> 
#include <stdbool.h>

bool isBissectrice(double, double);
bool isVertical(double);
bool isHorizontal(double);

void main() {
	double for_check[5][3] = {{3., 3.}, {-1., -4.}, {-4.,1.}, {-5., 4.}, {3., 5.}, {5.,-3.},      
	{3., -1.}, {1.,1.}, {0.,0.}, {3.,-3.}};

	/* 1-ые координаты - входят ли они в закраш. область 1 четверти 
	2-ые координаты - входят ли они в третью четверть 
	3-ие координаты - входят ли они в закраш. область 2 четверти 
	4-ые координаты - входят ли они в незакраш. область 2 четверти под графиком 
	5-ые координаты - входят ли они в незакраш. обл. 2 четверти сверху графика 
	6-ые координаты - входят ли они в незакраш. обл. 4 четверти под графиком 
	7-ые координаты - входят ли они в незакраш. обл. 4 четверти сверху графика 
	8-ые координаты - входят ли они в незакраш. обл. 1 чертверти 
	9-ые координаты - как ведут себя в начале координат 
	10-ые координаты - как ведут себя на границе графика  */

	double x;
	double y;

	for (int i = 0; i < 10; i++) {
		printf("Проверка %d: %d\n", i+1, (isBissectrice(for_check[i][0], for_check[i][1]) 
		&& (!isVertical(for_check[i][0])) && (!isHorizontal(for_check[i][1]))) || 
		(isVertical(for_check[i][0]) && isHorizontal(for_check[i][1])));
	}

	printf ("Введите координату х: ");
	scanf ("%lf", &x);
	printf ("Введите координату y: ");
	scanf ("%lf", &y);
	printf("Проверка от пользователя: %d\n", (isBissectrice(x, y) 
	&& (!isVertical(x)) && (!isHorizontal(y))) || 
	(isVertical(x) && isHorizontal(y)));

}

bool isBissectrice(double x, double y) {
	bool resultat;
	resultat = (y <= -x);
	return resultat;
}

bool isVertical(double x) {
	bool resultat;
	resultat = (x > 4);
	return resultat;
}
bool isHorizontal(double y) {
	bool resultat;
	resultat = (y > 3);
	return resultat;
}