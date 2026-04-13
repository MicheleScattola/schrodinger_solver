#ifndef __SOLVER__
#define __SOLVER__
#include "../external/eigen/Eigen/Dense"


class Solver {

  public:
  Solver();
  Solver(int nSteps, float leftL, float rightL);
  ~Solver();
  void setSteps(int nSteps) {_nSteps = nSteps;};
  void setLeftLim(float leftL) {_leftLimit = leftL;};
  void setRightLim(float rightL) {_rightLimit = rightL;};

  std::pair<Eigen::VectorXf,Eigen::MatrixXf> solve(genericFunction &H, genericFunction &V);
  
  private:
  int _nSteps;
  float _leftLimit;
  float _rightLimit;
};

#endif __SOLVER__