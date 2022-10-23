#include "math.h"
#include <array>
#include <chrono>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
using namespace std;
typedef pair<int, int> Pair;

typedef tuple<double, int, int> Tuple;

struct cell {
    Pair parent; 
    double f, g, h;
	cell()
		: parent(-1, -1)
		, f(-1)
		, g(-1)
		, h(-1)
	{
	}
};

template <size_t ROW, size_t COL>
bool isValid(const array<array<int, COL>, ROW>& grid,
			const Pair& point){
	if (ROW > 0 && COL > 0)
		return (point.first >= 0) && (point.first < ROW)
			&& (point.second >= 0)
			&& (point.second < COL);

	return false;
}

template <size_t ROW, size_t COL>
bool isUnBlocked(const array<array<int, COL>, ROW>& grid,
				const Pair& point){
		return isValid(grid, point)
		&& grid[point.first][point.second] == 1;
}

bool isDestination(const Pair& position, const Pair& dest){
	return position == dest;
}

double calculateHValue(const Pair& src, const Pair& dest){
		return sqrt(pow((src.first - dest.first), 2.0)
				+ pow((src.second - dest.second), 2.0));
}

template <size_t ROW, size_t COL>
void tracePath(
	const array<array<cell, COL>, ROW>& cellDetails,
	const Pair& dest){
	printf("\nThe Path is ");

	stack<Pair> Path;

	int row = dest.first;
	int col = dest.second;
	Pair next_node = cellDetails[row][col].parent;
	do {
		Path.push(next_node);
		next_node = cellDetails[row][col].parent;
		row = next_node.first;
		col = next_node.second;
	} while (cellDetails[row][col].parent != next_node);

	Path.emplace(row, col);
	while (!Path.empty()) {
		Pair p = Path.top();
		Path.pop();
		printf("-> (%d,%d) ", p.first, p.second);
	}
}

template <size_t ROW, size_t COL>
void aStarSearch(const array<array<int, COL>, ROW>& grid,
				const Pair& src, const Pair& dest){
	if (!isValid(grid, src)) {
		printf("Source is invalid\n");
		return;
	}

    if (!isValid(grid, dest)) {
		printf("Destination is invalid\n");
		return;
	}

    if (!isUnBlocked(grid, src)
		|| !isUnBlocked(grid, dest)) {
		printf("Source or the destination is blocked\n");
		return;
	}
	if (isDestination(src, dest)) {
		printf("We are already at the destination\n");
		return;
	}
	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));
	array<array<cell, COL>, ROW> cellDetails;

	int i, j;

	i = src.first, j = src.second;
	cellDetails[i][j].f = 0.0;
	cellDetails[i][j].g = 0.0;
	cellDetails[i][j].h = 0.0;
	cellDetails[i][j].parent = { i, j };

		std::priority_queue<Tuple, std::vector<Tuple>,
						std::greater<Tuple> >
		openList;
	openList.emplace(0.0, i, j);

    while (!openList.empty()) {
		const Tuple& p = openList.top();
        i = get<1>(p); 
		j = get<2>(p); 
		
		openList.pop();
		closedList[i][j] = true;
        for (int add_x = -1; add_x <= 1; add_x++) {
            for (int add_y = -1; add_y <= 1; add_y++) {
				Pair neighbour(i + add_x, j + add_y);
				
				if (isValid(grid, neighbour)) {
					
			        if (isDestination( neighbour,dest)) { 
						cellDetails[neighbour.first]
								[neighbour.second]
									.parent
							= { i, j };
						printf("The destination cell is "
							"found\n");
						tracePath(cellDetails, dest);
						return;
					}
                    else if (!closedList[neighbour.first]
										[neighbour.second]
							&& isUnBlocked(grid,
											neighbour)) {
						double gNew, hNew, fNew;
						gNew = cellDetails[i][j].g + 1.0;
						hNew = calculateHValue(neighbour,
											dest);
						fNew = gNew + hNew;
						if (cellDetails[neighbour.first]
									[neighbour.second]
										.f
								== -1
							|| cellDetails[neighbour.first]
										[neighbour.second]
											.f
								> fNew) {
							openList.emplace(
								fNew, neighbour.first,
								neighbour.second);

							
							cellDetails[neighbour.first]
									[neighbour.second]
										.g
								= gNew;
							cellDetails[neighbour.first]
									[neighbour.second]
										.h
								= hNew;
							cellDetails[neighbour.first]
									[neighbour.second]
										.f
								= fNew;
							cellDetails[neighbour.first]
									[neighbour.second]
										.parent
								= { i, j };
						}
					}
				}
			}
		}
	}

	printf("Failed to find the Destination Cell\n");
}

int main(){
		array<array<int, 10>, 9> grid{
		{ { { 1, 0, 0, 1, 1, 1, 0, 1, 0, 1 } },
		{ { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 } },
		{ { 1, 1, 1, 0, 1, 1, 0, 1, 0, 0 } },
		{ { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 } },
		{ { 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 } },
		{ { 1, 0, 1, 1, 1, 1, 1, 0, 0, 0 } },
		{ { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 } },
		{ { 1, 0, 0, 1, 1, 1, 0, 1, 1, 1 } },
		{ { 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 } } }
	};

		Pair src(8, 0);

		Pair dest(0, 0);

	aStarSearch(grid, src, dest);

	return 0;
}
