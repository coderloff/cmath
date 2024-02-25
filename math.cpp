#include "math.hpp"

using std::cout;

namespace Math{
// Vector2

	// Constructors
	Vector2::Vector2() : x(0), y(0), magnitude(0), normalized(new Vector2(Vector2::Zero)){}
	Vector2::Vector2(double a, double b) : x(a), y(b), magnitude(sqrt(a*a+b*b)), normalized(new Vector2()){
		if(Magnitude){ normalized->x = a/magnitude; normalized->y = b/magnitude; }
	}
	Vector2::Vector2(const Vector2& v) : x(v.x), y(v.y), magnitude(v.magnitude), normalized(v.normalized){}

	// Static
	Vector2 Vector2::Up { Vector2(0, 1) };
	Vector2 Vector2::Down { Vector2(0, -1) };
	Vector2 Vector2::Left { Vector2(-1, 0) };
	Vector2 Vector2::Right { Vector2(1, 0) };
	Vector2 Vector2::One { Vector2(1, 1) };
	Vector2 Vector2::Zero { Vector2(0, 0) };

	double Vector2::Dot(const Vector2& a, const Vector2& b){
		return a.x*b.x+a.y*b.y;
	}
	double Vector2::Angle(const Vector2& a, const Vector2& b){
		return acos(Vector2::Dot(*a.normalized, *b.normalized)) * 180 / PI;
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
		return Vector2(a.x/a.magnitude*ml, a.y/a.magnitude*ml);
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
		if(magnitude) { x /= magnitude; y /= magnitude; }
	}
	void Vector2::Set(double a, double b){
		x = a; y = b; magnitude = sqrt(a*a+b*b);
		delete normalized;
		normalized = new Vector2(x/magnitude, y/magnitude);
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
	
// Vector3

	// Constructors
	Vector3::Vector3() : x(0), y(0), z(0), magnitude(0), normalized(new Vector3(Vector3::Zero)){}
	Vector3::Vector3(double a, double b, double c) : x(a), y(b), z(c), magnitude(sqrt(a*a+b*b+c*c)), normalized(new Vector3()){
		if(magnitude){ normalized->x = a/magnitude; normalized->y = b/magnitude; normalized->z = c/magnitude; }
	}
	Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z), magnitude(v.magnitude), normalized(v.normalized){}

	// Static
	Vector3 Vector3::Up { Vector3(0, 1, 0) };
	Vector3 Vector3::Down { Vector3(0, -1, 0) };
	Vector3 Vector3::Left { Vector3(-1, 0, 0) };
	Vector3 Vector3::Right { Vector3(1, 0, 0) };
	Vector3 Vector3::Forward { Vector3(1, 0, 1) };
	Vector3 Vector3::Backward { Vector3(1, 0, -1) };
	Vector3 Vector3::One { Vector3(1, 1, 1) };
	Vector3 Vector3::Zero { Vector3(0, 0, 0) };

	double Vector3::Dot(const Vector3& a, const Vector3& b){
		return a.x*b.x+a.y*b.y+a.z*b.z;
	}
	double Vector3::Angle(const Vector3& a, const Vector3& b){
		return acos(Vector3::Dot(*a.normalized, *b.normalized)) * 180 / PI;
	}
	double Vector3::Distance(const Vector3& a, const Vector3& b){
		return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
	}
	Vector3 Vector3::Max(const Vector3& a, const Vector3& b){
		return Vector3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
	}
	Vector3 Vector3::Min(const Vector3& a, const Vector3& b){
		return Vector3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
	}
	Vector3 Vector3::ClampMagnitude(const Vector3& a, int ml){
		return Vector3(a.x/a.magnitude*ml, a.y/a.magnitude*ml, a.z/a.magnitude*ml);
	}

	// Dynamic
	//double Vector2::Magnitude() const{ return sqrt(x*x+y*y); }
	// Vector2 Vector2::Normalized() const{
	// 	return Vector2(x/Magnitude, y/Magnitude);
	// }
	bool Vector3::Equals(const Vector3& v){
		return x == v.x && y == v.y && z == v.z;
	}
	void Vector3::Normalize(){
		if(magnitude) { x /= magnitude; y /= magnitude; z /= magnitude; }
	}
	void Vector3::Set(double a, double b, double c){
		x = a; y = b; z = c; magnitude = sqrt(a*a+b*b);
		delete normalized;
		normalized = new Vector3(x/magnitude, y/magnitude, z/magnitude);
	}
	Vector3& Vector3::operator+(const Vector3& v){
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	Vector3& Vector3::operator=(const Vector3& v){
		x = v.x; y = v.y; z = v.z;
		return *this;
	}
	ostream& operator<<(ostream& out, const Vector3& v){
		out << v.x << ' ' << v.y << ' ' << v.z << '\n';
		return out;
	}
}
