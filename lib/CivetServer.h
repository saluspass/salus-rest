#pragma once

#include "civetweb.h"
#include <map>
#include <string>
#include <vector>
#include <stdexcept>

class CivetServer;

class CIVETWEB_API CivetException : public std::runtime_error
{
public:
	CivetException(const std::string& msg) 
		: std::runtime_error(msg)
	{
	}
};

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

class CIVETWEB_API CivetAuthHandler
{
public:
	virtual ~CivetAuthHandler()
	{
	}

	virtual bool authorize(CivetServer* server, struct mg_connection* conn) = 0;
};

/**
 * Basic interface for a websocket handler.  Handlers implementations
 * must be reentrant.
 */
class CIVETWEB_API CivetWebSocketHandler
{
public:
	virtual ~CivetWebSocketHandler()
	{
	}

	virtual bool handleConnection(CivetServer* server, const struct mg_connection* conn);
	virtual void handleReadyState(CivetServer* server, struct mg_connection* conn);
	virtual bool handleData(CivetServer* server, struct mg_connection* conn, int bits, char* data, size_t data_len);
	virtual void handleClose(CivetServer* server, const struct mg_connection* conn);
};

/**
 * CivetCallbacks
 *
 * wrapper for mg_callbacks
 */
struct CIVETWEB_API CivetCallbacks : public mg_callbacks 
{
	CivetCallbacks();
};

/**
 * CivetServer
 *
 * Basic class for embedded web server.  This has an URL mapping built-in.
 */
class CIVETWEB_API CivetServer
{
public:
	CivetServer(const char** options, const struct CivetCallbacks* callbacks = nullptr, const void* UserContext = nullptr);
	CivetServer(std::vector<std::string> options, const struct CivetCallbacks* callbacks = nullptr, const void* UserContext = nullptr);

	virtual ~CivetServer();

	void close();

	const struct mg_context* getContext() const
	{
		return context;
	}

	void addHandler(const std::string& uri, CivetHandler* handler);

	void addHandler(const std::string& uri, CivetHandler& handler)
	{
		addHandler(uri, &handler);
	}

	void addWebSocketHandler(const std::string& uri, CivetWebSocketHandler* handler);

	void addWebSocketHandler(const std::string& uri, CivetWebSocketHandler& handler)
	{
		addWebSocketHandler(uri, &handler);
	}

	void removeHandler(const std::string& uri);
	void removeWebSocketHandler(const std::string& uri);
	void addAuthHandler(const std::string& uri, CivetAuthHandler* handler);
	void addAuthHandler(const std::string& uri, CivetAuthHandler& handler)
	{
		addAuthHandler(uri, &handler);
	}

	void removeAuthHandler(const std::string& uri);
	std::vector<int> getListeningPorts();

	static int getCookie(struct mg_connection* conn, const std::string& cookieName, std::string& cookieValue);
	static const char* getHeader(struct mg_connection* conn, const std::string& headerName);
	
	static bool getParam(struct mg_connection* conn, const char* name, std::string& dst, size_t occurrence = 0);
	static bool getParam(const std::string& data, const char* name, std::string& dst, size_t occurrence = 0)
	{
		return getParam(data.c_str(), data.length(), name, dst, occurrence);
	}

	static bool getParam(const char* data, size_t data_len, const char* name, std::string& dst, size_t occurrence = 0);

	static void urlDecode(const char* src, size_t src_len, std::string& dst, bool is_form_url_encoded = true);
	static void urlDecode(const char* src, std::string& dst, bool is_form_url_encoded = true);
	static void urlDecode(const std::string& src, std::string& dst, bool is_form_url_encoded = true)
	{
		urlDecode(src.c_str(), src.length(), dst, is_form_url_encoded);
	}
	
	static void urlEncode(const char* src, std::string& dst, bool append = false);
	static void urlEncode(const char* src, size_t src_len, std::string& dst, bool append = false);
	static void urlEncode(const std::string& src, std::string& dst, bool append = false)
	{
		urlEncode(src.c_str(), src.length(), dst, append);
	}
	
	const void*  getUserContext() const
	{
		return UserContext;
	}

protected:
	class CivetConnection
	{
	public:
		char* postData;
		unsigned long postDataLen;

		CivetConnection();
		~CivetConnection();
	};

	struct mg_context* context;
	std::map<struct mg_connection*, class CivetConnection> connections;

	const void* UserContext;

private:
	static int requestHandler(struct mg_connection* conn, void* cbdata);

	static int	webSocketConnectionHandler(const struct mg_connection* conn,void* cbdata);
	static void webSocketReadyHandler(struct mg_connection* conn, void* cbdata);
	static int	webSocketDataHandler(struct mg_connection* conn, int bits, char* data, size_t data_len, void* cbdata);
	static void webSocketCloseHandler(const struct mg_connection* conn, void* cbdata);
	
	static int authHandler(struct mg_connection* conn, void* cbdata);
	static void closeHandler(const struct mg_connection* conn);

	void (*userCloseHandler)(const struct mg_connection* conn);
};
