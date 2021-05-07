#include <stdafx.h>
#include <Link.h>

	Link::Link()
	{
		linkId = 0;
		value = "default";
	}

	Link::Link(int _linkId, std::string _value)
	{
		linkId = _linkId;
		value = _value;
	}

	int Link::GetLinkId() const
	{
		return linkId;
	}

	std::string Link::GetLinkValue() const
	{
		return value;
	}
