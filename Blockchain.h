#ifndef BLOCKCHAININONEFILE_BLOCKCHAIN_H
#define BLOCKCHAININONWFILE_BLOCKCHAIN_H

#include <cstdint>
#include <vector>

#include "Block.h"

using namespace std;

class Blockchain {
public:
	Blockchain();
	void addBlock(Block newBlock);
	void calcDifficulty(time_t time, time_t parentTime, uint32_t parentNumber);
	int max(int num1, int num2);
	
	vector<Block> getChain();
	Block getBlock(int index);
	uint32_t getDifficulty() const;
	Block getLastBlock() const;

private:
	uint32_t Difficulty;
	vector<Block> chainOfBlocks;

};


#endif