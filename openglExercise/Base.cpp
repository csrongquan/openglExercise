#include "stdafx.h"
#include "Base.h"

Base::Base():width(500),height(500),x(100),y(100)
{
}

Base::~Base()
{

}


display_func Base::warper_display()
{
	return Base::display;
}

reshape_func Base::warper_reshape()
{
	return Base::reshape;
}

mouse_func Base::warper_mouse()
{
	return Base::mouse;
}

void Base::init()
{
	
}

void Base::display()
{

}

void Base::reshape(int w,int h)
{

}

void Base::mouse(int button,int state,int x,int y)
{

}
