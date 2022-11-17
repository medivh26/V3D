#ifndef V3D_H
#define V3D_H
#include <string>
#include <iostream>

using namespace std;

class V3D
{
	friend void angle(const V3D &v1, const V3D &v2);
	public:
		V3D(string n,double X=0.0,double Y=0.0,double Z=0.0);
		~V3D();
		void setX(double);
		void setY(double);
		void setZ(double);
		double getX(void) const;
		double getY(void) const;
		double getZ(void) const;
		string getName(void) const;
		static int  getCount(void);
		void print(void) const;
		
		V3D &algebra (const V3D &b);
		V3D crossProduct (const V3D &b);
		
	private:
		double x;
		double y;
		double z;
		const string name;
		static int count;
};

#endif
