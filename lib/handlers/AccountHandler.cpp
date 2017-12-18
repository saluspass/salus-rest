#include "AccountHandler.h"

#include "objectmodel/Error.h"

#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

bool AccountHandler::handleGet(CivetServer* server, struct mg_connection* conn)
{
	mg_printf(conn,
		"HTTP/1.1 200 OK\r\nContent-Type: "
		"text/json\r\nConnection: close\r\n\r\n");

	std::string s;
	if (CivetServer::getParam(conn, "param", s))
	{
		mg_printf(conn, Error::GetJsonString(ErrorCode::ErrorCode_UnknownAccount).c_str());
	}
	else
	{
		mg_printf(conn, Error::GetJsonString(ErrorCode::ErrorCode_NoParam).c_str());
	}

	return true;
}