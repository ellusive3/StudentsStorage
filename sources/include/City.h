#pragma once

/**
*	@file
*		Файл для описания класса города
*	@detail
*		Файл, в котором описаны переменные и функции необходимые для
*		представления города в системе
*	@author
*		TP-1
*/

class City {
	public:
		/**
		*	Конструктор по умолчанию
		*/
		City();

		/**
		*		Конструктор с параметрами
		*
		*	@param[in] _cityId - идентификатор города
		*	@param[in] _name - название города
		*	@param[in] _facts - интересные факты о городе
		*	@param[in] _latitute - координаты широты
		*	@param[in] _longtitude - координаты долготы 
		*/
		City(int _cityId, std::string _name, std::string _facts, double _latitude, double _longtitude);

		/**
		*		Получить идентификатор города
		*
		*	@return идентификатор города
		*/
		int GetCityId() const;

		/**
		*		Получить имя города
		*
		*	@return имя города
		*/
		std::string GetName() const;

		/**
		*		Получить рейтинг города
		*
		*	@return рейтинг города
		*/
		double GetRating() const;

		/**
		*		Получить интересные факты о городе
		*	@detail
		*		Возвращает интересные факты о городе в виде одной строки разделенной
		*		комбинацией "FACT_SPLITTER"
		*
		*	@return интересные факты о городе
		*/
		std::string GetFacts() const;

		/**
		*		Добавить интересный факт о городе
		*
		*	@param[in] _fact - интересный факт о городе
		*/
		void AddFact(const std::string & _fact);

		/**
		*		Установить городу рейтинг
		*
		*	@param[in] _rating - новый рейтинг города
		*/
		void SetRating(const double _rating);
	private:
		/// Идентификатор города
		int cityId;
		
		/// Название города
		std::string name;

		/// Рейтинг города
		double rating;
		
		/// Интересные факты о городе
		std::string facts;

		/// Координаты широты
		double latitude;

		/// Координаты долготы
		double latitude;	
	protected:
		
}