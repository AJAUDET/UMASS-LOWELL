#pragma once

class Player
{
 public:
  virtual int getGuess() = 0;
  virtual void feedback(bool tooH, bool tooL) {}
  virtual ~Player() = default;
};

class HumanPlayer : public Player
{
 private:
  int guess;

 public:
  int getGuess() override;
};

class ComputerPlayer : public Player
{
 private:
  int low;
  int high;
  int prevGuess;

 public:
  ComputerPlayer();
  int getGuess() override;
  void feedback(bool tooH, bool tooL) override;
};
