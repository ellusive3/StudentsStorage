#pragma once

class User {
	public:
		User();
		User(int _userId, std::string _firstName, std::string _lastName, std::string _thirdName, int _groupId, double _avgDisciplineScore);
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetThirdName() const;
		double GetAvgDisciplineScore() const;
		int GetGroupId() const;
		int GetUserId() const;
	private:
		std::string firstName;
		std::string lastName;
		std::string thirdName;
		int userId;
		double avgDisciplineScore;
		int groupId;
		//TODO User's marks
	protected:
};