#pragma once

class User {
	public:
		User();
		User(std::string _firstName, _lastName, _thirdName, int _groupId);
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetThirdName() const;
		double GetAvgDisciplineScore() const;
		int GetGroupId();
	private:
		std::string firstName;
		std::string lastName;
		std::string thirdName;
		double avgDisciplineScore;
		int groupId;
		//TODO User's marks
	protected:
}