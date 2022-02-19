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
#include<set>
#include<map>
#include"Graph/dfs_bfs.h"
#include"Graph/connected_components.h"
#include"Graph/minimal_distancei_inGraph.h"
#include"Graph/topological_sort.h"
#include"Graph/strongly_connected_components.h"
#include"Graph/dijkstra.h"
#include"Graph/floyd_warshal.h"
#include"Graph/eulerPathandCicle.h"
#include"Containers/set.h"
#include"Sort/sort.h"
#include"Graph/minimumSpanningTree.h"




void dijkstra(std::vector<std::vector<std::pair<int, int>>>& v, int start) {
	std::vector<int> distance(v.size(), 100000);
	distance[start] = 0;
	std::set<std::pair<int, int>> s;
	s.insert({ 0,start });
	while (!s.empty()) {
		int current_vertex = s.begin()->second;
		s.erase(s.begin());
		for (int i{}; i != v[current_vertex].size(); ++i) {
			int adjacent_vertex = v[current_vertex][i].first;
			int weight = v[current_vertex][i].second;
			if (distance[current_vertex] + weight < distance[adjacent_vertex]) {
				s.erase({ distance[adjacent_vertex],adjacent_vertex });
				distance[adjacent_vertex] = distance[current_vertex] + weight;
				s.insert({ distance[adjacent_vertex],adjacent_vertex });

			}
		}
	}

	for (const auto& i : distance) {
		std::cout << i << "  ";
	}

}

void floyd_warshall(std::vector<std::vector<int>> graph) {

	for (int k{}; k < graph.size(); ++k) {
		for (int i{}; i < graph.size(); ++i) {
			for (int j{}; j < graph.size(); ++j) {
				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i{}; i != graph.size(); ++i) {
		for (int j{}; j != graph.size(); ++j) {
			if (i == j) {
				std::cout << "0" << " ";
			}
			else {
				std::cout << graph[i][j] << " ";
			}
		}
		std::cout << "\n";
	}

}

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(a > b ? a : b) {
	return a > b ? a : b;
}


void dfs(std::vector<std::vector<int>>& graph,
	std::map<std::pair<int, int>, int>& edges,
	std::vector<int>& cycles, const int& start_vertex) {


	for (int i{}; i != graph[start_vertex].size(); ++i) {
		int adjacent_vertex = graph[start_vertex][i];
		int a = start_vertex;
		int b = adjacent_vertex;
		if (a > b)
			std::swap(a, b);
		if (edges[{a, b}] != 0) {
			edges[{a, b}]--;
			dfs(graph, edges, cycles, adjacent_vertex);
		}
	}
	cycles.push_back(start_vertex);
}




int main() {





	//std::vector<std::vector<int>> v{
	//	{1,3,4},
	//	{0,2,3},
	//	{1,3,4},
	//	{0,1,2,4,5},
	//	{0,3,5},
	//	{2,3,4}
	//};

	//std::vector<std::vector<int>> vm{
	//	{0,1,0,1,1,0},
	//	{1,0,1,1,0,0},
	//	{0,1,0,1,0,1},
	//	{1,1,1,1,1,1},
	//	{1,0,0,1,0,1},
	//	{0,0,1,1,1,0}
	//};

	//std::vector<std::vector<int>>cgr{
	//	{4,5},
	//	{3},
	//	{3},
	//	{1,2,9},
	//	{},
	//	{},
	//	{},
	//	{8},
	//	{7},
	//	{3}
	//};

	//std::vector<std::vector<int>> graph{
	//   {1, 2},
	//   {0, 3, 6},
	//   {0, 3},
	//   {1, 2, 4, 5, 6},
	//   {3, 7},
	//   {3, 7},
	//   {1, 3, 7},
	//   {4, 5, 6, 8},
	//   {7}
	//};

	//std::vector<std::vector<int>> top_graph{
	//	{4},
	//	{0},
	//	{0,1,4},
	//	{1,2},
	//	{},
	//};



	//std::vector<std::vector<int>> stcgraph{
	//	{2},
	//	{0,2},
	//	{3,4},
	//	{},
	//	{1,8},
	//	{10},
	//	{5},
	//	{1,5},
	//	{9},
	//	{8},
	//	{6,7}
	//};

	//std::vector<std::vector<std::pair<int, int>>> dgraph{
	//	{{1,10},{5,5}},
	//	{{0,10},{2,1}},
	//	{{1,1},{3,5},{5,7},{6,10}},
	//	{{2,5},{4,1}},
	//	{{3,1},{6,2}},
	//	{{0,5},{2,7},{6,100},{7,3}},
	//	{{2,10},{4,2},{5,100},{7,8},{8,100}},
	//	{{5,3},{6,8},{9,1}},
	//	{{6,100},{9,1}},
	//	{{7,1},{8,1}},
	//};
	//const int inf = 1e9 + 7;
	//std::vector<std::vector<int>> fmgraph(dgraph.size(), std::vector<int>(dgraph.size(), inf));

	//for (int i{}; i != dgraph.size(); ++i) {
	//	for (int j{}; j != dgraph[i].size(); ++j) {
	//		fmgraph[i][dgraph[i][j].first] = dgraph[i][j].second;
	//		fmgraph[dgraph[i][j].first][i] = dgraph[i][j].second;
	//	}
	//}

	//for (int i{}; i < dgraph.size(); ++i) {
	//	std_my::dijkstra(dgraph, i);
	//	std::cout << "\n";
	//}
	//std::cout << "\n\n";
	////floyd_warshall(fmgraph);

	//std_my::floyd_warshal(fmgraph);


	//  std_my::dijkstra(dgraph, 0);	

	//	std_my::minimal_distance_graphe(graph, 0);

	//	std_my::topological_sort(top_graph);

	//	std_my::connected_components(cgr);

	//	std_my::topological_sort(top_graph);

	//	std_my::strongly_connected_components(stcgraph);

	/*std::vector<std::vector<int>> graph{
	   {1, 3, 4},
	   {0, 2, 3, 4},
	   {1, 3},
	   {0, 1, 2, 4},
	   {0, 1, 3},
	};

	std_my::EulerPathandCycle(graph, 0);*/

	/* std::vector<int> v{ 9,10, 4,12,11, 8,20,19, 5, 3,13, 1,15,18, 7, 6,17,14,16, 2 };

	 std_my::buble_sort_iter(v.begin(), v.end());


	 for (const auto& i : v) {
		 std::cout << i << " ";
	 }
	 std::cin.get();*/

	// //Minimum Spanning tree example edges
	//std::vector<std_my::edge> edges{
	//	{1, 2, 5},
	//	{1, 3, 9},
	//	{1, 5, 1},
	//	{1, 6, 3},
	//	{2, 4, 8},
	//	{2, 6, 3},
	//	{3, 5, 4},
	//	{4, 6, 7},
	//	{5, 6, 2},
	//};

	//std_my::minimumpSpanningTree(edges);


	std::getchar();
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


