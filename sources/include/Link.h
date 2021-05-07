#pragma once

class Link {
	public:
		Link();
		Link(int _linkId, std::string _value);

		int GetLinkId() const;
		std::string GetLinkValue() const;
	private:
		int linkId;
		std::string value;
	protected:
};