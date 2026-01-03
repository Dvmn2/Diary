#pragma once

#include <vector>

class Model {
   private:
    std::vector<int> Data = {};

   public:
    void add_el_data(int a);
    void add_data(std::vector<int> a);
    int get_el_data(int i);
    std::vector<int> get_data();
};
