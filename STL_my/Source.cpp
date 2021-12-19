#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<type_traits>
#include<queue>
#include<filesystem>
#include<fstream>
#include<regex>
#include<mutex>
#include<direct.h>
#include <locale>
#include <codecvt>
#include<regex>
#include<TCHAR.H> 
#include<time.h>
#include <chrono>
#include<stack>
#include<io.h>
#include"Graph/dfs_bfs.h"
#include"Graph/connected_components.h"
#include"Graph/minimal_distancei_inGraph.h"
#include"Graph/topological_sort.h"
#include"Graph/strongly_connected_components.h"

void bfs(std::vector<std::vector<int>>& v, int start) {
	std::vector<int> used(v.size(), -1);
	used[start] = 0;
	std::queue<int> q;
	q.push(start);
	std::vector<int> distance(v.size());
	while (!q.empty()) {
		int current_vertex = q.front();
		q.pop();
		for (int i{}; i != v[current_vertex].size(); ++i) {
			int adjacent_vertex = v[current_vertex][i];
			if (used[adjacent_vertex] == -1) {
				q.push(adjacent_vertex);
				used[adjacent_vertex] = used[current_vertex] + 1;

			}
		}
	}

	for (const auto& i : used) {
		std::cout << i << "  ";
	}

}









int main() {

	std::vector<std::vector<int>> v{
		{1,3,4},
		{0,2,3},
		{1,3,4},
		{0,1,2,4,5},
		{0,3,5},
		{2,3,4}
	};

	std::vector<std::vector<int>> vm{
		{0,1,0,1,1,0},
		{1,0,1,1,0,0},
		{0,1,0,1,0,1},
		{1,1,1,1,1,1},
		{1,0,0,1,0,1},
		{0,0,1,1,1,0}
	};

	std::vector<std::vector<int>>cgr{
		{4,5},
		{3},
		{3},
		{1,2,9},
		{},
		{},
		{},
		{8},
		{7},
		{3}
	};

	std::vector<std::vector<int>> graph{
	   {1, 2},
	   {0, 3, 6},
	   {0, 3},
	   {1, 2, 4, 5, 6},
	   {3, 7},
	   {3, 7},
	   {1, 3, 7},
	   {4, 5, 6, 8},
	   {7}
	};

	std::vector<std::vector<int>> top_graph{
		{4},
		{0},
		{0,1,4},
		{1,2},
		{},
	};



	std::vector<std::vector<int>> stcgraph{
		{2},
		{0,2},
		{3,4},
		{},
		{1,8},
		{10},
		{5},
		{1,5},
		{9},
		{8},
		{6,7}
	};



	//	std_my::minimal_distance_graphe(graph, 0);

	//	std_my::topological_sort(top_graph);

	//	std_my::connected_components(cgr);

	//	std_my::topological_sort(top_graph);

		std_my::strongly_connected_components(stcgraph);


	std::cin.get();
	return {};
}



//
//
//int main() {
//	std::vector<int> v{ 9,10, 4,12,11, 8,20,19, 5, 3,13, 1,15,18, 7, 6,17,14,16, 2 };
//	int l[]{ 9,10, 4,12,11, 8,20,19, 5, 3,13, 1,15,18, 7, 6,17,14,16, 2 };
//	std::vector<int> ra{ 415, 993, 404, 830, 843, 536, 551, 220, 778, 289, 111, 960, 465, 223, 695 };
//
//	std::cout << "\n\n\n\n\n";
//	std::cout << "\n\n";
//
//
//
//
//	std::getchar();
//	return 0;
//}


