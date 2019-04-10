#include "Block.h"
#include "sha256.h"


void Block::MineBlock(uint32_t Difficulty) {

	char* STR = new char[Difficulty + 1];

	for (uint32_t i = 0; i < Difficulty; ++i) {
		STR[i] = '0';
	}

	STR[Difficulty] = '\0';

	string str(STR);

	cout << str;

	int i = 0;
	do {
		_Nonce++;
		_Hash = CalculateHash();
		cout << "Calculating Hash...Proof Of Work " << i++ << '\r';
	} while (_Hash.substr(0, Difficulty) != str);

	cout << "Block Mined: " << _Hash << endl;
}

inline string Block::CalculateHash() {
	stringstream ss;
	ss << _Index << _Time << _Data << _Nonce << prevHash;
	return sha256(ss.str());
}

//initialize our block
Block::Block(uint32_t blockIndex, string blockData) {
	_Index = blockIndex;
	_Data = blockData;
	_Time = time(nullptr);
	_Nonce = -1;  //creates a random nonce, more or less, for your genesis block
}

string Block::getHash() {
	return _Hash;
}

//Block getters
uint32_t Block::getIndex() {
	return _Index;
}

uint64_t Block::getNonce() {
	return _Nonce;
}

string Block::getData() {
	return _Data;
}

time_t Block::getTime() {
	return  _Time;
}