#ifndef BLOCKCHAININONEFILE_BLOCK_H
#define BLOCKCHAININONEFILE_BLOCK_H


#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

class Block {
public:
	string prevHash;
	Block(uint32_t blockIndex, string blockData);
	void MineBlock(uint32_t Difficulty);
	string CalculateHash();

	uint32_t getIndex();
	uint64_t getNonce();
	string getData();
	string getHash();
	time_t getTime();


private:
	uint32_t _Index;
	uint64_t _Nonce;
	string _Data;
	string _Hash;
	time_t _Time;



};



#endif