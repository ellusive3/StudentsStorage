#include <stdafx.h>
#include <State.h>
#include <City.h>

	State::State()
	{
		stateId = 0;
		stateName = "default";
		cities = std::vector<City>();	
	}
	
	State::State(int _stateId, _stateName, std::vector<City> _cities)
	{
		stateId = _stateId;
		stateName = _stateName;
		cities = _cities;
	}

	int State::GetStateId() const
	{
		return stateId;
	}

	std::string State::GetStateName() const
	{
		return stateName;
	}

	std::vector<City> State::GetCities() const
	{
		return cities;
	}
