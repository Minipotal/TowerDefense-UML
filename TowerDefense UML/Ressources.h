#pragma once
class Ressources
{
public:
	Ressources(int gold, int wood, int iron);
	Ressources();

	int _gold;
	int _wood;
	int _iron;

	void setGold(int gold);
	void setWood(int wood);
	void setIron(int iron);
};

