#pragma once
#include<iostream>

struct point
{
	int x;
	int y;
	int z;
	point& operator= (int r);
};

std::ostream& operator<< (std::ostream& out, point& obj);
point operator* (point& l, point& r);
void operator+= (point& l, const point& r);