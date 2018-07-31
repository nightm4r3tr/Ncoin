// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
	uint8_t addr[16];
	uint16_t port;
};

#include "chainparamsseeds.h"
//
// Main network
//

// Convert the pnSeeds array into usable address objects.
static void convertSeeds(std::vector<CAddress> &vSeedsOut, const unsigned int *data, unsigned int count, int port)
{
	// It'll only connect to one or two seed nodes because once it connects,
	// it'll get a pile of addresses with newer timestamps.
	// Seed nodes are given a random 'last seen time' of between one and two
	// weeks ago.
	const int64_t nOneWeek = 7 * 24 * 60 * 60;
	for (unsigned int k = 0; k < count; ++k)
	{
		struct in_addr ip;
		unsigned int i = data[k], t;

		// -- convert to big endian
		t = (i & 0x000000ff) << 24u
			| (i & 0x0000ff00) << 8u
			| (i & 0x00ff0000) >> 8u
			| (i & 0xff000000) >> 24u;

		memcpy(&ip, &t, sizeof(ip));

		CAddress addr(CService(ip, port));
		addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
		vSeedsOut.push_back(addr);
	}
}

class CMainParams : public CChainParams {
public:
	CMainParams() {
		// The message start string is designed to be unlikely to occur in normal data.
		// The characters are rarely used upper ASCII, not valid as UTF-8, and produce
		// a large 4-byte int at any alignment.
		pchMessageStart[0] = 0xc6;
		pchMessageStart[1] = 0xf5;
		pchMessageStart[2] = 0xa1;
		pchMessageStart[3] = 0xe6;
		vAlertPubKey = ParseHex("123490ee10b08f29bd3a19107993e456f128f115fa71d7fff13cc0dfa76a2a76860a060371f9abd139cef35c6c98fa97e52adb7dd6d0b5d3ecc70cceb8e14fc5b6");
		nDefaultPort = 22954;
		nRPCPort = 22953;
		bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

		const char* pszTimestamp = "Ncoincoin is officially lunching on 31/07/2018!";
		std::vector<CTxIn> vin;
		vin.resize(1);
		vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
		std::vector<CTxOut> vout;
		vout.resize(1);
		vout[0].SetEmpty();
		CTransaction txNew(1, 1524149953, vin, vout, 0);
		genesis.vtx.push_back(txNew);
		genesis.hashPrevBlock = 0;
		genesis.hashMerkleRoot = genesis.BuildMerkleTree();
		printf("genesis.BuildMerkleTree = %s\n", genesis.BuildMerkleTree().ToString().c_str());
		genesis.nVersion = 1;
		genesis.nTime = 1533044334;
		genesis.nBits = 520159231;
		genesis.nNonce = 0;

		hashGenesisBlock = genesis.GetHash();

		assert(genesis.hashMerkleRoot == uint256("0x"));
		printf("genesis.GetHash = %s\n", genesis.GetHash().ToString().c_str());
		assert(hashGenesisBlock == uint256("0x"));
		//debug
		//printf("genesis.nTime = %s\n", genesis.nTime().ToString().c_str());
		//printf("genesis.nNonce = %s\n", genesis.nNonce().ToString().c_str());
        
		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 25);
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 75);
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 130);
		base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1, 60);
		base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
		base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

		vSeeds.push_back(CDNSSeedData("0", "207.154.235.30"));
	
		convertSeeds(vFixedSeeds, pnSeed, ARRAYLEN(pnSeed), nDefaultPort);

		nPoolMaxTransactions = 3;
		//strSporkKey = "046f78dcf911fbd61910136f7f0f8d90578f68d0b3ac973b5040fb7afb501b5939f39b108b0569dca71488f5bbf498d92e4d1194f6f941307ffd95f75e76869f0e";
		//strMasternodePaymentsPubKey = "046f78dcf911fbd61910136f7f0f8d90578f68d0b3ac973b5040fb7afb501b5939f39b108b0569dca71488f5bbf498d92e4d1194f6f941307ffd95f75e76869f0e";
		strDarksendPoolDummyAddress = "BXuRnHZizkREBg7yBzcpy4TBLn2B1GbUva";
		nLastPOWBlock = 2000;
		nPOSStartBlock = 10;
	}


	virtual const CBlock& GenesisBlock() const { return genesis; }
	virtual Network NetworkID() const { return CChainParams::MAIN; }

	virtual const vector<CAddress>& FixedSeeds() const {
		return vFixedSeeds;
	}
protected:
	CBlock genesis;
	vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
	CTestNetParams() {
		// The message start string is designed to be unlikely to occur in normal data.
		// The characters are rarely used upper ASCII, not valid as UTF-8, and produce
		// a large 4-byte int at any alignment.
		pchMessageStart[0] = 0x13;
		pchMessageStart[1] = 0x75;
		pchMessageStart[2] = 0x7a;
		pchMessageStart[3] = 0x47;
		bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
		vAlertPubKey = ParseHex("3efd90ee10b08f29bd3a19107993e456f128f115fa71d7fff13cc0dfa76a2a76860a060371f9abd139cef35c6c98fa97e52adb7dd6d0b5d3ecc70cceb8e14fc5b6");
		nDefaultPort = 20114;
		nRPCPort = 20115;
		strDataDir = "testnet";

		genesis.nTime = 1533044334;
		genesis.nBits = 520159231;
		genesis.nNonce = 0;
		
		hashGenesisBlock = genesis.GetHash();

		assert(genesis.hashMerkleRoot == uint256("0x"));
		printf("genesis.GetHash = %s\n", genesis.GetHash().ToString().c_str());
		assert(hashGenesisBlock == uint256("0x"));

		vFixedSeeds.clear();
		vSeeds.clear();

		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 85);
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);
		base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1, 40);
		base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
		base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

		convertSeeds(vFixedSeeds, pnTestnetSeed, ARRAYLEN(pnTestnetSeed), nDefaultPort);

		nLastPOWBlock = 0x7fffffff;
	}
	virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
	return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
	switch (network) {
	case CChainParams::MAIN:
		pCurrentParams = &mainParams;
		break;
	case CChainParams::TESTNET:
		pCurrentParams = &testNetParams;
		break;
	default:
		assert(false && "Unimplemented network");
		return;
	}
}

bool SelectParamsFromCommandLine() {

	bool fTestNet = GetBoolArg("-testnet", false);

	if (fTestNet) {
		SelectParams(CChainParams::TESTNET);
	}
	else {
		SelectParams(CChainParams::MAIN);
	}
	return true;
}
