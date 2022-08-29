

#include "fatsim.h"
#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

std::vector<long> fat_check(const std::vector<long> & fat){

  std::vector<std::vector<long>> adj_list(fat.size());
  std::vector<long> end_chain_indices;
  std::vector<long> results;

  for(int i =0; i<(int)fat.size();i++){
    if(fat[i]!=-1) adj_list[fat[i]].push_back(i);
    else end_chain_indices.push_back(i);
  }

  for(int i =0; i<(int)end_chain_indices.size();i++){

    std::vector<long> distances(fat.size(),0);
    std::vector<bool> visited(fat.size(),false);
    std::vector<long> stack;
    std::vector<long> pred(fat.size());

    stack.push_back(end_chain_indices[i]);
    while(!stack.empty()){
      long current = stack.back();
      stack.pop_back();
      if(!visited[current]){
        visited[current] = true;
        if(current == end_chain_indices[i]) distances[current] = 1;
        else distances[current] = distances[pred[current]] + 1 ;
      }
      if(!adj_list[current].empty()){
        for (auto i = adj_list[current].begin(); i != adj_list[current].end(); ++i){
          if (!visited[*i]){ 
            pred[*i] = current;
            stack.push_back(*i);
          }
        }  
      }              
    }
    int max_chain = *max_element(distances.begin(), distances.end());
    results.push_back(max_chain);
  }
  std::sort(results.begin(), results.end());
  return results;
}

