#include "Blockchain.h"


Blockchain::Blockchain() {
	chainOfBlocks.emplace_back(Block(0, "Genesis Block"));
	Difficulty = 1;
}

void Blockchain::addBlock(Block newBlock) {
	newBlock.prevHash = getLastBlock().getHash();
	newBlock.MineBlock(Difficulty);
	chainOfBlocks.push_back(newBlock);
}


uint32_t Blockchain::getDifficulty() const {
	return Difficulty;
}

void Blockchain::calcDifficulty(time_t time, time_t parentTime, uint32_t parentNumber) {
	//https://dltlabs.com/how-difficulty-adjustment-algorithm-works-in-ethereum/
	//https://ethereum.stackexchange.com/questions/1880/how-is-the-mining-difficulty-calculated-on-ethereum


	uint32_t parentDifference = time - parentTime;
	uint32_t block_diff;


	//block_diff = parentDifference + parentDifference / 2048 * max(1 - (time - parentTime) / 10, -99) + int(pow(2,(getLastBlock().getIndex() / 100000) - 2));

	cout << "Block Time Difference: " << parentDifference << endl;

	if (parentDifference < 13) {
		Difficulty += 1;
	}

	if (parentDifference > 18) {
		Difficulty -= 1;
	}

}

int Blockchain::max(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	}
	return num2;
}

//Blockchain getters
vector<Block> Blockchain::getChain() {
	return chainOfBlocks;
}

Block Blockchain::getBlock(int index) {
	return chainOfBlocks[index];
}

Block Blockchain::getLastBlock() const {
	return chainOfBlocks.back();
}