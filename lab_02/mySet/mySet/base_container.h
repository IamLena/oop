#pragma once

class base_container {
protected:
	size_t m_length;
public:
	base_container() : m_length(0) {}
	base_container(size_t len) : m_length(len) {}
	virtual ~base_container() {}
	size_t size() const{
		return m_length;
	}
	void setLength(size_t len) {
		m_length = 0;
	}
	bool is_empty() const {
		return m_length == 0;
	}
};