// Magdalena Lipka
#include <iostream>
using namespace std;

class FRUIT_CLASS;
class BRANCH_CLASS;
class WOOD_CLASS;
class GARDEN_CLASS;

class FRUIT_CLASS {
 private:
  FRUIT_CLASS* prevFruit;
  FRUIT_CLASS* nextFruit;
  unsigned int weight;
  unsigned int length;
  BRANCH_CLASS* motherBranch;

 public:
  FRUIT_CLASS() {
    (*this).prevFruit = NULL;
    (*this).nextFruit = NULL;
    (*this).weight = 0;
    (*this).length = 0;
    (*this).motherBranch = NULL;
  }

  FRUIT_CLASS(FRUIT_CLASS* setprev, FRUIT_CLASS* setnext, unsigned int setweight, unsigned int setlength, BRANCH_CLASS* setmother) {
    prevFruit = setprev;
    nextFruit = setnext;
    weight = setweight;
    length = setlength;
    motherBranch = setmother;
  }
  FRUIT_CLASS(const FRUIT_CLASS& sourceFruit) {
    //*this = sourceFruit;
    // FRUIT_CLASS& source = const_cast<FRUIT_CLASS&>(sourceFruit);
    prevFruit = NULL;
    nextFruit = NULL;
    weight = sourceFruit.weight;
    length = sourceFruit.length;
    motherBranch = NULL;
  }

  FRUIT_CLASS* getnextFruit() {
    return nextFruit;
  }

  FRUIT_CLASS* getprevFruit() {
    return prevFruit;
  }

  void setnextFruit(FRUIT_CLASS* inserted) {
    nextFruit = inserted;
  }

  void setprevFruit(FRUIT_CLASS* inserted) {
    prevFruit = inserted;
  }

  unsigned int getLength() {
    return length;
  }

  void setLength(unsigned int inserted) {
    length = inserted;
  }

  unsigned int getWeight() {
    return weight;
  }

  void setWeight(unsigned int inserted) {
    weight = inserted;
  }

  void growthFruit() {
    weight++;
  }

  void fadeFruit() {
    if (weight > 0) weight--;
  }

  void pluckFruit() {
    weight = 0;
  }

  BRANCH_CLASS* getBranchPointer() {
    return motherBranch;
  }

  void setMotherBranchPointer(BRANCH_CLASS* mother) {
    motherBranch = mother;
  }
};

class BRANCH_CLASS {
 private:
  FRUIT_CLASS* firstFruit;
  FRUIT_CLASS* lastFruit;
  BRANCH_CLASS* nextBranch;
  BRANCH_CLASS* prevBranch;
  WOOD_CLASS* motherWood;
  unsigned int height;
  unsigned int length;

 public:
  BRANCH_CLASS() {
    firstFruit = NULL;
    lastFruit = NULL;
    prevBranch = NULL;
    nextBranch = NULL;
    motherWood = NULL;
    height = 0;
    length = 0;
  }

  BRANCH_CLASS(FRUIT_CLASS* setfirst, FRUIT_CLASS* setlast, BRANCH_CLASS* setnext, BRANCH_CLASS* setprev, WOOD_CLASS* setmother, unsigned int setheight, unsigned int setlength) {
    firstFruit = setfirst;
    lastFruit = setlast;
    prevBranch = setprev;
    nextBranch = setnext;
    motherWood = setmother;
    height = setheight;
    length = setlength;
  }

  BRANCH_CLASS(const BRANCH_CLASS& source) {
    prevBranch = NULL;
    nextBranch = NULL;

    // skopiowanie infomacji o owocach

    // BRANCH_CLASS& source = const_cast<BRANCH_CLASS&>(sourceBranch);

    length = source.length;
    height = source.height;
    // motherWood = source.motherWood;

    if (source.firstFruit == NULL) {
      firstFruit = NULL;
      lastFruit = NULL;
    } else {
      FRUIT_CLASS* sourceFruit = source.firstFruit;
      // pierwszy owoc
      FRUIT_CLASS* newFruit = new FRUIT_CLASS(*sourceFruit);
      (*newFruit).setMotherBranchPointer(this);
      firstFruit = newFruit;
      // srodkowe owoce
      while ((*sourceFruit).getnextFruit() != NULL) {
        sourceFruit = (*sourceFruit).getnextFruit();
        FRUIT_CLASS* nextFruit = new FRUIT_CLASS(*sourceFruit);
        (*nextFruit).setMotherBranchPointer(this);
        (*newFruit).setnextFruit(nextFruit);
        //(*nextFruit).setprevFruit(newFruit);
        newFruit = nextFruit;
      }
      // ostatni owoc
      lastFruit = newFruit;
    }
  }

