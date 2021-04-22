#pragma once

class City {
	public:
		City();
		City(int _cityId, std::string _name, int _stateId, std::string _facts, double _latitude, double _longtitude);
		
		int GetCityId() const;
		std::string GetName() const;
		int GetStateId() const;
		double GetRating() const;
		std::string GetFacts() const;

		void AddFact(const std::string & _fact);
		void SetRating(const double _rating);
	private:
		int cityId;
		std::string name;
		int stateId;
		double rating;
		std::string facts;
		double latitude;
		double latitude;	
	protected:
		
}