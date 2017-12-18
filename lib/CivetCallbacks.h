#pragma once

#include "CivetApi.h"

/**
* CivetCallbacks
*
* wrapper for mg_callbacks
*/
struct CIVETWEB_API CivetCallbacks : public mg_callbacks
{
	CivetCallbacks();
};