#pragma once

#include "CivetHandler.h"

class AccountHandler : public CivetHandler
{
public:
	bool handleGet(CivetServer* server, struct mg_connection* conn) override;
};
