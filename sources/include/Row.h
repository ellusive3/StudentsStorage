#pragma once
#include <vector>
#include <Attribute.h>

class Row {
	public:
		Row();
		Row(const std::vector<Attribute>& _attrs);
		void AddAttr(Attribute& _attr);
		std::vector<Attribute> GetAttrs() const;
		Attribute * FindAttrByKey(const std::string _key) const;
		std::vector<Attribute>& FindAttrsByValue(const AttrValue & _value) const;
	private:
		std::vector<Attribute> m_attrs;
	protected:
};