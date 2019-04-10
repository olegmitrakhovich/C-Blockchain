#include "Blockchain.h"


int main()
{
	Blockchain newChain = Blockchain();

	for (int i = 1; i < 100; i++) {
		cout << endl;
		cout << "Mining Block: " << i << endl;
		
		time_t parentTime = newChain.getLastBlock().getTime();
		uint32_t parentNumber = newChain.getLastBlock().getNonce();
		
		newChain.addBlock(Block(i, "Block Data"));
		 
		cout << "last block time: " << newChain.getLastBlock().getTime() << endl;
		cout << "parent block time: " << parentTime << endl;
		
		newChain.calcDifficulty(newChain.getLastBlock().getTime(), parentTime, parentNumber);
		cout << "New Difficulty: " << newChain.getDifficulty() << endl;
	}

	int x = newChain.getChain().size();

	cout << "DISPLAY ALL BLOCKS: " << endl;
	for (int i = 0; i < x; ++i)
	cout << ' ' << newChain.getBlock(i).getIndex() << ' ' << newChain.getBlock(i).getNonce() << ' ' << newChain.getBlock(i).getData() << ' ' << newChain.getBlock(i).getHash() << ' ' << newChain.getBlock(i).getTime() << endl;
	cout << '\n';

   
}

