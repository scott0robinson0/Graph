#include <iostream>
#include <string>
#include <vector>


std::vector<std::vector<char>> initialise(int width) {
	if (width % 2 == 0) width++;
	
	std::vector<std::vector<char>> graph;

	for (int i = 0; i < width; i++) {
		graph.push_back({});
		for (int j = 0; j < width; j++) {
			int x = -((width - 1) / 2) + j;
			int y = ((width - 1) / 2) - i;

			if (x == 0 || y == 0) {
				graph.at(i).push_back('.');
			}
			else {
				graph.at(i).push_back(' ');
			}

			int expression = pow(x, 3) + 5;

			if (y == expression) {
				graph[i][j] = '0';
			}

			if (-5 <= x && x <= 5 && y > 0 && y < expression)
				graph[i][j] = 'H';
		}
	}

	return graph;
}

void print(std::vector<std::vector<char>> graph) {
	for (const std::vector<char>& row : graph) {
		for (const char& column : row) {
			std::cout << column << ' ';
		}
		std::cout << std::endl;
	}
}


int main()
{
	print(initialise(100));
}