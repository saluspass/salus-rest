#pragma once

#include "rapidjson/prettywriter.h" // for stringify JSON

class ISerializableObject
{
public:
	virtual void Serialize(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) const = 0;
};