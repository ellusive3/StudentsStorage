#include <stdafx.h>
#include <Theme.h>
#include <Link.h>

	Theme::Theme()
	{
		themeId = 0;
		description = "none";
		links = std::vector<Link>();
	}

	Theme::Theme(int _themeId, std::string _description)
	{
		themeId = _themeId;
		description = _description;
	}
	int Theme::GetThemeId() const
	{
		return themeId;
	}

	std::string Theme::GetThemeDescription() const
	{
		return description;
	}

	std::vector<Link> Theme::GetLinks() const
	{
		return links;
	}
