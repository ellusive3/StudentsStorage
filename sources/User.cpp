#include <stdafx.h>
#include <User.h>

	User::User()
	{
		firstName = "default";
		lastName = "default";
		thirdName = "default";
		avgDisciplineScore = 0.0;
		groupId = 0;
	}

	User::User(std::string _firstName, std::string _lastName, std::string _thirdName, int _groupId)
	{
		firstName = _firstName;
		lastName = _lastName;
		thirdName = _thirdName;
		groupId = _groupId;
		avgDisciplineScore = 0.0;
	}

	std::string User::GetFirstName() const
	{
		return firstName;
	}

	std::string User::GetLastName() const
	{
		return lastName;
	}

	std::string User::GetThirdName() const
	{
		return thirdName;
	}
	double User::GetAvgDisciplineScore() const
	{
		return avgDisciplineScore;
	}

	int User::GetGroupId()
	{
		return groupId;
	}
