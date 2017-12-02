#include <memory>

class NetworkManager
{
public:
	NetworkManager();
	~NetworkManager();

	void Connetct();
	void Disconnect();

private:
	class NetManImpl;
	std::unique_ptr<NetManImpl> m_pImpl;
};