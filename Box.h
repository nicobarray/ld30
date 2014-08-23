#pragma once
class Box
{
public:
	Box(int hmin, int hmax, int vmin, int vmax);
	~Box(void);

	bool collide(Box& b);

private:
	int hm, hM, vm, vM;
};

