#pragma once

class User {
	public:
		User();
		User(std::string _firstName, std::string _lastName, std::string _thirdName, int _groupId, double _avgDisciplineScore);
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetThirdName() const;
		double GetAvgDisciplineScore() const;
		int GetGroupId() const;
	private:
		std::string firstName;
		std::string lastName;
		std::string thirdName;
		double avgDisciplineScore;
		int groupId;
		//TODO User's marks
	protected:
};