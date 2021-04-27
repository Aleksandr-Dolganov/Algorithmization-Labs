#include <stdio.h>
#include<math.h>

double area(double, double, double, double, double, double, double, double);
double lines(double, double, double, double);

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4, S;
	scanf_s("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	S = area(x1, y1, x2, y2, x3, y3, x4, y4);
	printf("%lf", S);
}

double lines(double x1, double y1, double x2, double y2)
{
	double a, b, c;
	b = x2 - x1;
	c = y2 - y1;
	a = sqrt(pow(b, 2) + pow(c, 2));

	return a;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double a, b, c, d, p, S;
	a = lines(x1, y1, x2, y2);
	b = lines(x2, y2, x3, y3);
	c = lines(x4, y4, x3, y3);
	d = lines(x4, y4, x1, y1);
	p = (a + b + c + d) / 2;
	S = sqrt((p - a) * (p - b) * (p - c) * (p - d));

	return S;
}