#ifndef _MATH_H
#define _MATH_H

class Vector2f
{
public:
	Vector2f();
	Vector2f(float _x, float _y);
	~Vector2f();

private:
	float m_x;
	float m_y;

};
/*
class Vector3f
{
public:
	Vector3f();
	Vector3f(float _x, float _y, float _z);
	~Vector3f();

private:
	float m_x;
	float m_y;
	float m_z;
}
*/

#endif