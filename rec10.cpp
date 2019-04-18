#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Unsigned is similar to int.

class Instrument {
public:
    virtual void makeSound() = 0;
    virtual void play() const = 0;
};

////////////////////////////////////////////////

class Percussion : public Instrument {
public:
    void makeSound() {
        cout << "To make a sound... hit me!" << endl;
    }
};

class Drum : public Percussion {
public:
    void play() const { cout << "BOOM" << endl;}
};

class Cymbal : public Percussion {
public:
    void play() const { cout << "CRASH" << endl;}
};

////////////////////////////////////////////////

class Brass: public Instrument { // base
public:
    Brass(unsigned mouthPieceSize) : mouthPiece(mouthPieceSize) {}
    void makeSound() {
        cout << "To make a sound... blow on a mouthpiece of size " << mouthPiece << endl;
    }
private:
    unsigned mouthPiece;
};

class Trumpet : public Brass {
public:
    Trumpet(unsigned mouthPieceSize) : Brass(mouthPieceSize) {}
    void play() const { cout << "TOOT" << endl;}

};

class Trombone : public Brass {
public:
    Trombone(unsigned mouthPieceSize) : Brass(mouthPieceSize) {}
    void play() const { cout << "BLAT" << endl;}

};

////////////////////////////////////////////////

class StringInstrument : public Instrument { // Base
public:
    StringInstrument(unsigned aPitch) : pitch(aPitch) {}
    void makeSound() {
        cout << "To make a sound... bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Violin : public StringInstrument {
public:
    Violin(unsigned aPitch) : StringInstrument(aPitch) {}
    void play() const { cout << "SCREECH" << endl;}
};

class Cello : public StringInstrument {
public:
    Cello(unsigned aPitch) : StringInstrument(aPitch) {}
    void play() const { cout << "SQUAWK" << endl;}
};
////////////////////////////////////////////////
class Musician {
public:
    Musician() : instr(nullptr) {}
    
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }
    
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }
    
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    void play() const {
        if (instr) instr->play();
    }
private:
    Instrument* instr;
};
////////////////////////////////////////////////
class MILL {
public:
    bool receiveInstr(Instrument& aInstrument) {
        aInstrument.makeSound();
        if (inventory.size() == 0){
            inventory.push_back(&aInstrument);
            return true;
        }
        else{
            for (size_t i = 0; i < inventory.size(); i++) {
                if (inventory[i] == nullptr){
                    inventory[i] = &aInstrument;
                    return true;
                }
            }
            inventory.push_back(&aInstrument);
            return true;
        }
        return false;
    }
    void dailyTestPlay() const {
        for (size_t i = 0; i < inventory.size(); i++){
            if (inventory[i] != nullptr){
                inventory[i]->makeSound();
            }
        }
    }
    Instrument* loanOut() {
        for (size_t i = 0; i < inventory.size(); i++){
            if (inventory[i] != nullptr){
                Instrument* loanedInstrument = inventory[i];
                inventory[i] = nullptr;
                return loanedInstrument;
            }
        }
        return nullptr;
    }
private:
    vector<Instrument*> inventory;
};

class Orch {
public:
    bool addPlayer(Musician& aMusician) {
        if (orchestra.size() != 25){
            orchestra.push_back(&aMusician);
            return true;
        }
        return false;
    }
    void play() const {
        for (size_t i = 0; i < orchestra.size(); i++){
            orchestra[i]->play();
        }
    }
private:
    vector<Musician*> orchestra;
};


