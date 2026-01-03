#include "model.h"

void Model::add_el_data(int a) { Data.push_back(a); }

void Model::add_data(std::vector<int> a) { Data = a; }

int Model::get_el_data(int i) { return Data[i]; }

std::vector<int> Model::get_data() { return Data; }
