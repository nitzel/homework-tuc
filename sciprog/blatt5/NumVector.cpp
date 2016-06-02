/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file NumVector.cpp
 * @desc Homework Blatt5.2 for SciProg
 * NumVector mit eigenen exceptions
 *
 * Für die exceptions und generell Vererbung muss es doch eine bessere
 * Möglichkeit geben, den Base-CTor nach der Konstruktion von zu übergebenden
 * Prametern aufzurufen. So, wie es hier gemacht wird, ist das nicht schön.
 * Also erst die Parameter berechnen, und dann die Base Klasse damit initialisieren.
 * Anstatt wie hier die DerivedClass in ihrem CTor mit einer BaseClass
 * zu überschreiben ... Ja, ist nicht schön - aber selten.
 */
#include<iostream>
#include<sstream>
#include<cmath>
#include<vector>
#include<stdexcept>


class NumVector{
public:
  // internal exception classes
  struct OutOfRangeException : public std::logic_error {
    OutOfRangeException(int index, int maxIndex) : std::logic_error("grr"){
      std::ostringstream tmp;
      tmp << "NumVector Index " << index << " out of Range [0," << maxIndex << ")";
      std::logic_error err(tmp.str().c_str());
      *this = *reinterpret_cast<OutOfRangeException*>(&err);
    }
  };
  struct IncompatibleDimensionsException : public std::logic_error {
    IncompatibleDimensionsException(int dimA, int dimB) : std::logic_error("grrr"){
      std::ostringstream tmp;
      tmp << "NumVectors have incompatible dimensions " << dimA << " and " << dimB << ".";
      std::logic_error err(tmp.str().c_str());
      *this = *reinterpret_cast<IncompatibleDimensionsException*>(&err);
    }
  };
  // NumVector
  NumVector(size_t size);
  size_t size() const {return data.size();}
  double norm() const;
  double operator* (const NumVector &v) const throw(IncompatibleDimensionsException);
  double& operator[] (size_t index) throw(OutOfRangeException);
  double operator[] (size_t index) const throw(OutOfRangeException);
private:
  std::vector<double> data;
};

int main(){
  try{
    NumVector v(3);
    v[0]=1; v[1]=3, v[2]=4;
    NumVector v2(3);
    v2[0]=4; v2[1]=6, v2[2]=9;
    std::cout<<"norm(v1) is "<<v.norm()<<std::endl;
    std::cout<<"norm(v2) is "<<v2.norm()<<std::endl;
    std::cout<<"vector1 is ["<<v[0]<<", "<<v[1]<<", "<<v[2]<<"]"<<std::endl;
    std::cout<<"vector1 is ["<<v2[0]<<", "<<v2[1]<<", "<<v2[2]<<"]"<<std::endl;

    std::cout<<"v1*v2 is "<< v*v2 << std::endl;
    std::cout<<"v2*v2 is "<< v2*v2 << std::endl;
    std::cout<<"sqrt(v2*v2) is its norm: "<< sqrt(v2*v2) << std::endl;

    v[5]; // OutOfRangeException
    v*NumVector(4); // IncompatibleDimensionsException
  }catch(std::logic_error exc){
    std::cout << "Error: " << exc.what() << std::endl;
  }
}

NumVector::NumVector(size_t size){
  data = std::vector<double>(size);
  for(double &d : data) d = 0; // init with 0
}
double NumVector::norm() const{
  double squared_norm = 0;
  for(double d : data) squared_norm += pow(d,2);
  return sqrt(squared_norm);
}
double NumVector::operator* (const NumVector &v) const throw(IncompatibleDimensionsException){
  if(size() != v.size())
    throw IncompatibleDimensionsException(size(), v.size());
  double scalarProduct = 0;
  for(size_t i = 0; i < size(); ++i) {
    scalarProduct += (*this)[i] * v[i];
  }
  return scalarProduct;
}
double& NumVector::operator[](size_t index) throw(OutOfRangeException){
  try{
    return data.at(index);
  } catch(...){
    throw OutOfRangeException(index, data.size());

  }
}
double NumVector::operator[](size_t index) const throw(OutOfRangeException){
  try{
    return data.at(index);
  } catch(...){
    throw OutOfRangeException(index, data.size());
  }
}
