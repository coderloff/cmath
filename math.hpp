#include <iostream>
#include <math.h>

using std::ostream;
using std::max;
using std::min;

namespace Math{
	const double PI = 3.141592;
	
	class Vector2{
	private:
		double x, y;
		
	public:
		// Constructors
		Vector2();
		Vector2(double, double);
		Vector2(const Vector2&);
		// Static
		static Vector2 Down;
		static Vector2 Up;
		static Vector2 Left;
		static Vector2 Right;
		static Vector2 One;
		static Vector2 Zero;
		static double Dot(const Vector2&, const Vector2&);
		static double Angle(const Vector2&, const Vector2&);
		static double Distance(const Vector2&, const Vector2&);
		static Vector2 ClampMagnitude(const Vector2&, int);
		static Vector2 Max(const Vector2&, const Vector2&);
		static Vector2 Min(const Vector2&, const Vector2&);
		// Dynamic
		double Magnitude;
		Vector2* Normalized;
		bool Equals(const Vector2&);
		void Normalize();
		void Set(double, double);
		Vector2& operator+(const Vector2&);
		friend ostream& operator<<(ostream&, const Vector2&);
		Vector2& operator=(const Vector2&);
	};
}
