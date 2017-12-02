#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <algorithm>
#include "binary_headers.h"
#include "binary-tree.h"
#include "bubble.h"
#include "quick.h"
#include "merge.h"

using namespace std;

//user can set this number to decide how large of a dataset they want to sort
int size_set = 100000;

//this function does a performance check on the sorted data type
//the class sorts is the abstract base class
//currently, the derived classes include:
//binary tree, quick_sort, merge_sort, and bubble sort
//the file "binary_headers.h" contains the class definitions
void time_stamps(const unique_ptr <sorts> & sort_type, const vector <int> & pass_data);

int main()
{

  vector <int> pass_data(size_set);

  for(int i = 0; i < size_set; i++)
  {
	  int j = rand() % size_set + 1;
	  pass_data[i] = j;
  }

//limiting the scope will limit memory used in case of really large sets
    {
        unique_ptr <sorts> bin_tree = make_unique <btree>();

        cout << "Binary Tree Stats:" << endl;
        cout << endl;
        time_stamps(bin_tree,pass_data);
    }

    {
        unique_ptr <sorts> quicks = make_unique <quick>();

        cout << endl;
        cout << "Quick Stats:" << endl;
        cout << endl;
        time_stamps(quicks,pass_data);
    }

    {
        unique_ptr <sorts> merged = make_unique <_merge>();

        cout << endl;
        cout << "Merge Stats:" << endl;
        cout << endl;
        time_stamps(merged,pass_data);
    }

    {
        unique_ptr <sorts> bubbly = make_unique <bubble>();

        cout << endl;
        cout << "Bubble Stats:" << endl;
        cout << endl;
        time_stamps(bubbly,pass_data);
    }

}

void time_stamps(const unique_ptr <sorts> & sort_type, const vector <int> & pass_data)
{

	auto begin = chrono::high_resolution_clock::now();
    sort_type->build(pass_data);
	auto end = chrono::high_resolution_clock::now();
	double timeSec = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()*1.0e-9;
	cout << "Time to build: " << timeSec << endl;

    cout << "Sorted Correctly?: " << sort_type->check_sorted() << endl;

	begin = chrono::high_resolution_clock::now();
    sort_type->printQuiet();
	end = chrono::high_resolution_clock::now();
	timeSec = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()*1.0e-9;
	cout << "Time to Traverse: " << timeSec << endl;

	int j = rand() % size_set + 1;

	begin = chrono::high_resolution_clock::now();
    sort_type->insert(j);
	end = chrono::high_resolution_clock::now();
	timeSec = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()*1.0e-9;
	cout << "Time to Insert new Key: " << timeSec << endl;

	cout << "Sorted Correctly?: " << sort_type->check_sorted() << endl;

	begin = chrono::high_resolution_clock::now();
    sort_type->search_key(j);
	end = chrono::high_resolution_clock::now();
	timeSec = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()*1.0e-9;
	cout << "Time to Search Key: " << timeSec << endl;

	begin = chrono::high_resolution_clock::now();
    sort_type->remove(j);
	end = chrono::high_resolution_clock::now();
	timeSec = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()*1.0e-9;
	cout << "Time to Remove Key: " << timeSec << endl;

	cout << "Sorted Correctly?: " << sort_type->check_sorted() << endl;

}

















