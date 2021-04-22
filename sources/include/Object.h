#pragma once

// Forward declarations
class Theme;

class Object {
	public:
		Object();
		Object(int _objectId, std::string _objectName, std::vector<Theme> & _themes);

		int GetObjectId() const;
		std::string GetObjectName() const;
		std::vector<Theme> GetThemes() const;
	private:
		int objectId;
		std::string objectName;
		std::vector<Theme> themes;
	protected:
}