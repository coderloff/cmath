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
		double magnitude;
		Vector2* normalized;
		
	public:
		// Constructors
		Vector2();
		Vector2(double, double);
		Vector2(const Vector2&);
		// Static
		static Vector2 Up;
		static Vector2 Down;
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
		const double& X { x };
		const double& Y { y };
		const double& Magnitude { magnitude };
		const Vector2* Normalized { normalized };
		bool Equals(const Vector2&);
		void Normalize();
		void Set(double, double);
		Vector2& operator+(const Vector2&);
		friend ostream& operator<<(ostream&, const Vector2&);
		Vector2& operator=(const Vector2&);
	};

	class Vector3{
	private:
		double x, y, z;
		double magnitude;
		Vector3* normalized;
		
	public:
		// Constructors
		Vector3();
		Vector3(double, double, double);
		Vector3(const Vector3&);
		// Static
		static Vector3 Up;
		static Vector3 Down;
		static Vector3 Left;
		static Vector3 Right;
		static Vector3 Forward;
		static Vector3 Backward;
		static Vector3 One;
		static Vector3 Zero;
		static double Dot(const Vector3&, const Vector3&);
		static double Angle(const Vector3&, const Vector3&);
		static double Distance(const Vector3&, const Vector3&);
		static Vector3 ClampMagnitude(const Vector3&, int);
		static Vector3 Max(const Vector3&, const Vector3&);
		static Vector3 Min(const Vector3&, const Vector3&);
		// Dynamic
		const double& X { x };
		const double& Y { y };
		const double& Z { z };
		const double& Magnitude { magnitude };
		const Vector3* Normalized { normalized };
		bool Equals(const Vector3&);
		void Normalize();
		void Set(double, double, double);
		Vector3& operator+(const Vector3&);
		friend ostream& operator<<(ostream&, const Vector3&);
		Vector3& operator=(const Vector3&);
	};

}
