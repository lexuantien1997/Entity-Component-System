#ifndef VECTOR2_H_
#define VECTOR2_H_

template <typename T>
class Vector2
{
public:

	T x, y;
	
	Vector2():x(0),y(0) { }

	Vector2(T xx, T yy) :x(xx), y(yy) {}

	// =================== Negative ===================

	Vector2 operator-(const Vector2<T> &a)
	{
		return Vector<T>(-a.x, -a.y);
	}

	~Vector2(){ }
};


template <typename T>
Vector2<T>& operator-=(Vector2<T> &a, const Vector2<T> &b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

template <typename T>
Vector2<T>& operator+=(Vector2<T> &a, const Vector2<T> &b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

template <typename T>
Vector2<T> operator +(const Vector2<T>& a, const Vector2<T>& b)
{
	return Vector2<T>(a.x + b.x, a.y + b.y);
}

template <typename T>
Vector2<T> operator -(const Vector2<T>& a, const Vector2<T>& b)
{
	return Vector2<T>(a.x - b.x, a.y - b.y);
}

template <typename T>
Vector2<T> operator *(const Vector2<T>& a, T b)
{
	return Vector2<T>(a.x * b, a.y * b);
}

template <typename T>
Vector2<T> operator *(T a, const Vector2<T>& b)
{
	return Vector2<T>(a.x * b, a.y * b);
}

template <typename T>
Vector2<T>& operator *=(Vector2<T>& a, T b)
{
	a.x *= b;
	a.y *= b;

	return a;
}

template <typename T>
Vector2<T> operator /(const Vector2<T>& a, T b)
{
	return Vector2<T>(a.x / b, a.y / b);
}
template <typename T>
Vector2<T>& operator /=(Vector2<T>& a, T b)
{
	a.x /= b;
	a.y /= b;

	return a;
}

template <typename T>
bool operator ==(const Vector2<T>& a, const Vector2<T>& b)
{
	return (a.x == b.x) && (a.y == b.y);
}

template <typename T>
bool operator !=(const Vector2<T>& a, const Vector2<T>& b)
{
	return(a.x != b.x) || (a.y != b.y);
}


typedef Vector2<float>        Vector2f;
typedef Vector2<int>          Vector2i;

#endif // !VECTOR2_H_
