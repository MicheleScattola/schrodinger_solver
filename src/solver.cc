#include "../include/solver.h"
#include "functions.cc"
#include "../external/eigen/Eigen/Dense"

Solver::Solver() {
  _nSteps = 10;
  _leftLimit = -1.;
  _rightLimit = 1.;
}
Solver::Solver(int nSteps, float leftL, float rightL){
  _nSteps = nSteps;
  _leftLimit = leftL;
  _rightLimit = rightL;
}
std::pair<Eigen::VectorXf,Eigen::MatrixXf> Solver::solve(genericFunction &T, genericFunction &V){
  
  int gridStep = std::round((_rightLimit - _leftLimit)/(_nSteps+1));

  // populate hamiltonian matrix
  Eigen::MatrixXf H = Eigen::MatrixXf::Zero(_nSteps,_nSteps);

  for(int i=0;i<H.rows();i++){
    // current evaluation point
    float x = _leftLimit + (i+1)*gridStep;
    // diagonal terms
    H.coeffRef(i,i) = V.evaluate(x)-2.0*T.evaluate(x);
    // off diagonal, takes care of first and last column
    if(i>0){
      H.coeffRef(i,i-1) = T.evaluate(x);
    } else if (i<H.rows()-1){
      H.coeffRef(i,i+1) = V.evaluate(x)-2.0*T.evaluate(x);
    }
  }

  // solve
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXf> solver(H);
}