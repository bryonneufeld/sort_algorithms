#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick::build(const vector <int> & data)
{
	sorted = quicksort(data);
}

vector <int> quick::quicksort(const vector <int> & b)
{

	if(b.size() <= 1)
	{
		return b;
	}

	int half = floor(b.size()/2);
	int length = b.size();
	int middle = b.at(half);

	vector <int> left(0);
	vector <int> right(0);

	for(int i = 0; (i < length); i++)
	{
		if(b.at(i) > middle && (i != half))
		{
			right.push_back(b.at(i));
		}
		else if(b.at(i) <= middle && (i != half))
		{
			left.push_back(b.at(i));
		}
	}

	vector <int> con1(quicksort(left));
	vector <int> con2(quicksort(right));
	vector <int> data(0);

	data.insert(data.end(), con1.begin(), con1.end());
	data.push_back(middle);
	data.insert(data.end(), con2.begin(), con2.end());

	return data;
}


void quick::destroy_tree()
{
  vector <int > empty_vec;
  sorted.swap( empty_vec );
}

void quick::insert(int key)
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

void quick::remove(int key)
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

void quick::search_key(int key)
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

void quick::printOrder()
{
	for(int i = 0; i < sorted.size(); i++)
	{
		cout << sorted[i] << " ";
	}
	cout << endl;
}

void quick::printQuiet()
{
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i];
	}
}

bool quick::check_sorted()
{
	bool b1 = true;

	for(int i = 0; i < sorted.size()-1; i++)
	{
		if(sorted[i] > sorted[i+1]){return false;}
	}

	return b1;
}











