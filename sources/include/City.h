#pragma once

class City {
	public:
		City();
		City(int _cityId, std::string _name, std::string _facts, double _latitude, double _longtitude);
		
		int GetCityId() const;
		std::string GetName() const;
		double GetRating() const;
		std::string GetFacts() const;

		void AddFact(const std::string & _fact);
		void SetRating(const double _rating);
	private:
		int cityId;
		std::string name;
		double rating;
		std::string facts;
		double latitude;
		double latitude;	
	protected:
		
}