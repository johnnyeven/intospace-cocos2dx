#include "BasicObject.h"
#include "PZGuidMaker.h"

BasicObject::BasicObject(void)
{
	guid = PZGuidMaker::CreateGuidString().c_str();
}


BasicObject::~BasicObject(void)
{
}

const char* BasicObject::getGuid()
{
	return guid;
}
