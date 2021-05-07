#pragma  once
#include <vector>
#include <City.h>

class State {
	public:
		State();
		State(int _stateId, std::string _stateName, std::vector<City> _cities);
		int GetStateId() const;
		std::string GetStateName() const;
		std::vector<City> GetCities() const;
	private:
		int stateId;
		std::string stateName;
		std::vector<City> cities;
	protected:
};