#pragma once

#include "civetweb.h"

class CivetServer;

class CIVETWEB_API CivetHandler
{
public:
	virtual ~CivetHandler()
	{
	}

	virtual bool handleGet(CivetServer* server, struct mg_connection* conn);
	virtual bool handlePost(CivetServer* server, struct mg_connection* conn);
	virtual bool handleHead(CivetServer* server, struct mg_connection* conn);
	virtual bool handlePut(CivetServer* server, struct mg_connection* conn);
	virtual bool handleDelete(CivetServer* server, struct mg_connection* conn);
	virtual bool handleOptions(CivetServer* server, struct mg_connection* conn);
	virtual bool handlePatch(CivetServer* server, struct mg_connection* conn);
};
