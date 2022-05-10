#pragma once
#include <math.h>
#include <ostream>

struct Vector2D
{
	Vector2D() : x_(0), y_(0) {};
	
	Vector2D(float x, float y) : x_(x), y_(y) {};
	
	// Operator overloading
	Vector2D operator + (const Vector2D& other) const {return {other.x_+x_,other.y_+y_};}
	Vector2D operator * (const float scale) const {return {x_*scale,y_*scale};}
	Vector2D operator / (const float scale) const {return {x_/scale,y_/scale};}
	Vector2D operator - (const Vector2D& other)  const {return {x_-other.x_,y_-other.y_};};

	friend bool operator==(const Vector2D& lhs, const Vector2D& rhs)
	{
		return (int)lhs.x_ == (int)rhs.x_
			&& abs(lhs.y_ - rhs.y_) < 0.5f;
	}

	friend bool operator!=(const Vector2D& lhs, const Vector2D& rhs)
	{
		return !(lhs == rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector2D& obj)
	{
		return os
			<< "x_: " << obj.x_
			<< " y_: " << obj.y_;
	}

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

