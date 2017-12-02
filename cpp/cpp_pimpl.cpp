#include "cpp_pimpl.h"
#include <iostream>

class NetManImpl
{
public:
	~NetManImpl()
	{
		if (m_connectionOpened)
			Disconnect();
	}

	void Connect()
	{
		m_connectionOpened = true;
		std::cout << "NetManImpl::Connect\n";
	}
	
	void Disconnect()
	{
		m_connectionOpened = false;
		std::cout << "NetManImpl::Disconnect\n";
	}
	
private:
	bool m_connectionOpened { false };
};

NetworkManager::NetworkManager() : m_pImpl(new NetManImpl()) 
{
	
}

NetworkManager::~NetworkManager() = default;

void NetworkManager::Connect()
{
	m_pImpl->Connect();
}

void NetworkManager::Disconnect()
{
	m_pImpl->Disconnect();
}