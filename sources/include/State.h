#pragma  once

// Forward declarations
class City;

class State {
	public:
		State();
		State(int _stateId, _stateName, std::vector<City> _cities);
		int GetStateId() const;
		std::string GetStateName() const;
		std::vector<City> GetCities() const;	
	private:
		int stateId;
		std::string stateName;
		std::vector<City> cities;
	protected:
}