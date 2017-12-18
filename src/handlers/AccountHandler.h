#pragma once

#include "CivetServer.h"

class AccountHandler : public CivetHandler
{
public:
	bool handleGet(CivetServer* server, struct mg_connection* conn) override;
};
