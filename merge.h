#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void _merge::build(const vector <int> & data)
{
	sorted = mergesort(data);
}

//still working on the mergesort, CONSTRUCTION ZONE!
vector <int> _merge::mergesort(const vector <int> & b)
{
    vector <int> for_sort = b;
    vector <int> scratch(b.size());
    merge_helper(for_sort, 0, b.size(), scratch);
    reverse(for_sort.begin(),for_sort.end());
    return for_sort;
}

/* left is the index of the leftmost element of the subarray; right is one
 * past the index of the rightmost element */
void _merge::merge_helper(vector <int> & for_sort, int left, int right, vector <int> & scratch)
{
    /* base case: one element */
    if(right == left + 1)
    {
        return;
    }
    else
    {
        int i = 0;
        int length = right - left;
        int midpoint_distance = length/2;
        /* l and r are to the positions in the left and right subarrays */
        int l = left, r = left + midpoint_distance;

        /* sort each subarray */
        merge_helper(for_sort, left, left + midpoint_distance, scratch);
        merge_helper(for_sort, left + midpoint_distance, right, scratch);

        /* merge the arrays together using scratch for temporary storage */
        for(i = 0; i < length; i++)
        {
            /* Check to see if any elements remain in the left array; if so,
             * we check if there are any elements left in the right array; if
             * so, we compare them.  Otherwise, we know that the merge must
             * use take the element from the left array */
            if(l < left + midpoint_distance &&
              (r == right || max(for_sort[l], for_sort[r]) == for_sort[l]))
            {
                scratch[i] = for_sort[l];
                l++;
            }
            else
            {
                scratch[i] = for_sort[r];
                r++;
            }
        }
        /* Copy the sorted subarray back to the input */
        for(i = left; i < right; i++)
        {
            for_sort[i] = scratch[i - left];
        }
    }
}

void _merge::destroy_tree()
{
  vector <int > empty_vec;
  sorted.swap( empty_vec );
}

void _merge::insert(int key)
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

void _merge::remove(int key)
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

void _merge::search_key(int key)
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

void _merge::printOrder()
{
	for(int i = 0; i < sorted.size(); i++)
	{
		cout << sorted[i] << " ";
	}
	cout << endl;
}

void _merge::printQuiet()
{
	for(int i = 0; i < sorted.size(); i++)
	{
		sorted[i];
	}
}

bool _merge::check_sorted()
{
	bool b1 = true;

	for(int i = 0; i < sorted.size()-1; i++)
	{
		if(sorted[i] > sorted[i+1]){return false;}
	}

	return b1;
}











