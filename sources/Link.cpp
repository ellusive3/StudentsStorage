#include <stdafx.h>
#include <Link.h>

	Link::Link()
	{
		linkId = 0;
		value = "default";
	}

	Link::Link(int _linkId, _value, std::vector<Link> & _links)
	{
		linkId = _linkId;
		value = _value;
		links = _links;
	}

	int Link::GetLinkId() const
	{
		return linkId;
	}

	std::string Link::GetLinkValue() const
	{
		return value;
	}
