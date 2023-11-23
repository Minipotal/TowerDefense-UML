#include "colors.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

MyColor::MyColor() : MyColor(0, 255)
{
}

MyColor::MyColor(int rgb) : MyColor(rgb, 255)
{
}

MyColor::MyColor(int r, int g, int b) : MyColor(r * 0x10000 + g * 0x100 + b, 255)
{
}

MyColor::MyColor(int r, int g, int b, int a) : MyColor(r * 0x10000 + g * 0x100 + b, a)
{
}

MyColor::MyColor(int rgb, int a)
{
	setRGBA(rgb, a);
}

int MyColor::r()
{
	return _r;
}

int MyColor::g()
{
	return _g;
}

int MyColor::b()
{
	return _b;
}

int MyColor::a()
{
	return _a;
}

int MyColor::rgb()
{
	return _rgb;
}

int MyColor::rgba()
{
	return _rgba;
}

int MyColor::h()
{
	return _h;
}

int MyColor::s()
{
	return _s;
}

int MyColor::v()
{
	return _v;
}

int MyColor::hsv()
{
	return _hsv;
}

Color MyColor::getSfColor()
{
	return sf::Color(_rgba);
}

void MyColor::printColorHex(bool includeAlpha)
{
	cout << "#" << hex << (includeAlpha ? _rgba : _rgb) << dec;
}

void MyColor::printColor(bool includeAlpha)
{
	cout << "{" << _r << ", " << _g << ", " << _b;
	if (includeAlpha)
	{
		cout << ", " << _a;
	}
	cout << "} ";
}

MyColor MyColor::mixin(MyColor otherCol, float pct)
{
	MyColor mixed;
	mixin(otherCol, &mixed, pct);
	return mixed;
}

void MyColor::mixin(MyColor otherCol, MyColor* savedColor, float pct)
{
	savedColor->setRGBA(
		(otherCol.r() - _r) * pct + _r,
		(otherCol.g() - _g) * pct + _g,
		(otherCol.b() - _b) * pct + _b,
		(otherCol.a() - _a) * pct + _a
	);
}

MyColor MyColor::tripleMixin(MyColor otherCol, MyColor lastColor, float pct)
{
	MyColor mixed;
	tripleMixin(otherCol, lastColor, &mixed, pct);
	return mixed;
}

void MyColor::tripleMixin(MyColor otherCol, MyColor lastColor, MyColor* savedColor, float pct)
{
	MyColor mix1;
	MyColor mix2;
	mixin(otherCol, &mix1, pct);
	otherCol.mixin(lastColor, &mix2, pct);
	mix1.mixin(mix2, savedColor, pct);
}

MyColor MyColor::HSVmixin(MyColor otherCol, float pct)
{
	MyColor mixed;
	HSVmixin(otherCol, &mixed, pct);
	return mixed;
}

void MyColor::HSVmixin(MyColor otherCol, MyColor* savedColor, float pct)
{
	savedColor->setHSVA(
		(otherCol.h() - _h) * pct + _h,
		(otherCol.s() - _s) * pct + _s,
		(otherCol.v() - _v) * pct + _v,
		(otherCol.a() - _a) * pct + _a
	);
}

MyColor MyColor::HSVtripleMixin(MyColor otherCol, MyColor lastColor, float pct)
{
	MyColor mixed;
	HSVtripleMixin(otherCol, lastColor, &mixed, pct);
	return mixed;
}

void MyColor::HSVtripleMixin(MyColor otherCol, MyColor lastColor, MyColor* savedColor, float pct)
{
	MyColor mix1;
	MyColor mix2;
	HSVmixin(otherCol, &mix1, pct);
	otherCol.HSVmixin(lastColor, &mix2, pct);
	mix1.HSVmixin(mix2, savedColor, pct);
}

void MyColor::setR(int r)
{
	setRGBA(r * 0x10000 + _g * 0x100 + _b, _a);
}

void MyColor::setG(int g)
{
	setRGBA(_r * 0x10000 + g * 0x100 + _b, _a);
}

void MyColor::setB(int b)
{
	setRGBA(_r * 0x10000 + _g * 0x100 + b, _a);
}

void MyColor::setA(int a)
{
	setRGBA(_r * 0x10000 + _g * 0x100 + _b, a);
}

void MyColor::setRGB(int rgb)
{
	setRGBA(rgb, _a);
}

void MyColor::setRGB(int r, int g, int b)
{
	setRGBA(r * 0x10000 + g * 0x100 + b, _a);
}

void MyColor::setRGBA(int rgba)
{
	setRGBA(rgba / 0x100, rgba % 0x100);
}

