#pragma once

 // Forward Declarations
class Link;

class Theme {
	public:
		Theme();
		Theme(int _themeId, _description, std::vector<Link> & _links);
		
		int GetThemeId() const;
		std::string GetThemeDescription() const;
		std::vector<Link> GetLinks() const;
	private:
		int themeId;
		std::string description;
		std::vector<Link> links;
	protected:
}