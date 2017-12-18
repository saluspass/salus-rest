#pragma once

class AccountHandler;
class CivetServer;

namespace Salus
{
	public ref class RestServer
	{
	public:
		RestServer();

		void Start(System::String^ sslCerts);
		void Stop();

	internal:
		AccountHandler* m_hAccount;
		CivetServer* m_pServer;
	};
}