  ~BRANCH_CLASS() {
    FRUIT_CLASS* fruit = firstFruit;
    FRUIT_CLASS* temp;
    while (fruit != NULL) {
      temp = (*fruit).getnextFruit();
      //(*temp).setprevFruit(NULL);
      delete fruit;
      fruit = temp;
    }
  }

  unsigned int getWeightsTotal() {
    unsigned int sum = 0;
    FRUIT_CLASS* fruit = firstFruit;
    while (fruit != NULL) {
      sum += (*fruit).getWeight();
      fruit = (*fruit).getnextFruit();
    }
    return sum;
  }

  unsigned int getFruitsTotal() {
    unsigned int sum = 0;
    FRUIT_CLASS* fruit = firstFruit;
    while (fruit != NULL) {
      sum++;
      fruit = (*fruit).getnextFruit();
    }
    return sum;
  }

  FRUIT_CLASS* getFirstFruit() {
    return firstFruit;
  }

  FRUIT_CLASS* getLastFruit() {
    return lastFruit;
  }

  void setFirstFruit(FRUIT_CLASS* inserted) {
    firstFruit = inserted;
  }

  void setLastFruit(FRUIT_CLASS* inserted) {
    lastFruit = inserted;
  }

  BRANCH_CLASS* getnextBranch() {
    return nextBranch;
  }

  void setnextBranch(BRANCH_CLASS* inserted) {
    nextBranch = inserted;
  }

  void setprevBranch(BRANCH_CLASS* inserted) {
    prevBranch = inserted;
  }

  BRANCH_CLASS* getprevBranch() {
    return prevBranch;
  }

  unsigned int getHeight() {
    return height;
  }

  unsigned int getLength() {
    return length;
  }

  void setHeight(unsigned int parameter) {
    height = parameter;
  }

  void setLength(unsigned int parameter) {
    length = parameter;
  }

  WOOD_CLASS* getmotherWood() {
    return motherWood;
  }

  void setmotherWood(WOOD_CLASS* inserted) {
    motherWood = inserted;
  }

  void growthBranch() {
    length++;

    // zwieksznenie wag owocow
    FRUIT_CLASS* fruit = firstFruit;
    while (fruit != NULL) {
      (*fruit).growthFruit();
      fruit = (*fruit).getnextFruit();
    }

    // dodanie nowego owocu
    if (length % 2 == 0) {
      if (firstFruit == NULL) {
        FRUIT_CLASS* newFruit = new FRUIT_CLASS(NULL, NULL, 0, length, this);
        firstFruit = newFruit;
        lastFruit = newFruit;
      } else {
        FRUIT_CLASS* newFruit = new FRUIT_CLASS(lastFruit, NULL, 0, length, this);
        (*lastFruit).setnextFruit(newFruit);
        lastFruit = newFruit;
      }
    }
  }

  void fadeBranch() {
    if (length == 0) return;
    length--;
    if (length == 0) return;

    FRUIT_CLASS* fruit = firstFruit;
    while (fruit != NULL) {
      (*fruit).fadeFruit();
      fruit = (*fruit).getnextFruit();
    }
    if ((*lastFruit).getLength() > length) {
      if (lastFruit == firstFruit) {
        delete lastFruit;
        lastFruit = NULL;
        firstFruit = NULL;
      } else {
        FRUIT_CLASS* temp = (*lastFruit).getprevFruit();
        (*temp).setnextFruit(NULL);
        delete lastFruit;
        lastFruit = temp;
      }
    }
  }

  void harvestBranch(unsigned int parameter) {
    FRUIT_CLASS* fruit = firstFruit;
    while (fruit != NULL) {
      if ((*fruit).getWeight() >= parameter) (*fruit).pluckFruit();
      fruit = (*fruit).getnextFruit();
    }
  }

