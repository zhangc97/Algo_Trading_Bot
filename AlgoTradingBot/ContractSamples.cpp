#include "StdAfx.h"

#include "ContractSamples.h"

#include "Contract.h"


Contract ContractSamples::NVDASTK() {
	//! [NVIDIA stock contract]
	Contract contract;
	contract.symbol = "NVDA";
	contract.secType = "STK";
	contract.currency = "USD";
	contract.exchange = "SMART";
	//! [NVIDIA stock contract]
	return contract;
}
