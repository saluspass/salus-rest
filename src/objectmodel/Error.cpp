#include "Error.h"

void Error::Serialize(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) const
{
	writer.StartObject();
	writer.Key("error_code");
	writer.Int(static_cast<int>(m_ErrorCode));
	writer.Key("error");
	writer.String(GetErrorString().c_str());
	writer.EndObject();
}

const std::string Error::GetErrorString() const
{
	switch (m_ErrorCode)
	{
	case ErrorCode::ErrorCode_None:
		return "None";
	case ErrorCode::ErrorCode_NoParam:
		return "No parameter present";
	case ErrorCode::ErrorCode_UnknownAccount:
		return "Specified account could not be found";
	};

	return { };
}

std::string Error::GetJsonString(ErrorCode error)
{
	rapidjson::StringBuffer sb;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
	Error err;
	err.SetError(error);
	err.Serialize(writer);

	return sb.GetString();
}