#include <stdafx.h>
#include <City.h>


	City::City()
	{
	 	cityId = 0;
		name = "default";
		facts = "";
		latitude = 0.0;
		longtitude = 0.0;
		rating = 0.0;
	}

	
	City::City(int _cityId, std::string _name, std::string _facts, double _latitude, double _longtitude) 
	{
	 	cityId = _cityId;
		name = _name;
		facts = _facts;
		latitude = _latitude;
		longtitude = _longtitude;
		rating = 0.0;
	}
	
		
	int City::GetCityId() const 
	{
		return cityId;
	}

	std::string City::GetName() const
	{
		return name;
 	}

	double City::GetRating() const 
	{
		return rating;
	}

	std::string City::GetFacts() const 
	{
		return facts;
	}

	void City::AddFact(const std::string & _fact)
	{
		if (facts.empty()) {
			facts += _fact;
		}
		else {
			facts += FACT_SPLITTER + _fact;
		}
	}

	void City::SetRating(const double _rating)
	{
		rating = _rating;
	}