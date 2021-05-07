#pragma once
#include <vector>
#include <Link.h>

class Theme {
	public:
		Theme();
		Theme(int _themeId, std::string _description);

		int GetThemeId() const;
		std::string GetThemeDescription() const;
		std::vector<Link> GetLinks() const;
	private:
		int themeId;
		std::string description;
		std::vector<Link> links;
	protected:
};