int main() {
//    // Part 2 ///////////////////////////////////////////////
//    Drum drum;
//    Cello cello(673);
//    Cymbal cymbal;
//    Trombone tbone(4);
//    Trumpet trpt(12);
//    Violin violin(567);
//
//    MILL mill;
//    mill.receiveInstr(trpt);
//    mill.receiveInstr(violin);
//    mill.receiveInstr(tbone);
//    mill.receiveInstr(drum);
//    mill.receiveInstr(cello);
//    mill.receiveInstr(cymbal);
//
//    Musician bob;
//    Musician sue;
//    Musician mary;
//    Musician ralph;
//    Musician jody;
//    Musician morgan;
//
//    Orch orch;
//
//    // THE SCENARIO
//
//    //Bob joins the orchestra without an instrument.
//    orch.addPlayer(bob);
//
//    //The orchestra performs
//    cout << "orch performs\n";
//    orch.play();
//
//    //Sue gets an instrument from the MIL2 and joins the orchestra.
//    sue.acceptInstr(mill.loanOut());
//    orch.addPlayer(sue);
//
//    //Ralph gets an instrument from the MIL2.
//    ralph.acceptInstr(mill.loanOut());
//
//    //Mary gets an instrument from the MIL2 and joins the orchestra.
//    mary.acceptInstr(mill.loanOut());
//    orch.addPlayer(mary);
//
//    //Ralph returns his instrument to the MIL2.
//    mill.receiveInstr(*ralph.giveBackInstr());
//
//    //Jody gets an instrument from the MIL2 and joins the orchestra.
//    jody.acceptInstr(mill.loanOut());
//    orch.addPlayer(jody);
//
//    // morgan gets an instrument from the MIL2
//    morgan.acceptInstr(mill.loanOut());
//
//    //The orchestra performs.
//    cout << "orch performs\n";
//    orch.play();
//
//    //Ralph joins the orchestra.
//    orch.addPlayer(ralph);
//
//    //The orchestra performs.
//    cout << "orch performs\n";
//    orch.play();
//
//    // bob gets an instrument from the MIL2
//    bob.acceptInstr(mill.loanOut());
//
//    // ralph gets an instrument from the MIL2
//    ralph.acceptInstr(mill.loanOut());
//
//    //The orchestra performs.
//    cout << "orch performs\n";
//    orch.play();
//
//    //Morgan joins the orchestra.
//    orch.addPlayer(morgan);
//
//    //The orchestra performs.
//    cout << "orch performs\n";
//    orch.play();
         cout << "Define some instruments ----------------------------------------\n";
         Drum drum; // percussion
         Cello cello(673); // string
         Cymbal cymbal;// percussion
         Trombone tbone(4); // Brass
         Trumpet trpt(12) ; // Brass
         Violin violin(567) ; // string
    
         // use the debugger to look at the mill
         cout << "Define the MILL ------------------------------------------------\n";
         MILL mill;
    
         cout << "Put the instruments into the MILL ------------------------------\n";
         mill.receiveInstr(trpt);
         mill.receiveInstr(violin);
         mill.receiveInstr(tbone);
         mill.receiveInstr(drum);
         mill.receiveInstr(cello);
         mill.receiveInstr(cymbal);
    
         cout << "Daily test -----------------------------------------------------\n";
         cout << endl;
         cout << "dailyTestPlay()" << endl;
         mill.dailyTestPlay();
         cout << endl;
    
         cout << "Define some Musicians-------------------------------------------\n";
         Musician harpo;
         Musician groucho;
    
         cout << "TESTING: groucho.acceptInstr(mill.loanOut());-----------------------\n";
         groucho.testPlay();
         cout << endl;
         groucho.acceptInstr(mill.loanOut());
         cout << endl;
         groucho.testPlay();
         cout << endl;
         cout << "dailyTestPlay()" << endl;
         mill.dailyTestPlay();
    
         cout << endl << endl;
    
         groucho.testPlay();
         cout << endl;
         mill.receiveInstr(*groucho.giveBackInstr());
         harpo.acceptInstr(mill.loanOut());
         groucho.acceptInstr(mill.loanOut());
         cout << endl;
         groucho.testPlay();
         cout << endl;
         harpo.testPlay();
         cout << endl;
         cout << "dailyTestPlay()" << endl;
         mill.dailyTestPlay();
    
         cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ----------\n";
    
         // fifth
         mill.receiveInstr(*groucho.giveBackInstr());
         cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
         mill.receiveInstr(*harpo.giveBackInstr());
    
    
         cout << endl;
         cout << "dailyTestPlay()" << endl;
         mill.dailyTestPlay();
         cout << endl;
    
         cout << endl;
}
