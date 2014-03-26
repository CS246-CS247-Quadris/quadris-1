#ifndef __IBLOCK_H__
#define __IBLOCK_H__


class iBlock : public Block {

  Cell cells[4][4];

 public:
  iBlock();
  ~iBlock();
  virtual void rotateCCW();
  virtual void rotateCW();
	

};
#endif
