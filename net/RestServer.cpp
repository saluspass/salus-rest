#include "RestServer.h"
#include "CivetServer.h"
#include "handlers/AccountHandler.h"

#define DOCUMENT_ROOT "."

namespace Salus
{
	RestServer::RestServer()
		: m_hAccount(nullptr)
		, m_pServer(nullptr)
	{

	}

	void RestServer::Start(System::String^ sslCerts)
	{
		/*System::IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sslCerts);
		std::string sSslCerts = static_cast<char*>(ptrToNativeString.ToPointer());
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);

		std::vector<std::string> cpp_options = { "document_root", DOCUMENT_ROOT, "listening_ports", "8081r,8443s", "ssl_certificate", sSslCerts };

		m_pServer = new CivetServer(cpp_options);*/
	}

	void RestServer::Stop()
	{

	}
}