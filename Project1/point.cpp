//#include "point.h"

//std::ostream& operator<<(std::ostream& out, point& obj)
//{
//	out << " { " << obj.x << ", " << obj.y << ", " << obj.z << " } ";
//	return out;
//}
//
//point operator*(point& l, point& r)
//{
//	point tmp;
//	tmp.x = l.y * r.z - l.z * r.y;
//	tmp.y = l.x * r.z - l.z * r.x;
//	tmp.z = l.x * r.y - l.y * r.x;
//	return tmp;
//}
//
//void operator+=(point& l, const point& r)
//{
//	l.x += r.x;
//	l.y += r.y;
//	l.z += r.z;
//}
//
//point& point::operator=(int r)
//{
//	x = r;
//	y = z = 0;
//	return *this;
//}