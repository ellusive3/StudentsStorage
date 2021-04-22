#pragma once

/**
*	@file
*		���� ��� �������� ������ ������
*	@detail
*		����, � ������� ������� ���������� � ������� ����������� ���
*		������������� ������ � �������
*	@author
*		TP-1
*/

class City {
	public:
		/**
		*	����������� �� ���������
		*/
		City();

		/**
		*		����������� � �����������
		*
		*	@param[in] _cityId - ������������� ������
		*	@param[in] _name - �������� ������
		*	@param[in] _facts - ���������� ����� � ������
		*	@param[in] _latitute - ���������� ������
		*	@param[in] _longtitude - ���������� ������� 
		*/
		City(int _cityId, std::string _name, std::string _facts, double _latitude, double _longtitude);

		/**
		*		�������� ������������� ������
		*
		*	@return ������������� ������
		*/
		int GetCityId() const;

		/**
		*		�������� ��� ������
		*
		*	@return ��� ������
		*/
		std::string GetName() const;

		/**
		*		�������� ������� ������
		*
		*	@return ������� ������
		*/
		double GetRating() const;

		/**
		*		�������� ���������� ����� � ������
		*	@detail
		*		���������� ���������� ����� � ������ � ���� ����� ������ �����������
		*		����������� "FACT_SPLITTER"
		*
		*	@return ���������� ����� � ������
		*/
		std::string GetFacts() const;

		/**
		*		�������� ���������� ���� � ������
		*
		*	@param[in] _fact - ���������� ���� � ������
		*/
		void AddFact(const std::string & _fact);

		/**
		*		���������� ������ �������
		*
		*	@param[in] _rating - ����� ������� ������
		*/
		void SetRating(const double _rating);
	private:
		/// ������������� ������
		int cityId;
		
		/// �������� ������
		std::string name;

		/// ������� ������
		double rating;
		
		/// ���������� ����� � ������
		std::string facts;

		/// ���������� ������
		double latitude;

		/// ���������� �������
		double latitude;	
	protected:
		
}