  void cutBranch(unsigned int newlength) {
    length = newlength;
    FRUIT_CLASS* fruit = firstFruit;
    FRUIT_CLASS* deleteFromhere = NULL;
    while (fruit != NULL) {
      if ((*fruit).getLength() > length) {
        deleteFromhere = fruit;
        break;
      }
      fruit = (*fruit).getnextFruit();
    }
    if (deleteFromhere != NULL) {
      if ((*deleteFromhere).getprevFruit() == NULL && (*deleteFromhere).getnextFruit() == NULL) {
        // usuwanie jedynego
        firstFruit = NULL;
        lastFruit = NULL;
        delete deleteFromhere;
      } else if ((*deleteFromhere).getprevFruit() == NULL) {
        // usuwanie od pierwszego
        firstFruit = NULL;
        lastFruit = NULL;
        FRUIT_CLASS* temp;
        while (deleteFromhere != NULL) {
          temp = (*deleteFromhere).getnextFruit();
          delete deleteFromhere;
          deleteFromhere = temp;
        }
      } else if ((*deleteFromhere).getnextFruit() == NULL) {
        // usuwanie ostatniego
        lastFruit = (*deleteFromhere).getprevFruit();
        (*lastFruit).setnextFruit(NULL);
        delete deleteFromhere;
      } else {
        // usuwanie od jakiegokolwiek innego
        (*(*deleteFromhere).getprevFruit()).setnextFruit(NULL);
        lastFruit = (*deleteFromhere).getprevFruit();
        FRUIT_CLASS* temp;
        while (deleteFromhere != NULL) {
          temp = (*deleteFromhere).getnextFruit();
          delete deleteFromhere;
          deleteFromhere = temp;
        }
      }
    }
  }

  FRUIT_CLASS* getFruitPointer(unsigned int distance) {
    FRUIT_CLASS* fruit = firstFruit;
    while (fruit != NULL) {
      if ((*fruit).getLength() == distance) return fruit;
      if ((*fruit).getLength() > distance) return NULL;
      fruit = (*fruit).getnextFruit();
    }
    return NULL;
  }

  WOOD_CLASS* getWoodPointer() {
    return motherWood;
  }
};

class WOOD_CLASS {
 private:
  BRANCH_CLASS* firstBranch;
  BRANCH_CLASS* lastBranch;
  WOOD_CLASS* nextWood;
  WOOD_CLASS* prevWood;
  GARDEN_CLASS* motherGarden;
  unsigned int id;
  unsigned int height;

 public:
  WOOD_CLASS() {
    firstBranch = NULL;
    lastBranch = NULL;
    nextWood = NULL;
    prevWood = NULL;
    motherGarden = NULL;
    id = 0;
    height = 0;
  }

  WOOD_CLASS(BRANCH_CLASS* setfirst, BRANCH_CLASS* setlast, WOOD_CLASS* setnext, WOOD_CLASS* setprev, GARDEN_CLASS* setmother, unsigned int setid, unsigned int setheight) {
    firstBranch = setfirst;
    lastBranch = setlast;
    nextWood = setnext;
    prevWood = setprev;
    motherGarden = setmother;
    id = setid;
    height = setheight;
  }

  WOOD_CLASS(const WOOD_CLASS& source) {
    // WOOD_CLASS& source = const_cast<WOOD_CLASS&>(sourceWood);
    height = source.height;
    (*this).prevWood = NULL;
    (*this).nextWood = NULL;

    if (source.firstBranch == NULL) {
      (*this).firstBranch = NULL;
      (*this).lastBranch = NULL;
    } else {
      BRANCH_CLASS* sourceBranch = source.firstBranch;
      // pierwsza galaz
      BRANCH_CLASS* newBranch = new BRANCH_CLASS(*sourceBranch);
      (*newBranch).setmotherWood(this);
      (*this).firstBranch = newBranch;
      // srodkowe galezie
      while ((*sourceBranch).getnextBranch() != NULL) {
        sourceBranch = (*sourceBranch).getnextBranch();
        BRANCH_CLASS* nextBranch = new BRANCH_CLASS(*sourceBranch);
        (*nextBranch).setmotherWood(this);
        (*newBranch).setnextBranch(nextBranch);
        (*nextBranch).setprevBranch(newBranch);
        newBranch = nextBranch;
      }
      // ostatnia galaz
      (*this).lastBranch = newBranch;
    }
  }

  ~WOOD_CLASS() {
    BRANCH_CLASS* branch = firstBranch;
    BRANCH_CLASS* temp;
    while (branch != NULL) {
      temp = (*branch).getnextBranch();
      delete branch;
      branch = temp;
    }
  }

