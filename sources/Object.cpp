#include <stdafx.h>
#include <Object.cpp>
#include <Theme.h>

	Object::Object()
	{
		objectId = 0;
		objectName = "default";
		themes = std::vector<Theme>();
	}

	Object::Object(int _objectId, std::string _objectName, std::vector<Theme> & _themes)
	{
		objectId = _objectId;
		objectName = _objectName;
		themes = _themes;
	}

	int Object::GetObjectId() const
	{
		return objectId;
	}

	std::string Object::GetObjectName() const
	{
		return objectName;
	}

	std::vector<Theme> Object::GetThemes() const
	{
		return themes;
	}
