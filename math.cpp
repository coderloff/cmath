#include "math.hpp"

using std::cout;

namespace Math{
// Vector2

	// Constructors
	Vector2::Vector2() : x(0), y(0), Magnitude(0), Normalized(new Vector2(Vector2::Zero)){}
	Vector2::Vector2(double a, double b) : x(a), y(b), Magnitude(sqrt(a*a+b*b)), Normalized(new Vector2()){
		if(Magnitude){ Normalized->x = a/Magnitude; Normalized->y = b/Magnitude; }
	}
	Vector2::Vector2(const Vector2& v) : x(v.x), y(v.y), Magnitude(v.Magnitude), Normalized(v.Normalized){}

	// Static
	Vector2 Vector2::Down { Vector2(0, -1) };
	Vector2 Vector2::Up { Vector2(0, 1) };
	Vector2 Vector2::Left { Vector2(-1, 0) };
	Vector2 Vector2::Right { Vector2(1, 0) };
	Vector2 Vector2::One { Vector2(1, 1) };
	Vector2 Vector2::Zero { Vector2(0, 0) };

	double Vector2::Dot(const Vector2& a, const Vector2& b){
		return a.x*b.x+a.y*b.y;
	}
	double Vector2::Angle(const Vector2& a, const Vector2& b){
		return acos(Vector2::Dot(*a.Normalized, *b.Normalized)) * 180 / PI;
	}
	double Vector2::Distance(const Vector2& a, const Vector2& b){
		return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	}
	Vector2 Vector2::Max(const Vector2& a, const Vector2& b){
		return Vector2(max(a.x, b.x), max(a.y, b.y));
	}
	Vector2 Vector2::Min(const Vector2& a, const Vector2& b){
		return Vector2(min(a.x, b.x), min(a.y, b.y));
	}
	Vector2 Vector2::ClampMagnitude(const Vector2& a, int ml){
		return Vector2(a.x/a.Magnitude*ml, a.y/a.Magnitude*ml);
	}

	// Dynamic
	//double Vector2::Magnitude() const{ return sqrt(x*x+y*y); }
	// Vector2 Vector2::Normalized() const{
	// 	return Vector2(x/Magnitude, y/Magnitude);
	// }
	bool Vector2::Equals(const Vector2& v){
		return x == v.x && y == v.y;
	}
	void Vector2::Normalize(){
		if(Magnitude) { x /= Magnitude; y /= Magnitude; }
	}
	void Vector2::Set(double a, double b){
		x = a; y = b; Magnitude = sqrt(a*a+b*b);
		delete Normalized;
		Normalized = new Vector2(x/Magnitude, y/Magnitude);
	}
	Vector2& Vector2::operator+(const Vector2& v){
		x += v.x; y += v.y;
		return *this;
	}
	Vector2& Vector2::operator=(const Vector2& v){
		x = v.x; y = v.y;
		return *this;
	}
	ostream& operator<<(ostream& out, const Vector2& v){
		out << v.x << ' ' << v.y << '\n';
		return out;
	}
}
