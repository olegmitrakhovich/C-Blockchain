# C-Blockchain
Proof of Work blockchain written in C++

output:
![c-blockchain-difficulty](https://user-images.githubusercontent.com/24768092/55850633-1a048e80-5b23-11e9-84ad-63daa5b3dc6c.PNG)

The issue is here:

void Blockchain::calcDifficulty(time_t time, time_t parentTime, uint32_t parentNumber) {


uint32_t parentDifference = time - parentTime;
uint32_t block_diff;

block_diff = parentDifference + parentDifference / 2048 * max(1 - (time - parentTime) / 10, -99) + int(pow(2,  (getLastBlock().getIndex() / 100000) - 2));

cout << "Block Time Difference: " << parentDifference << endl;

if (parentDifference < 13) {
		Difficulty += 1;
}

if (parentDifference > 18) {
		Difficulty -= 1;
		}

}