  unsigned int getBranchesTotal() {
    BRANCH_CLASS* branch = firstBranch;
    unsigned int sum = 0;
    while (branch != NULL) {
      sum++;
      branch = (*branch).getnextBranch();
    }
    return sum;
  }

  unsigned int getFruitsTotal() {
    unsigned int sum = 0;
    BRANCH_CLASS* branch = firstBranch;
    while (branch != NULL) {
      sum += (*branch).getFruitsTotal();
      branch = (*branch).getnextBranch();
    }
    return sum;
  }

  unsigned int getWeightsTotal() {
    unsigned int sum = 0;
    BRANCH_CLASS* branch = firstBranch;
    while (branch != NULL) {
      sum += (*branch).getWeightsTotal();
      branch = (*branch).getnextBranch();
    }
    return sum;
  }

  void setGarden(GARDEN_CLASS* garden) {
    motherGarden = garden;
  }

  void setnextWood(WOOD_CLASS* setnext) {
    nextWood = setnext;
  }

  WOOD_CLASS* getnextWood() {
    return nextWood;
  }

  void setprevWood(WOOD_CLASS* setnext) {
    prevWood = setnext;
  }

  WOOD_CLASS* getprevWood() {
    return prevWood;
  }

  unsigned int getNumber() {
    return id;
  }

  void setNumber(unsigned int num) {
    id = num;
  }

  unsigned int getHeight() {
    return height;
  }

  BRANCH_CLASS* getfirstBranch() {
    return firstBranch;
  }

  BRANCH_CLASS* getlastBranch() {
    return lastBranch;
  }

  void setfirstBranch(BRANCH_CLASS* inserted) {
    firstBranch = inserted;
  }

  void setlastBranch(BRANCH_CLASS* inserted) {
    lastBranch = inserted;
  }

  void growthWood() {
    height++;
    // dojrzewanie galezi
    BRANCH_CLASS* branch = firstBranch;
    while (branch != NULL) {
      (*branch).growthBranch();
      branch = (*branch).getnextBranch();
    }
    // dodanie nowej galezi
    if (height % 3 == 0) {
      BRANCH_CLASS* newBranch = new BRANCH_CLASS(NULL, NULL, NULL, lastBranch, this, height, 0);
      if (firstBranch == NULL)
        firstBranch = newBranch;
      else
        (*lastBranch).setnextBranch(newBranch);
      lastBranch = newBranch;
    }
  }

  void fadeWood() {
    if (height == 0) return;
    height--;
    if (height < 2) return;

    BRANCH_CLASS* branch = firstBranch;
    while (branch != NULL) {
      (*branch).fadeBranch();
      branch = (*branch).getnextBranch();
    }
    if ((*lastBranch).getHeight() > height) {
      if (lastBranch == firstBranch) {
        delete lastBranch;
        lastBranch = NULL;
        firstBranch = NULL;
      } else {
        BRANCH_CLASS* temp = (*lastBranch).getprevBranch();
        delete lastBranch;
        lastBranch = temp;
        (*lastBranch).setnextBranch(NULL);
      }
    }
  }

  void harvestWood(unsigned int parameter) {
    BRANCH_CLASS* branch = firstBranch;
    while (branch != NULL) {
      (*branch).harvestBranch(parameter);
      branch = (*branch).getnextBranch();
    }
  }

  void cutWood(unsigned int parameter) {
    height = parameter;

    BRANCH_CLASS* branch = firstBranch;
    BRANCH_CLASS* deleteFromHere = NULL;
    while (branch != NULL) {
      if ((*branch).getHeight() > height) {
        deleteFromHere = branch;
        break;
      }
      branch = (*branch).getnextBranch();
    }
    if (deleteFromHere != NULL) {
      if ((*deleteFromHere).getnextBranch() == NULL && (*deleteFromHere).getprevBranch() == NULL) {
        lastBranch = NULL;
        firstBranch = NULL;
        delete deleteFromHere;
      } else if ((*deleteFromHere).getnextBranch() == NULL) {
        lastBranch = (*deleteFromHere).getprevBranch();
        (*lastBranch).setnextBranch(NULL);
        delete deleteFromHere;
      } else if ((*deleteFromHere).getprevBranch() == NULL) {
        firstBranch = NULL;
        lastBranch = NULL;
        BRANCH_CLASS* temp;
        while (deleteFromHere != NULL) {
          temp = (*deleteFromHere).getnextBranch();
          delete deleteFromHere;
          deleteFromHere = temp;
        }
      } else {
        (*(*deleteFromHere).getprevBranch()).setnextBranch(NULL);
        lastBranch = (*deleteFromHere).getprevBranch();
        BRANCH_CLASS* temp;
        while (deleteFromHere != NULL) {
          temp = (*deleteFromHere).getnextBranch();
          delete deleteFromHere;
          deleteFromHere = temp;
        }
      }
    }
  }

