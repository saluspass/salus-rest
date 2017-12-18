#pragma once

#include <stdexcept>

class CIVETWEB_API CivetException : public std::runtime_error
{
public:
	CivetException(const std::string& msg)
		: std::runtime_error(msg)
	{
	}
};
