#pragma once
class IIdentifier
{
public:
	IIdentifier(void);
	virtual ~IIdentifier(void);
	virtual void update(double delta);
};

