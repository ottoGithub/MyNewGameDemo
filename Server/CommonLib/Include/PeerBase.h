#ifndef _PEER_BASE_H_
#define _PEER_BASE_H_

#include <iostream>
#include "Types.h"
#include "PacketList.h"

class PacketProcessEx;
class NetManagerBase;
class PacketText;
class PacketBase;

class PeerBase
{
public:
	PeerBase();
	~PeerBase();

	virtual bool Init(const char* szIp, int port);
	virtual bool PeerAccept();
	virtual int PeerConnect();

	void OnPeerConnect(int32 socketid);
	void OnPeerAccept(int32 socketid);
	void OnPeerDisconnect(int32 socketid);
	
	virtual void PeerConnect(int32 socketid){}
	virtual void PeerAccept(int32 socketid){}
	virtual void PeerDisconnect(int32 socketid){}

	virtual void RegPktHandler();
	virtual void DefaultPeerPktHandler(PacketBase* pkt){};

	//������
	void PktTestHandler(PacketText* pkt);

	void PeerRun();
	void DoPeerRun();

	bool PeerSend(int32 socketid, PacketBase* pkt);
	void DoPeerSend();
	bool PeerProcPacket();
protected:
	std::string m_PeerIP;
	int32 m_PeerPort;
	PacketProcessEx* m_PeerPocPacket; //�հ�����
	NetManagerBase* m_NetManger;

	PacketListEx m_PktSendList; //��������
	PacketListEx m_PktFailedList; //��������

	int32 m_LastFrameTime;
};

#endif