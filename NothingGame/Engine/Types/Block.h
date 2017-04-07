//
// Created by Mateusz Pelka on 07.04.2017.
//

#ifndef NOTHINGGAME_BLOCK_H
#define NOTHINGGAME_BLOCK_H


class Block {
private:
    /**
     * 0 - noncolliding
     * 1 - colliding
     * 2 - noncolliding but breakable
     * 3 - colliging and breakable
     * 4 - unbreakable and noncolliding
     * 5 - unbreakable and colliding
     * 6 - untouchable
     * 7 - water
     */
    int type;
    int lifetime;
    int count;
    int blockID;
};


#endif //NOTHINGGAME_BLOCK_H
