#include<iostream>
#include<cmath>
#include<vector>
#include <stdexcept>

class NumVector : private std::vector<double>{
public:
  NumVector(size_t size);
  double norm() const;
  double& operator[] (size_t index);
  const double& operator[] (size_t index) const;
};

int main(){
  try{
    NumVector v(3);
    v[0]=1; v[1]=3, v[2]=4;
    const NumVector& w=v;
    std::cout<<"norm is "<<w.norm()<<std::endl;
    std::cout<<"vector is ["<<w[0]<<", "<<w[1]<<", "<<w[2]<<"]"<<std::endl;
  }catch(std::out_of_range error){
    std::cout << "Error: " << error.what() << std::endl;
  }
}

NumVector::NumVector(size_t size) : std::vector<double>(size){
  for(double &d : *this) d = 0; // init with 0
}
double NumVector::norm() const{
  double squared_norm = 0;
  for(double d : *this) squared_norm += pow(d,2);
  return sqrt(squared_norm);
}
double& NumVector::operator[](size_t index){
  return this->at(index);
}
const double& NumVector::operator[](size_t index) const{
  return this->at(index);
}