  void cloneBranch(BRANCH_CLASS* sourcebranch) {
    BRANCH_CLASS* seekbranch = NULL;
    BRANCH_CLASS* temp = firstBranch;
    while (temp != NULL) {
      if ((*temp).getLength() == 0) {
        seekbranch = temp;
        break;
      }
      temp = (*temp).getnextBranch();
    }
    if (seekbranch == NULL || sourcebranch == NULL) return;

    BRANCH_CLASS* newBranch = new BRANCH_CLASS(*sourcebranch);
    BRANCH_CLASS* left = (*seekbranch).getprevBranch();
    BRANCH_CLASS* right = (*seekbranch).getnextBranch();
    (*newBranch).setmotherWood(this);
    (*newBranch).setHeight((*seekbranch).getHeight());
    (*newBranch).setnextBranch(right);
    (*newBranch).setprevBranch(left);

    if (left != NULL)
      (*left).setnextBranch(newBranch);
    else
      firstBranch = newBranch;
    if (right != NULL)
      (*right).setprevBranch(newBranch);
    else
      lastBranch = newBranch;

    delete seekbranch;
  }

  GARDEN_CLASS* getGardenPointer() {
    return motherGarden;
  }

  BRANCH_CLASS* getBranchPointer(unsigned int distance) {
    BRANCH_CLASS* branch = firstBranch;
    while (branch != NULL) {
      if ((*branch).getHeight() == distance) return branch;
      if ((*branch).getHeight() > distance) return NULL;
      branch = (*branch).getnextBranch();
    }
    return NULL;
  }
};

class GARDEN_CLASS {
 private:
  WOOD_CLASS* firstWood;
  WOOD_CLASS* lastWood;
  unsigned int woods;
  unsigned int maxid;

 public:
  GARDEN_CLASS() {
    firstWood = NULL;
    lastWood = NULL;
    woods = 0;
    maxid = 0;
  }
  ~GARDEN_CLASS() {
    WOOD_CLASS* wood = firstWood;
    WOOD_CLASS* temp;
    while (wood != NULL) {
      temp = (*wood).getnextWood();
      delete wood;
      wood = temp;
    }
  }

  unsigned int getWoods() {
    return woods;
  }

  unsigned int getWoodsTotal() {
    return woods;
  }

