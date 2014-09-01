#include "Identifier\DefaultIdentifier.h"

DefaultIdentifier::DefaultIdentifier(void)
{
}

DefaultIdentifier::~DefaultIdentifier(void)
{
}

void DefaultIdentifier::update(double delta)
{

}

void DefaultIdentifier::setTarget(BasicObject* obj)
{
	_target = obj;
}

BasicObject* DefaultIdentifier::getTarget()
{
	return _target;
}

void DefaultIdentifier::setType(IdentifierType type)
{
	_type = type;
}

IdentifierType DefaultIdentifier::getType()
{
	return _type;
}