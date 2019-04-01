#include "Block.h"
#include "sha256.h"



Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
	_nNonce = -1;
	_tTime = time(nullptr);
}

string Block::GetHash() {
	return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
	//char cstr[nDifficulty + 1];
	
	char* cstr = new char[nDifficulty + 1];
	
	//vector<char> cstr(nDifficulty);
	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);

	//string str(cstr.begin(), cstr.end());

	cout << str;
	do {
		_nNonce++;
		_sHash = _CalculateHash();
		//cout << "Proof of Work (PoW): " << _nNonce << endl << endl;
	} while (_sHash.substr(0, nDifficulty) != str);

	cout << "Block mined: " << _sHash << endl;

	delete cstr;
}

inline string Block::_CalculateHash() const {
	stringstream ss;
	ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

	return sha256(ss.str());
}

