#include <stdafx.h>
#include <Row.h>

Row::Row()
{
	m_attrs = std::vector<Attribute>();
}

Row::Row(const std::vector<Attribute> & _attrs)
{
	m_attrs = _attrs;
}

void Row::AddAttr(Attribute & _attr)
{
	if (FindAttrByKey(_attr.GetKey()) == nullptr) {
		m_attrs.push_back(_attr);
	}
}

std::vector<Attribute> Row::GetAttrs() const
{
	return m_attrs;
}

Attribute * Row::FindAttrByKey(const std::string _key) const
{
	for (int i = 0; i < m_attrs.size();  i++) {
		if (m_attrs.at(i).GetKey() == _key)
			return &(const_cast<Attribute&>(m_attrs.at(i)));
	}
	return nullptr;
}

template<class T>
std::vector<Attribute> & Row::FindAttrsByValue(const T & _value) const
{
	std::vector<Attribute> result = std::vector<Attribute>();
	for (auto attr : m_attrs) {
		if (attr.GetValue() == _value)
			result.push_back(attr);		
	}
	return result;
}