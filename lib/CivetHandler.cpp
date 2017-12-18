#include "CivetHandler.h"

#ifndef UNUSED_PARAMETER
#define UNUSED_PARAMETER(x) (void)(x)
#endif

bool CivetHandler::handleGet(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}

bool CivetHandler::handlePost(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}

bool CivetHandler::handleHead(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}

bool CivetHandler::handlePut(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}

bool CivetHandler::handlePatch(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}

bool CivetHandler::handleDelete(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}

bool CivetHandler::handleOptions(CivetServer* server, struct mg_connection* conn)
{
	UNUSED_PARAMETER(server);
	UNUSED_PARAMETER(conn);
	return false;
}