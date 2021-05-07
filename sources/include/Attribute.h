#pragma once
#include <stdafx.h>

template<class T>
class Attribute {
	public:
		Attribute() {
			m_key = "default";
			m_value = T;
		}

		Attribute(const std::string& _key, const T& _value)
		{
			m_key = _key;
			m_value = _value;
		}

		std::string& GetKey() const { return m_key; }
		T& GetValue() const { return m_value; }
	private:
		std::string m_key;
		T m_value;
	protected:
};