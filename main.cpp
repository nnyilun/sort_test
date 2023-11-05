#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "sort_function.h"
#include "Timer.h"
constexpr int SIZE = 10000;
constexpr int TIMES = 5;

int main() {
	std::vector<double> t(TIMES);
	std::vector<std::vector<double>> time_usage(10, t);

	std::fstream input("input.txt", std::ios::in|std::ios::out);
	std::ofstream out("result.txt", std::ios::out);

	std::cout << "Generating random number..." << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE && i == 3; ++j) {
			input << std::setw(6) << 10;
		}
		for (int j = 0; j < SIZE && i == 4; ++j) {
			input << std::setw(6) << SIZE - j;
		}
		for (int j = 0; j < SIZE && i != 3 && i != 4; ++j) {
			input << std::setw(6) << rand();
		}
		input << std::endl;
	}
	std::cout << "Generated random number successfully!" << std::endl;

	
	int** num = nullptr;

	num = new int*[TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "BubbleSort_Raw...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			BubbleSort_Raw(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[0][i] = temp;
		}
	}
	std::cout << "BubbleSort_Raw done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete[] num[i];
	}
	delete[] num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "BubbleSort_Optimized...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			BubbleSort_Optimized(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[1][i] = temp;
		}
	}
	std::cout << "BubbleSort_Optimized done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "insertion_sort...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			insertion_sort(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[2][i] = temp;
		}
	}
	std::cout << "insertion_sort done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "merge_sort...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			merge_sort(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[3][i] = temp;
		}
	}
	std::cout << "merge_sort done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "merge_sort_BU...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			merge_sort_BU(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[4][i] = temp;
		}
	}
	std::cout << "merge_sort_BU done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "quicksort...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			quicksort(num[i], 0, SIZE - 1, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[5][i] = temp;
		}
	}
	std::cout << "quicksort done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "quicksort_3way...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			if (i == 4)continue;
			quicksort_3way(num[i], 0, SIZE - 1, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[6][i] = temp;
		}
	}
	std::cout << "quicksort_3way done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "selection_sort...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			selection_sort(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[7][i] = temp;
		}
	}
	std::cout << "selection_sort done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "shell_sort...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			shell_sort(num[i], SIZE, 0);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[8][i] = temp;
		}
	}
	std::cout << "shell_sort done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;



	num = new int* [TIMES];
	for (int i = 0; i < TIMES; ++i) {
		num[i] = new int[SIZE];
	}
	input.seekg(0);
	input.seekp(0);
	for (int i = 0; i < TIMES; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			input >> num[i][j];
		}
	}

	std::cout << "sort()...\n";
	{
		Timer timer;
		for (int i = 0; i < TIMES; ++i) {
			std::sort(num[i], num[i] + SIZE);
			double temp = timer.breakpoint() * 0.001;
			std::cout << "times: " << i + 1 << "\tUsage time: " << temp << "ms" << std::endl;
			time_usage[9][i] = temp;
		}
	}
	std::cout << "sort() done!\n\n";

	for (int i = 0; i < TIMES; ++i) {
		delete num[i];
	}
	delete[]num;


	out << "sort method         \t" << "   1       2       3      same  inverted\t   total\n";

	out << "BubbleSort_Raw      \t";
	double total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[0][i];
		out << std::setw(8) << time_usage[0][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "BubbleSort_Optimized\t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[1][i];
		out << std::setw(8) << time_usage[1][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "insertion_sort      \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[2][i];
		out << std::setw(8) << time_usage[2][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "merge_sort          \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[3][i];
		out << std::setw(8) << time_usage[3][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "merge_sort_3U       \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[4][i];
		out << std::setw(8) << time_usage[4][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "quicksort           \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[5][i];
		out << std::setw(8) << time_usage[5][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "quicksort_3way      \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[6][i];
		out << std::setw(8) << time_usage[6][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "selection_sort      \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[7][i];
		out << std::setw(8) << time_usage[7][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "shell_sort          \t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[8][i];
		out << std::setw(8) << time_usage[8][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	out << "sort() function(STL)\t";
	total = 0;
	for (int i = 0; i < TIMES; ++i) {
		total += time_usage[9][i];
		out << std::setw(8) << time_usage[9][i];
	}
	out << "\t" << std::setw(8) << total << "\n";

	input.close();
	out.close();

	return 0;
}
