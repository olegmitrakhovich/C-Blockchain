C-Blockchain
Proof of Work blockchain written in C++

expected output:

Mining block 1...

Block mined: 000000c1b50cb30fd8d9a0f2e16e38681cfcf9caead098cea726854925ab3772

Mining block 2...

Block mined: 0000005081063c8c854d11560cfea4fe734bde515a08565c26aa05448eea184e

Mining block 3...

Block mined: 000000ea61810fa85ff636440eb803263daf06b306c607aced9a1f996a421042

takes a long time to get to block 3!

Blockchain::Blockchain() { _vChain.emplace_back(Block(0, "Genesis Block"));

_nDifficulty = 6; <-----------------------------------lower difficulty to get faster results

}
