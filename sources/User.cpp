#include <stdafx.h>
#include <User.h>

	User::User()
	{
		firstName = "default";
		lastName = "default";
		thirdName = "default";
		avgDisciplineScore = 0.0;
		userId = -1;
		groupId = 0;
	}

	User::User(int _userId, std::string _firstName, std::string _lastName, std::string _thirdName, int _groupId, double _avgDisciplineScore)
	{
		firstName = _firstName;
		lastName = _lastName;
		thirdName = _thirdName;
		groupId = _groupId;
		userId = _userId;
		avgDisciplineScore = _avgDisciplineScore;
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

	int User::GetGroupId() const
	{
		return groupId;
	}

	int User::GetUserId() const
	{
		return userId;
	}
