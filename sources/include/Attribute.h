#pragma once
#include <stdafx.h>

class Attribute {
	public:
		Attribute() {
			m_key = "default";
			m_value = "default";
		}

		Attribute(const std::string& _key, const std::string & _value)
		{
			m_key = _key;
			m_value = _value;
		}

		std::string GetKey() const { return m_key; }
		std::string GetValue() const { return m_value; }
	private:
		std::string m_key;
		std::string m_value;
	protected:
};