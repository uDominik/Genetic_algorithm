#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <memory>
#include <string>

class Solution
{
public:
  virtual ~Solution() { };
  // Solution(Solution const &) = delete;
  // Solution & operator=(Solution const &) = delete;

  virtual double CalcRank() = 0;
  virtual void Mute() = 0;
  virtual std::shared_ptr<Solution> Cross(const std::shared_ptr<Solution> apSolution) = 0;

  virtual std::string PrintSolution() = 0;

protected:
  Solution() { }
};

#endif