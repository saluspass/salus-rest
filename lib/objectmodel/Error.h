#pragma once

#include "SerializableObject.h"

#include <string>

enum class ErrorCode : unsigned int
{
	ErrorCode_None,
	ErrorCode_NoParam,			//No parameter was passed
	ErrorCode_UnknownAccount,	//Could not find specified account
};

class Error : ISerializableObject
{
public:
	virtual void Serialize(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) const override;

	const std::string GetErrorString() const;

	void SetError(ErrorCode error) { m_ErrorCode = error; }

	static std::string GetJsonString(ErrorCode error);
private:
	ErrorCode m_ErrorCode;
};
