
#include "base.h"
class Clip :
	public Base
{
public:
	Clip(void);
	~Clip(void);

	virtual void init();
	virtual display_func warper_display();
	virtual reshape_func warper_reshape();

private:
	static void display();
	static void reshape(int w,int h);

};
