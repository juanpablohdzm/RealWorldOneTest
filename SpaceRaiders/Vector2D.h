#pragma once
#include <math.h>

struct Vector2D
{
	Vector2D() : x_(0), y_(0) {};
	
	Vector2D(float x, float y) : x_(x), y_(y) {};


	bool IntCmp(const Vector2D& vec) const { return int(x_) == int(vec.x_) && int(y_) == int(vec.y_); }
	// Operator overloading
	Vector2D operator + (const Vector2D& other) const {return {other.x_+x_,other.y_+y_};}
	Vector2D operator * (const float scale) const {return {x_*scale,y_*scale};}
	Vector2D operator / (const float scale) const {return {x_/scale,y_/scale};}
	Vector2D operator - (const Vector2D& other)  const {return {x_-other.x_,y_-other.y_};};

	float Length() const { return sqrt(x_*x_ + y_*y_);}

	float x() const{return x_;}
	float y() const{return y_;}

	void set_x(float x){x_ = x;}
	void set_y(float y){y_ = y;}

	~Vector2D() {}
private:
	float x_;
	float y_;
};

