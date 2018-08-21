#pragma once

#ifndef testcppclient_h__INCLUDED
#define testcppclient_h__INCLUDED

#include "EWrapper.h"
#include "EReaderOSSignal.h"
#include "EReader.h"

#include <memory>
#include <vector>

class EClientSocket;

enum State {
	ST_CONNECT,
	ST_TEST,
	ST_PING,
	ST_PING_ACK,
	ST_HISTORICALDATAREQUEST,
	ST_HISTORICALDATAREQUESTS_ACK,
};
//! [ewrapperimpl]
class TestCppClient : public EWrapper
{
//! [ewrapperimpl]
public:
	TestCppClient();
	~TestCppClient();

	void setConnectOptions(const std::string&);
	void processMessages();

public:

	bool connect(const char* host, unsigned int port, int clientId = 0);
	void disconnect() const;
	bool isConnected() const;

private:
	//Functions go here
	void reqCurrentTime();
	void historicalDataRequests(const Contract& data);

public:
	//events
	#include "EWrapper_prototypes.h"

private:
	void printContractMsg(const Contract& contract);
	void printContractDetailsMsg(const ContractDetails& contractDetails);
	void printContractDetailsSecIdList(const TagValueListSPtr &secIdList);
	void printBondContractDetailsMsg(const ContractDetails& contractDetails);

private:
	//! [socket_declare]
	EReaderOSSignal m_osSignal;
	EClientSocket *const m_pClient;
	//! [socket_declare]
	State m_state;
	time_t m_sleepDeadline;

	OrderId m_orderId;
	EReader *m_pReader;
	bool m_extraAuth;
	std::string m_bboExchange;
};
#endif