#include <iostream>
#include <math.h>

//f(x) = Asin(Bx + C) + De^(Ex+F) + G|Hx + I| + J

using namespace std;

const double ACCURACY=0.000000001;
double A,B,C,D,E,F,G,H,I,J;

//#define e 2,71828182

double szukaj(double p, double q, double yp, double yq){
	
	if(fabs(q-p)<ACCURACY) return q;
	
	double x,y;
	x=(q+p)/2.0;
	
	y=A*sin(B*x + C) + D*exp(E*x+F) + G*fabs(H*x + I) + J;
	//yp=A*sin(B*p + C) + D*exp(E*p+F) + G*fabs(H*p + I) + J;
	//yq=A*sin(B*q + C) + D*exp(E*q+F) + G*fabs(H*q + I) + J;
	
	if(y==0) return 0;
	if(y*yp<0) return szukaj(p, x, yp, y);
	else return szukaj(x,q,y,yq);

}

int main(){
	double p,q,x,yp,yq;
	
	cin>>p>>q>>A>>B>>C>>D>>E>>F>>G>>H>>I>>J;

	yp=A*sin(B*p + C) + D*exp(E*p+F) + G*fabs(H*p + I) + J;
	yq=A*sin(B*q + C) + D*exp(E*q+F) + G*fabs(H*q + I) + J;
	
	cout.fixed;
	cout.precision(8);
	double y=szukaj(p,q, yp,yq);
	cout<<y<<"\n";
	
}

