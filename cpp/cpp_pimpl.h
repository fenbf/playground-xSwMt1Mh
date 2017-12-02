#include <memory>

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();

	void Connect();
	void Disconnect();

private:
	class NetManImpl;
	std::unique_ptr<NetManImpl> m_pImpl;
};