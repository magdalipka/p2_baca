
/*
####################################################
*/

#include <iostream>

int main(){
	std::cout << "\n";
	/*
	FruitLengthWeight
	*/
	{
		std::cout << "----------------------------------------\n" << "FruitLengthWeight\n\n";

		FRUIT_CLASS* fruit = new FRUIT_CLASS();

		if(0 != fruit->getWeight()){ std::cout << "BLAD - #1\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(0 != fruit->getLength()){ std::cout << "BLAD - #2\n" << fruit->getLength() << "\n"; } else { std::cout << "OK - #2\n"; };

		delete fruit;
	}

	/*
	FruitGrowth
	*/
	{
		std::cout << "----------------------------------------\n" << "FruitGrowth\n\n";

		FRUIT_CLASS* fruit = new FRUIT_CLASS();

		if(0 != fruit->getWeight()){ std::cout << "BLAD - #1\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		fruit->growthFruit();
		if(1 != fruit->getWeight()){ std::cout << "BLAD - #2\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #2\n"; };
		fruit->growthFruit();
		fruit->growthFruit();
		fruit->growthFruit();
		if(4 != fruit->getWeight()){ std::cout << "BLAD - #3\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #3\n"; };

		delete fruit;
	}

	/*
	FruitFade
	*/
	{
		std::cout << "----------------------------------------\n" << "FruitFade\n\n";
		FRUIT_CLASS* fruit = new FRUIT_CLASS();

		if(0 != fruit->getWeight()){ std::cout << "BLAD - #1\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		fruit->growthFruit();
		fruit->growthFruit();
		fruit->growthFruit();
		fruit->growthFruit();
		if(4 != fruit->getWeight()){ std::cout << "BLAD - #2\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #2\n"; };

		fruit->fadeFruit();
		if(3 != fruit->getWeight()){ std::cout << "BLAD - #3\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #3\n"; };
		fruit->fadeFruit();
		fruit->fadeFruit();
		fruit->fadeFruit();
		if(0 != fruit->getWeight()){ std::cout << "BLAD - #4\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #4\n"; };

		fruit->fadeFruit();
		if(0 != fruit->getWeight()){ std::cout << "BLAD - #5\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #5\n"; };

		delete fruit;
	}

	/*
	FruitPluck
	*/
	{
		std::cout << "----------------------------------------\n" << "FruitPluck\n\n";
		FRUIT_CLASS* fruit = new FRUIT_CLASS();

		if(0 != fruit->getWeight()){ std::cout << "BLAD - #1\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		fruit->growthFruit();
		fruit->growthFruit();
		fruit->growthFruit();
		fruit->growthFruit();
		if(4 != fruit->getWeight()){ std::cout << "BLAD - #2\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #2\n"; };
		fruit->pluckFruit();
		if(0 != fruit->getWeight()){ std::cout << "BLAD - #3\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #3\n"; };
		fruit->pluckFruit();
		if(0 != fruit->getWeight()){ std::cout << "BLAD - #4\n" << fruit->getWeight() << "\n"; } else { std::cout << "OK - #4\n"; };

		delete fruit;
	}

	/*
	BranchConstructor
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchConstructor\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #1\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #2\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
	}

	/*
	BranchGrowth
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchGrowth\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		if(0 != branch.getLength()){ std::cout << "BLAD - #1a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1a\n"; };
		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #1b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #1b\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #1c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #1c\n"; };

		branch.growthBranch();
		if(1 != branch.getLength()){ std::cout << "BLAD - #2a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #2a\n"; };
		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #2b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2b\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #2c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #2c\n"; };

		branch.growthBranch();
		if(2 != branch.getLength()){ std::cout << "BLAD - #3a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #3a\n"; };
		if(1 != branch.getFruitsTotal()){ std::cout << "BLAD - #3b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #3b\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #3c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3c\n"; };

		branch.growthBranch();
		if(3 != branch.getLength()){ std::cout << "BLAD - #4a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #4a\n"; };
		if(1 != branch.getFruitsTotal()){ std::cout << "BLAD - #4b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #4b\n"; };
		if(1 != branch.getWeightsTotal()){ std::cout << "BLAD - #4c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #4c\n"; };

		branch.growthBranch();
		if(4 != branch.getLength()){ std::cout << "BLAD - #5a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #5a\n"; };
		if(2 != branch.getFruitsTotal()){ std::cout << "BLAD - #5b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #5b\n"; };
		if(2 != branch.getWeightsTotal()){ std::cout << "BLAD - #5c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #5c\n"; };

		branch.growthBranch();
		if(5 != branch.getLength()){ std::cout << "BLAD - #6a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #6a\n"; };
		if(2 != branch.getFruitsTotal()){ std::cout << "BLAD - #6b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #6b\n"; };
		if(4 != branch.getWeightsTotal()){ std::cout << "BLAD - #6c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #6c\n"; };

		branch.growthBranch();
		if(6 != branch.getLength()){ std::cout << "BLAD - #7a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #7a\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #7b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #7b\n"; };
		if(6 != branch.getWeightsTotal()){ std::cout << "BLAD - #7c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #7c\n"; };

		branch.growthBranch();
		if(7 != branch.getLength()){ std::cout << "BLAD - #8a\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #8a\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #8b\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #8b\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #8c\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #8c\n"; };
	}

	/*
	BranchHarvestMid
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchHarvestMid\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		branch.harvestBranch(3);

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(1 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };
	}

	/*
	BranchHarvestLast
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchHarvestLast\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		branch.harvestBranch(1);

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };
	}

	/*
	BranchHarvestFirst
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchHarvestFirst\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		branch.harvestBranch(5);

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(4 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };
	}

	/*
	BranchCut
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchCut\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };

		branch.cutBranch(6);
		if(6 != branch.getLength()){ std::cout << "BLAD - #4\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #4\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #5\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #5\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #6\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #6\n"; };

		branch.cutBranch(3);
		if(3 != branch.getLength()){ std::cout << "BLAD - #7\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #7\n"; };
		if(1 != branch.getFruitsTotal()){ std::cout << "BLAD - #8\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #8\n"; };
		if(5 != branch.getWeightsTotal()){ std::cout << "BLAD - #9\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #9\n"; };

		branch.cutBranch(0);
		if(0 != branch.getLength()){ std::cout << "BLAD - #10\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #10\n"; };
		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #11\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #11\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #12\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #12\n"; };
	}

	/*
	BranchFindFruit
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchFindFruit\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };

		if(2 != branch.getFruitPointer(2)->getLength()){ std::cout << "BLAD - #4\n" << branch.getFruitPointer(2)->getLength() << "\n"; } else { std::cout << "OK - #4\n"; };
		if(4 != branch.getFruitPointer(4)->getLength()){ std::cout << "BLAD - #5\n" << branch.getFruitPointer(4)->getLength() << "\n"; } else { std::cout << "OK - #5\n"; };
		if(6 != branch.getFruitPointer(6)->getLength()){ std::cout << "BLAD - #6\n" << branch.getFruitPointer(6)->getLength() << "\n"; } else { std::cout << "OK - #6\n"; };

		if(branch.getFruitPointer(0)){ std::cout << "BLAD - #7\n" << branch.getFruitPointer(0) << "\n"; } else { std::cout << "OK - #7\n"; };
		if(branch.getFruitPointer(7)){ std::cout << "BLAD - #8\n" << branch.getFruitPointer(7) << "\n"; } else { std::cout << "OK - #8\n"; };
		if(branch.getFruitPointer(8)){ std::cout << "BLAD - #9\n" << branch.getFruitPointer(8) << "\n"; } else { std::cout << "OK - #9\n"; };
		if(branch.getFruitPointer(-1)){ std::cout << "BLAD - #10\n" << branch.getFruitPointer(-1) << "\n"; } else { std::cout << "OK - #10\n"; };
	}

	/*
	BranchFade
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchFade\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };

		branch.fadeBranch();
		if(6 != branch.getLength()){ std::cout << "BLAD - #4\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #4\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #5\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #5\n"; };
		if(6 != branch.getWeightsTotal()){ std::cout << "BLAD - #6\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #6\n"; };

		branch.fadeBranch();
		if(5 != branch.getLength()){ std::cout << "BLAD - #7\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #7\n"; };
		if(2 != branch.getFruitsTotal()){ std::cout << "BLAD - #8\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #8\n"; };
		if(4 != branch.getWeightsTotal()){ std::cout << "BLAD - #9\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #9\n"; };

		branch.fadeBranch();
		if(4 != branch.getLength()){ std::cout << "BLAD - #10\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #10\n"; };
		if(2 != branch.getFruitsTotal()){ std::cout << "BLAD - #11\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #11\n"; };
		if(2 != branch.getWeightsTotal()){ std::cout << "BLAD - #12\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #12\n"; };

		branch.fadeBranch();
		if(3 != branch.getLength()){ std::cout << "BLAD - #13\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #13\n"; };
		if(1 != branch.getFruitsTotal()){ std::cout << "BLAD - #14\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #14\n"; };
		if(1 != branch.getWeightsTotal()){ std::cout << "BLAD - #15\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #15\n"; };

		branch.fadeBranch();
		if(2 != branch.getLength()){ std::cout << "BLAD - #16\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #16\n"; };
		if(1 != branch.getFruitsTotal()){ std::cout << "BLAD - #17\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #17\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #18\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #18\n"; };

		branch.fadeBranch();
		if(1 != branch.getLength()){ std::cout << "BLAD - #19\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #19\n"; };
		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #20\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #20\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #21\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #21\n"; };

		branch.fadeBranch();
		if(0 != branch.getLength()){ std::cout << "BLAD - #22\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #22\n"; };
		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #23\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #23\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #24\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #24\n"; };

		branch.fadeBranch();
		if(0 != branch.getLength()){ std::cout << "BLAD - #25\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #25\n"; };
		if(0 != branch.getFruitsTotal()){ std::cout << "BLAD - #26\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #26\n"; };
		if(0 != branch.getWeightsTotal()){ std::cout << "BLAD - #27\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #27\n"; };
	}

	/*
	BranchCopyConstructor
	*/
	{
		std::cout << "----------------------------------------\n" << "BranchCopyConstructor\n\n";
		BRANCH_CLASS branch = BRANCH_CLASS();

		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();
		branch.growthBranch();

		if(7 != branch.getLength()){ std::cout << "BLAD - #1\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #2\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #3\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };

		BRANCH_CLASS branch2 = BRANCH_CLASS(branch);

		if(branch.getWoodPointer() != branch2.getWoodPointer()){ std::cout << "BLAD - #4\n" << branch.getWoodPointer() << " " << branch2.getWoodPointer() << "\n"; } else { std::cout << "OK - #4\n"; };

		branch2.growthBranch();
		if(8 != branch2.getLength()){ std::cout << "BLAD - #5\n" << branch2.getLength() << "\n"; } else { std::cout << "OK - #5\n"; };
		if(4 != branch2.getFruitsTotal()){ std::cout << "BLAD - #6\n" << branch2.getFruitsTotal() << "\n"; } else { std::cout << "OK - #6\n"; };
		if(12 != branch2.getWeightsTotal()){ std::cout << "BLAD - #7\n" << branch2.getWeightsTotal() << "\n"; } else { std::cout << "OK - #7\n"; };

		if(7 != branch.getLength()){ std::cout << "BLAD - #8\n" << branch.getLength() << "\n"; } else { std::cout << "OK - #8\n"; };
		if(3 != branch.getFruitsTotal()){ std::cout << "BLAD - #9\n" << branch.getFruitsTotal() << "\n"; } else { std::cout << "OK - #9\n"; };
		if(9 != branch.getWeightsTotal()){ std::cout << "BLAD - #10\n" << branch.getWeightsTotal() << "\n"; } else { std::cout << "OK - #10\n"; };
	}

	/*
	WoodConstructor
	*/
	{
		std::cout << "----------------------------------------\n" << "WoodConstructor\n\n";
		WOOD_CLASS wood = WOOD_CLASS();

		if(0 != wood.getHeight()){ std::cout << "BLAD - #1\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #2\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #3\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #4\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #4\n"; };
	}

	/*
	WoodGrowth
	*/
	{
		std::cout << "----------------------------------------\n" << "WoodGrowth\n\n";
		WOOD_CLASS wood = WOOD_CLASS();
		if(0 != wood.getHeight()){ std::cout << "BLAD - #1\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #2\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #3\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #4\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #4\n"; };

		wood.growthWood();
		if(1 != wood.getHeight()){ std::cout << "BLAD - #5\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #5\n"; };
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #6\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #6\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #7\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #7\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #8\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #8\n"; };

		wood.growthWood();
		if(2 != wood.getHeight()){ std::cout << "BLAD - #9\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #9\n"; };
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #10\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #10\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #11\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #11\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #12\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #12\n"; };

		wood.growthWood();
		if(3 != wood.getHeight()){ std::cout << "BLAD - #13\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #13\n"; };
		if(1 != wood.getBranchesTotal()){ std::cout << "BLAD - #14\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #14\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #15\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #15\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #16\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #16\n"; };

		wood.growthWood();
		if(4 != wood.getHeight()){ std::cout << "BLAD - #17\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #17\n"; };
		if(1 != wood.getBranchesTotal()){ std::cout << "BLAD - #18\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #18\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #19\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #19\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #20\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #20\n"; };

		wood.growthWood();
		if(5 != wood.getHeight()){ std::cout << "BLAD - #21\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #21\n"; };
		if(1 != wood.getBranchesTotal()){ std::cout << "BLAD - #22\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #22\n"; };
		if(1 != wood.getFruitsTotal()){ std::cout << "BLAD - #23\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #23\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #24\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #24\n"; };

		wood.growthWood();
		if(6 != wood.getHeight()){ std::cout << "BLAD - #25\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #25\n"; };
		if(2 != wood.getBranchesTotal()){ std::cout << "BLAD - #26\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #26\n"; };
		if(1 != wood.getFruitsTotal()){ std::cout << "BLAD - #27\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #27\n"; };
		if(1 != wood.getWeightsTotal()){ std::cout << "BLAD - #28\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #28\n"; };

		wood.growthWood();
		if(7 != wood.getHeight()){ std::cout << "BLAD - #29\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #29\n"; };
		if(2 != wood.getBranchesTotal()){ std::cout << "BLAD - #30\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #30\n"; };
		if(2 != wood.getFruitsTotal()){ std::cout << "BLAD - #31\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #31\n"; };
		if(2 != wood.getWeightsTotal()){ std::cout << "BLAD - #32\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #32\n"; };

		wood.growthWood();
		if(8 != wood.getHeight()){ std::cout << "BLAD - #33\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #33\n"; };
		if(2 != wood.getBranchesTotal()){ std::cout << "BLAD - #34\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #34\n"; };
		if(3 != wood.getFruitsTotal()){ std::cout << "BLAD - #35\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #35\n"; };
		if(4 != wood.getWeightsTotal()){ std::cout << "BLAD - #36\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #36\n"; };

		for(int i=0; i<100; i++){
			wood.growthWood();
		}

		if(108 != wood.getHeight()){ std::cout << "BLAD - #37\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #37\n"; };
		if(36 != wood.getBranchesTotal()){ std::cout << "BLAD - #38\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #38\n"; };
		if(936 != wood.getFruitsTotal()){ std::cout << "BLAD - #39\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #39\n"; };
		if(32607 != wood.getWeightsTotal()){ std::cout << "BLAD - #40\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #40\n"; };
	}

	/*
	WoodFade
	*/
	{
		std::cout << "----------------------------------------\n" << "WoodFade\n\n";
		WOOD_CLASS wood = WOOD_CLASS();
		if(0 != wood.getHeight()){ std::cout << "BLAD - #1\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #1\n"; };
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #2\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #2\n"; };
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #3\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #3\n"; };
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #4\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #4\n"; };

		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();

		int calc = 5;
		if(9 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(3 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(4 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(7 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		wood.fadeWood();
		if(8 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(3 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(4 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		wood.fadeWood();
		if(7 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(6 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(5 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(4 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(3 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(2 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(1 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(0 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.fadeWood();
		if(0 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
	}

	/*
	WoodFindBranch
	*/
	{
		std::cout << "----------------------------------------\n" << "WoodFindBranch\n\n";

		auto wood = WOOD_CLASS();
		int calc = 1;
		if(wood.getGardenPointer()){ std::cout << "BLAD - #" << calc << "\n" << wood.getGardenPointer() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(0)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(0) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(1)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(1) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(2)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(2) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(3)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(3) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		wood.growthWood();

		if(wood.getBranchPointer(0)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(0) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(1)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(1) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(2)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(2) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(3)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(3) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;


		wood.growthWood();
		wood.growthWood();

		if(wood.getBranchPointer(0)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(0) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(1)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(1) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(2)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(2) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchesTotal() != 1){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(3)->getHeight() != 3){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(3)->getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(4)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(4) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
	}

	/*
	WoodCloneBranch
	*/
	{
		std::cout << "----------------------------------------\n" << "WoodCloneBranch\n\n";
		WOOD_CLASS wood = WOOD_CLASS();

		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();

		int calc = 1;
		if(12 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(4 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(8 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(23 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		wood.getBranchPointer(6)->fadeBranch();
		wood.getBranchPointer(6)->fadeBranch();
		wood.getBranchPointer(6)->fadeBranch();
		wood.getBranchPointer(6)->fadeBranch();
		wood.getBranchPointer(6)->fadeBranch();
		wood.getBranchPointer(6)->fadeBranch();
		BRANCH_CLASS* to_clone = wood.getBranchPointer(3);

		for(int i=0; i<100; i++){
			to_clone->growthBranch();
		}
		wood.cloneBranch(to_clone);
		to_clone->growthBranch();
		//wood.tellmeyourfruitsize();
		if(12 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(4 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(110 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(5887 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
	}

	/*
	WoodCopyConstructor
	*/
	{
		std::cout << "----------------------------------------\n" << "WoodCopyConstructor\n\n";
		WOOD_CLASS wood = WOOD_CLASS();

		int calc = 1;
		if(0 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();
		wood.growthWood();

		if(9 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(3 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(4 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(7 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		auto wood2 = WOOD_CLASS(wood);

		if(wood.getBranchesTotal() != wood2.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << " " << wood2.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getFruitsTotal() != wood2.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << " " << wood2.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getWeightsTotal() != wood2.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << " " << wood2.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getHeight() != wood2.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << " " << wood2.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getNumber() != wood2.getNumber()){ std::cout << "BLAD - #" << calc << "\n" << wood.getNumber() << " " << wood2.getNumber() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getGardenPointer() != wood2.getGardenPointer()){ std::cout << "BLAD - #" << calc << "\n" << wood.getGardenPointer() << " " << wood2.getGardenPointer() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(3) == wood2.getBranchPointer(3)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(3) << " " << wood2.getBranchPointer(3) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		wood2.growthWood();
		if(10 != wood2.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood2.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(3 != wood2.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood2.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(5 != wood2.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood2.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(11 != wood2.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood2.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		if(wood.getBranchesTotal() != wood2.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << " " << wood2.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getFruitsTotal() == wood2.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << " " << wood2.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getWeightsTotal() == wood2.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << " " << wood2.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getHeight() == wood2.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << " " << wood2.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getNumber() != wood2.getNumber()){ std::cout << "BLAD - #" << calc << "\n" << wood.getNumber() << " " << wood2.getNumber() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getGardenPointer() != wood2.getGardenPointer()){ std::cout << "BLAD - #" << calc << "\n" << wood.getGardenPointer() << " " << wood2.getGardenPointer() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(wood.getBranchPointer(3) == wood2.getBranchPointer(3)){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchPointer(3) << " " << wood2.getBranchPointer(3) << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;

		if(9 != wood.getHeight()){ std::cout << "BLAD - #" << calc << "\n" << wood.getHeight() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(3 != wood.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(4 != wood.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(7 != wood.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << wood.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
	}

	/*
	GardenConstructor
	*/
	{
		std::cout << "----------------------------------------\n" << "GardenConstructor\n\n";
		GARDEN_CLASS garden = GARDEN_CLASS();
		int calc = 1;
		if(0 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;
	}

	/*
	GardenPlant
	*/
	{
		std::cout << "----------------------------------------\n" << "GardenPlant\n\n";
		GARDEN_CLASS garden = GARDEN_CLASS();

		for(int i=0; i<1000000; i++){
			garden.plantWood();
		}
		int calc = 1;
		if(1000000 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;
	}

	/*
	GardenGrowth
	*/
	{
		std::cout << "----------------------------------------\n" << "GardenGrowth\n\n";
		GARDEN_CLASS garden = GARDEN_CLASS();

		garden.plantWood();
		garden.plantWood();

		int calc = 1;
		if(2 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;

		garden.growthGarden();
		garden.growthGarden();
		garden.growthGarden();

		if(2 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;

		garden.growthGarden();
		garden.growthGarden();

		if(2 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;
	}

	/*
	GardenHarvest
	*/
	{
		std::cout << "----------------------------------------\n" << "GardenHarvest\n\n";

		GARDEN_CLASS garden = GARDEN_CLASS();

		garden.plantWood();
		garden.plantWood();

		int calc = 1;
		if(2 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;

		for(int i=0; i<100; ++i){
			garden.growthGarden();
		}

		if(2 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(66 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1600 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(51472 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;
	}

	/*
	GardenClone
	*/
	{
		std::cout << "----------------------------------------\n" << "GardenClone\n\n";
		GARDEN_CLASS garden = GARDEN_CLASS();

		garden.plantWood();
		garden.plantWood();
		garden.plantWood();

		int calc = 1;
		if(3 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;

		WOOD_CLASS* cloned = garden.getWoodPointer(0);
		cloned->growthWood();
		cloned->growthWood();
		cloned->growthWood();

		if(3 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;

		garden.cloneWood(0);

		if(4 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;

		garden.getWoodPointer(3)->growthWood();
		garden.getWoodPointer(3)->growthWood();
		if(4 != garden.getWoodsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWoodsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(2 != garden.getBranchesTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getBranchesTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(1 != garden.getFruitsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getFruitsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;
		if(0 != garden.getWeightsTotal()){ std::cout << "BLAD - #" << calc << "\n" << garden.getWeightsTotal() << "\n"; } else { std::cout << "OK - #" << calc << "\n"; }; calc++;;
	}
	/*
	Bez:
	- FruitCreateDestroy
	- FruitGetParent
	- GardenExtract
	*/
	return 0;
}