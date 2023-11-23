#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class MyColor
{
private:
	int _r;
	int _g;
	int _b;
	int _a;
	int _rgb;
	int _rgba;
	int _h;
	int _s;
	int _v;
	int _hsv;

public:
	MyColor();
	MyColor(int rgb);
	MyColor(int rgb, int a);
	MyColor(int r, int g, int b);
	MyColor(int r, int g, int b, int a);

	int r();
	int g();
	int b();
	int a();
	int rgb();
	int rgba();
	int h();
	int s();
	int v();
	int hsv();

	Color getSfColor();

	void printColorHex(bool includeAlpha = false);
	void printColor(bool includeAlpha = false);

	MyColor mixin(MyColor otherCol, float pct = 0.5f);
	void mixin(MyColor otherCol, MyColor* savedColor, float pct = 0.5f);
	MyColor tripleMixin(MyColor otherCol, MyColor lastColor, float pct = 0.5f);
	void tripleMixin(MyColor otherCol, MyColor lastColor, MyColor* savedColor, float pct = 0.5f);

	MyColor HSVmixin(MyColor otherCol, float pct = 0.5f);
	void HSVmixin(MyColor otherCol, MyColor* savedColor, float pct = 0.5f);
	MyColor HSVtripleMixin(MyColor otherCol, MyColor lastColor, float pct = 0.5f);
	void HSVtripleMixin(MyColor otherCol, MyColor lastColor, MyColor* savedColor, float pct = 0.5f);

	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setA(int a);
	void setRGB(int rgb);
	void setRGB(int r, int g, int b);
	void setRGBA(int rgba);
	void setRGBA(int rgb, int a);
	void setRGBA(int r, int g, int b, int a);
	void setH(int h);
	void setS(int s);
	void setV(int v);
	void setHSV(int hsv);
	void setHSV(int h, int s, int v);
	void setHSVA(int hsv, int a);
	void setHSVA(int h, int s, int v, int a);

	void HSVtoRGB();
	void RGBtoHSV();

	bool operator==(MyColor otherColor);
	bool operator!=(MyColor otherColor);
	void operator=(MyColor otherColor);
	void operator=(Color otherColor);
};