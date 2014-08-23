#include "Box.h"


Box::Box(int a, int b, int d, int c)
	: hm(a), hM(b), vm(d), vM(c)
{
}


Box::~Box(void)
{
}

bool Box::collide(Box& b)
{
	return ((hm > b.hm && hm < b.hM)
		||(hM > b.hm && hM < b.hM)
		||(b.hm > hm && b.hm < hM)
		||(b.hM > hm && b.hM < hM))
		&& ((vm > b.vm && vm < b.vM)
		||(vM > b.vm && vM < b.vM)
		||(b.vm > vm && b.vm < vM)
		||(b.vM > vm && b.vM < vM));
}
