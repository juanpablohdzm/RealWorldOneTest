#pragma once

struct Vector2D
{
	Vector2D() : x_(0), y_(0) {};
	
	Vector2D(float x, float y) : x_(x), y_(y) {};

	Vector2D(const Vector2D& other)
		: x_(other.x_),
		  y_(other.y_)
	{
	}

	Vector2D(Vector2D&& other) noexcept
		: x_(other.x_),
		  y_(other.y_)
	{
	}

	Vector2D& operator=(const Vector2D& other)
	{
		if (this == &other)
			return *this;
		x_ = other.x_;
		y_ = other.y_;
		return *this;
	}

	Vector2D& operator=(Vector2D&& other) noexcept
	{
		if (this == &other)
			return *this;
		x_ = other.x_;
		y_ = other.y_;
		return *this;
	}

	~Vector2D() {}

	bool IntCmp(const Vector2D& vec) { return int(x_) == int(vec.x_) && int(y_) == int(vec.y_); }
	// Operator overloading
	Vector2D operator + (const Vector2D& other) const {return {other.x_+x_,other.y_+y_};}
	Vector2D operator * (const float scale) const {return {x_*scale,y_*scale};}
	Vector2D operator / (const float scale) const {return {x_/scale,y_/scale};}
	Vector2D operator - (const Vector2D& other)  const {return {x_-other.x_,y_-other.y_};};

	

	float Length();

private:

	float x_;
	float y_;
};