void MyColor::setRGBA(int r, int g, int b, int a)
{
	setRGBA(r * 0x10000 + g * 0x100 + b, a);
}

void MyColor::setRGBA(int rgb, int a)
{
	_rgb = rgb;
	_rgba = rgb * 0x100 + a;
	_a = a;
	_b = rgb % 0x100;
	_g = (rgb % 0x10000) / 0x100;
	_r = rgb / 0x10000;
	RGBtoHSV();
}

void MyColor::setH(int h)
{
	setHSVA(h * 1000000 + _s * 1000 + _v, _a);
}

void MyColor::setS(int s)
{
	setHSVA(_h * 1000000 + s * 1000 + _v, _a);
}

void MyColor::setV(int v)
{
	setHSVA(_h * 1000000 + _s * 1000 + v, _a);
}

void MyColor::setHSV(int hsv)
{
	setHSVA(hsv, _a);
}

void MyColor::setHSV(int h, int s, int v)
{
	setHSVA(h * 1000000 + s * 1000 + v, _a);
}

void MyColor::setHSVA(int h, int s, int v, int a)
{
	setHSVA(h * 1000000 + s * 1000 + v, a);
}

void MyColor::setHSVA(int hsv, int a)
{
	_hsv = hsv;
	_a = a;
	_v = hsv % 1000;
	_s = (hsv % 1000000) / 1000;
	_h = hsv / 1000000;
	HSVtoRGB();
}

void MyColor::RGBtoHSV() {
	double r = _r / 255.0;
	double g = _g / 255.0;
	double b = _b / 255.0;

	double cmax = std::max(std::max(r, g), b);
	double cmin = std::min(std::min(r, g), b);
	double delta = cmax - cmin;

	// Calcul de la composante H (teinte)
	if (delta == 0) {
		_h = 0;  // H indéfini (couleur grise)
	}
	else if (cmax == r) {
		_h = static_cast<int>(60 * ((g - b) / delta) + 360) % 360;
	}
	else if (cmax == g) {
		_h = static_cast<int>(60 * ((b - r) / delta) + 120);
	}
	else {
		_h = static_cast<int>(60 * ((r - g) / delta) + 240);
	}

	// Calcul de la composante S (saturation)
	if (cmax == 0) {
		_s = 0;
	}
	else {
		_s = static_cast<int>((delta / cmax) * 100);
	}

	// Calcul de la composante V (valeur)
	_v = static_cast<int>((cmax) * 100);
}

void MyColor::HSVtoRGB() {
	double h = _h;
	double s = _s / 100.0;
	double v = _v / 100.0;

	int i = static_cast<int>(h / 60) % 6;
	double f = (h / 60) - i;
	double p = v * (1 - s);
	double q = v * (1 - f * s);
	double t = v * (1 - (1 - f) * s);

	switch (i) {
	case 0:
		_r = static_cast<int>(v * 255);
		_g = static_cast<int>(t * 255);
		_b = static_cast<int>(p * 255);
		break;
	case 1:
		_r = static_cast<int>(q * 255);
		_g = static_cast<int>(v * 255);
		_b = static_cast<int>(p * 255);
		break;
	case 2:
		_r = static_cast<int>(p * 255);
		_g = static_cast<int>(v * 255);
		_b = static_cast<int>(t * 255);
		break;
	case 3:
		_r = static_cast<int>(p * 255);
		_g = static_cast<int>(q * 255);
		_b = static_cast<int>(v * 255);
		break;
	case 4:
		_r = static_cast<int>(t * 255);
		_g = static_cast<int>(p * 255);
		_b = static_cast<int>(v * 255);
		break;
	case 5:
		_r = static_cast<int>(v * 255);
		_g = static_cast<int>(p * 255);
		_b = static_cast<int>(q * 255);
		break;
	}
}

bool MyColor::operator==(MyColor otherColor)
{
	if (_rgba == otherColor.rgba())
	{
		return true;
	}
	return false;
}

bool MyColor::operator!=(MyColor otherColor)
{
	if (_rgba == otherColor.rgba())
	{
		return !true;
	}
	return !false;
}

void MyColor::operator=(MyColor otherColor)
{
	_r = otherColor.r();
	_g = otherColor.g();
	_b = otherColor.b();
	_a = otherColor.a();
	_rgb = otherColor.rgb();
	_rgba = otherColor.rgba();
}

void MyColor::operator=(Color otherColor)
{
	_r = otherColor.r;
	_g = otherColor.g;
	_b = otherColor.b;
	_a = otherColor.a;
	_rgb = _r * 0x10000 + _g * 0x100 + _b;
	_rgba = _rgb * 0x100 + _a;
}