#include "V3D.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int V3D::count=0;

V3D::V3D(string n,double X,double Y,double Z):name(n)
{
	setX(X);
	setY(Y);
	setZ(Z);
	count++;
	cout<<"V3D OBJECT CONSTRUCTOR "<<getName()<<endl;
}

V3D::~V3D()
{
	count--;
	cout<<"V3D OBJECT DESTRUCTOR "<<getName()<<endl;
}

void V3D::setX(double X){
	x=X;
}
void V3D::setY(double Y){
	y=Y;
}
void V3D::setZ(double Z){
	z=Z;
}
double V3D::getX(void) const{
	return x;
}
double V3D::getY(void) const{
	return y;
}
double V3D::getZ(void) const{
	return z;
}
string V3D::getName(void) const{
	return name;
}
int  V3D::getCount(void){
	return count;
}
void V3D::print(void) const{
	cout<<getName()<<"("<<getX()<<","<<getY()<<","<<getZ()<<")"<<endl;
}
V3D &V3D::algebra (const V3D &b){
	this->x = this->x - 4*(b.getX());
	this->y = this->y - 4*(b.getY());
	this->z = this->z - 4*(b.getZ());
	
	return *this;
}

V3D V3D::crossProduct (const V3D &b){
	V3D dump(" dump");
	dump.x= this->getY()*b.getZ()- this->getZ()*b.getY();
	dump.y= this->getZ()*b.getX()- this->getX()*b.getZ();
	dump.z= this->getX()*b.getY()- this->getY()*b.getX();
	return dump;
}

void angle(const V3D &v1, const V3D &v2){
	double dot=v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	double mag_v1= sqrt(pow(v1.x,2)+pow(v1.y,2)+pow(v1.z,2));
	double mag_v2= sqrt(pow(v2.x,2)+pow(v2.y,2)+pow(v2.z,2));
	double angle = acos(dot/(mag_v1*mag_v2))*180.0/M_PI;
	cout<<"The angles between "<<endl;
	v1.print();
	v2.print();
	cout<<"angles: "<<angle<<endl;
}
