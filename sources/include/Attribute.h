#pragma once
#include <stdafx.h>

class Attribute {
	public:
		Attribute() {
			m_key = "default";
			m_value = boost::variant<std::string>("default");
		}

		Attribute(const std::string& _key, const AttrValue & _value)
		{
			m_key = _key;
			m_value = _value;
		}

		std::string GetKey() const { return m_key; }
		AttrValue GetValue() const { return m_value; }
	private:
		std::string m_key;
		AttrValue m_value;
	protected:
};