  unsigned int getBranchesTotal() {
    unsigned int sum = 0;
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      sum += (*wood).getBranchesTotal();
      wood = (*wood).getnextWood();
    }
    return sum;
  }

  unsigned int getFruitsTotal() {
    unsigned int sum = 0;
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      sum += (*wood).getFruitsTotal();
      wood = (*wood).getnextWood();
    }
    return sum;
  }

  unsigned int getWeightsTotal() {
    unsigned int sum = 0;
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      sum += (*wood).getWeightsTotal();
      wood = (*wood).getnextWood();
    }
    return sum;
  }

  void plantWood() {
    if (woods == 0) {
      WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, NULL, NULL, this, 0, 0);
      firstWood = newWood;
      lastWood = newWood;
      maxid = 0;
    } else if (maxid + 1 == woods) {
      WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, NULL, lastWood, this, maxid + 1, 0);
      (*lastWood).setnextWood(newWood);
      lastWood = newWood;
      maxid = (*lastWood).getNumber();
    } else if ((*firstWood).getNumber() != 0) {
      WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, firstWood, NULL, this, 0, 0);
      (*firstWood).setprevWood(newWood);
      firstWood = newWood;
    } else {
      /**/
      // znalezienie miejsca do wstawienia
      WOOD_CLASS* temp = firstWood;
      while (temp != NULL) {
        if ((*temp).getnextWood() != NULL && (*temp).getNumber() + 1 < (*(*temp).getnextWood()).getNumber()) {
          WOOD_CLASS* right = (*temp).getnextWood();
          WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, right, temp, this, (*temp).getNumber() + 1, 0);
          if (temp != NULL) (*temp).setnextWood(newWood);
          if (right != NULL) (*right).setprevWood(newWood);
          break;
        }
        temp = (*temp).getnextWood();
      }
      /**/
    }
    maxid = (*lastWood).getNumber();
    woods++;
  }

  void extractWood(unsigned int seekid) {
    // if ( woods != getWoodsTotal() ) throw 3;
    // if ( lastWood != NULL && maxid != (*lastWood).getNumber() ) throw 3;
    // if ( maxid +1< woods ) throw 3;

    bool deleted = false;
    if (woods == 0) return;
    if (woods == 1 && (*firstWood).getNumber() != seekid) return;
    if (woods == 1 && (*firstWood).getNumber() == seekid) {
      WOOD_CLASS* todelete = firstWood;
      firstWood = NULL;
      lastWood = NULL;
      maxid = 0;
      deleted = true;
      delete todelete;
    } else if ((*firstWood).getNumber() == seekid) {
      if ((*firstWood).getnextWood() == NULL) throw 3;
      WOOD_CLASS* todelete = firstWood;
      firstWood = (*firstWood).getnextWood();
      (*firstWood).setprevWood(NULL);
      deleted = true;
      delete todelete;
    } else if ((*lastWood).getNumber() == seekid) {
      // throw 3;
      WOOD_CLASS* todelete = lastWood;
      lastWood = (*lastWood).getprevWood();
      (*lastWood).setnextWood(NULL);
      maxid = (*lastWood).getNumber();
      deleted = true;
      delete todelete;
    } else {
      /**/
      WOOD_CLASS* temp = firstWood;
      while (temp != NULL) {
        // if ( temp == lastWood ) throw 3;
        if ((*temp).getNumber() == seekid) {
          WOOD_CLASS* left = (*temp).getprevWood();
          WOOD_CLASS* right = (*temp).getnextWood();
          if (temp == lastWood) {
            maxid = (*lastWood).getNumber();
            lastWood = (*lastWood).getprevWood();
          }
          if (left != NULL)
            (*left).setnextWood(right);
          else
            firstWood = right;
          if (right != NULL)
            (*right).setprevWood(left);
          else
            lastWood = left;
          deleted = true;
          delete temp;
          break;
        }
        if ((*temp).getNumber() > seekid) break;
        temp = (*temp).getnextWood();
      }
      /**/
    }
    if (lastWood != NULL)
      maxid = (*lastWood).getNumber();
    else
      maxid = 0;
    if (deleted) woods--;
  }

  void growthGarden() {
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      (*wood).growthWood();
      wood = (*wood).getnextWood();
    }
  }

  void fadeGarden() {
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      (*wood).fadeWood();
      wood = (*wood).getnextWood();
    }
  }

  void harvestGarden(unsigned int parameter) {
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      (*wood).harvestWood(parameter);
      wood = (*wood).getnextWood();
    }
  }

  void cloneWood(unsigned int seekid) {
    WOOD_CLASS* seekwood = NULL;
    WOOD_CLASS* temp = firstWood;

    bool cloned = false;

    while (temp != NULL) {
      if ((*temp).getNumber() == seekid) {
        seekwood = temp;
        break;
      }
      // if ( (*temp).getNumber() > seekid ) break;
      temp = (*temp).getnextWood();
    }
    if (seekwood == NULL) return;

    WOOD_CLASS* newWood = new WOOD_CLASS(*seekwood);
    (*newWood).setGarden(this);

    if (maxid + 1 == woods) {
      // WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, NULL, lastWood, this, maxid + 1, 0 );
      (*newWood).setnextWood(NULL);
      (*newWood).setprevWood(lastWood);
      (*newWood).setNumber(maxid + 1);

      (*lastWood).setnextWood(newWood);
      lastWood = newWood;
      maxid = (*lastWood).getNumber();
    } else if ((*firstWood).getNumber() != 0) {
      // WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, firstWood, NULL, this, 0, 0);
      (*newWood).setnextWood(firstWood);
      (*newWood).setprevWood(NULL);
      (*newWood).setNumber(0);
      (*firstWood).setprevWood(newWood);
      firstWood = newWood;
    } else {
      /**/
      // znalezienie miejsca do wstawienia
      // throw 3;
      WOOD_CLASS* temp = firstWood;
      while (temp != NULL) {
        if ((*temp).getnextWood() != NULL && (*temp).getNumber() + 1 < (*(*temp).getnextWood()).getNumber()) {
          WOOD_CLASS* right = (*temp).getnextWood();
          // WOOD_CLASS* newWood = new WOOD_CLASS(NULL, NULL, right, temp, this, (*temp).getNumber() + 1, 0);
          (*newWood).setnextWood(right);
          (*newWood).setprevWood(temp);
          (*newWood).setNumber((*temp).getNumber() + 1);

          if (temp != NULL) (*temp).setnextWood(newWood);
          if (right != NULL) (*right).setprevWood(newWood);
          break;
        }
        temp = (*temp).getnextWood();
      }
      /**/
    }
    maxid = (*lastWood).getNumber();
    woods++;

    /*if ( maxid + 1 == woods ) {
            (*newWood).setprevWood(lastWood);
            (*lastWood).setnextWood(newWood);
            lastWood = newWood;
            (*lastWood).setNumber(maxid+1);
            maxid++;
            cloned = true;
    }
    else {
            if ( woods == 1 ) {
                    if ( (*firstWood).getNumber() == 0 ) {
                            (*firstWood).setnextWood(newWood);
                            (*newWood).setprevWood(firstWood);
                            (*newWood).setNumber(1);
                            lastWood = newWood;
                            cloned = true;
                            maxid = 1;
                    }
                    else {
                            (*newWood).setnextWood(firstWood);
                            (*newWood).setNumber(0);
                            (*firstWood).setprevWood(newWood);
                            firstWood = newWood;
                            cloned = true;
                    }
            }
            else if ( (*firstWood).getNumber() != 0 ) {
                    (*newWood).setnextWood(firstWood);
                    (*newWood).setNumber(0);
                    (*firstWood).setprevWood(newWood);
                    firstWood = newWood;
                    cloned = true;
            }
            else {
                    //znalezienie miejsca do wstawienia
                    WOOD_CLASS* temp = firstWood;
                    while ( temp != NULL ) {
                            if ( (*temp).getnextWood()!= NULL && (*temp).getNumber() + 1 < (*(*temp).getnextWood()).getNumber() ) {
                                    WOOD_CLASS* right = (*temp).getnextWood();
                                    (*newWood).setNumber((*temp).getNumber() + 1);
                                    (*newWood).setnextWood(right);
                                    (*newWood).setprevWood(temp);
                                    (*temp).setnextWood(newWood);
                                    (*right).setprevWood(newWood);
                                    cloned = true;
                                    break;
                            }
                            temp = (*temp).getnextWood();
                    }
            }
    }

    if (cloned) woods++;*/
  }

  WOOD_CLASS* getWoodPointer(unsigned int num) {
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      if ((*wood).getNumber() == num) return wood;
      if ((*wood).getNumber() > num) return NULL;
      wood = (*wood).getnextWood();
    }
    return NULL;
  }

  void showGarden() {
    cout << "woods: " << woods << endl
         << "maxid: " << maxid << endl;
    WOOD_CLASS* wood = firstWood;
    while (wood != NULL) {
      cout << (*wood).getNumber() << ":" << (*wood).getHeight() << "\nDRZEWO-----\n";
      BRANCH_CLASS* branch = (*wood).getfirstBranch();
      while (branch != NULL) {
        cout << "	" << (*branch).getHeight() << ":" << (*branch).getLength() << "   Galaz----\n";
        FRUIT_CLASS* fruit = (*branch).getFirstFruit();
        while (fruit != NULL) {
          cout << "-(" << (*fruit).getLength() << "-" << (*fruit).getWeight() << ")";
          fruit = (*fruit).getnextFruit();
        }
        cout << "\n   Koniec-Galaz-----\n";
        branch = (*branch).getnextBranch();
      }
      cout << "KONIEC-DRZEWO-----\n";
      wood = (*wood).getnextWood();
    }
    cout << endl
         << endl
         << endl
         << endl;
  }
};

/*
int main () {

        GARDEN_CLASS garden = GARDEN_CLASS();
        garden.plantWood();
        garden.plantWood();
        garden.plantWood();
        garden.plantWood();
        garden.plantWood();
        garden.plantWood();
        garden.plantWood();
        garden.growthGarden();
        garden.growthGarden();
        garden.growthGarden();
        garden.growthGarden();

        garden.extractWood(0);

        garden.showGarden();

        garden.cloneWood(1);

        garden.showGarden();

        garden.extractWood(3);

        garden.cloneWood(1);



return 0;

}
*/