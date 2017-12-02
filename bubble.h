#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble::build(const vector <int> & data)
{
	sorted = data;

	int sw = 1;

	//if sw == 0, means the list is sorted
	while(sw == 1)
	{
		sw = 0; int swap;
		for (int j = 0; j < sorted.size()-1; j++)
		{
			if(sorted[j] > sorted[j + 1])
			{
				swap = sorted[j + 1];
				sorted[j + 1] = sorted[j];
				sorted[j] = swap;
				sw = 1;
			}
		}
	}

}

void bubble::destroy_tree()
{
  vector <int > empty_vec;
  sorted.swap( empty_vec );
}

void bubble::insert(int key)
{
	for(int i = 0; i < sorted.size(); i++)
	{
		if(key <= sorted[i])
		{
			sorted.insert(sorted.begin() + i, key);
			break;
		}
	}
}

void bubble::remove(int key)
{
	for(int i = 0; i < sorted.size(); i++)
	{
		if(key == sorted[i])
		{
			sorted.erase(sorted.begin() + i);
			break;
		}
	}
}

void bubble::search_key(int key)
{

	auto it = find (sorted.begin(), sorted.end(), key);

	if (it != sorted.end())
	{
		cout << "Found " << *it << endl;
	}
	else
	{
		cout << "No Match" << endl;
	}

}

void bubble::printOrder()
{
	for(int i = 0; i < sorted.size(); i++)
	{
		cout << sorted[i] << " ";
	}
	cout << endl;
}

void bubble::printQuiet()
{
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i];
	}
}

bool bubble::check_sorted()
{
	bool b1 = true;

	for(int i = 0; i < sorted.size()-1; i++)
	{
		if(sorted[i] > sorted[i+1]){return false;}
	}

	return b1;
}











