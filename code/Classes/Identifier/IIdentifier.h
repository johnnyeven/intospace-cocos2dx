#ifndef _IDENTIFIER_H_
#define _IDENTIFIER_H_

#pragma once
class IIdentifier
{
public:
	IIdentifier(void) {};
	virtual ~IIdentifier(void) {};
	virtual void update(double delta) = 0;
};

#endif