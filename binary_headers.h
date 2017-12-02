#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

//for the btree
struct node
{
  int key_value;
  node *left;
  node *right;
  node *parent;
};

//the abstract base class, sets the general form I patterned each implementation after
class sorts
{
    public:
		virtual void build(const vector <int> & data) =0;
        virtual void insert(int key) =0;
		virtual void remove(int key) =0;
        virtual void destroy_tree() =0;
		virtual void printOrder() =0;
		virtual void printQuiet() =0;
		virtual bool check_sorted() =0;
		virtual void search_key(int key) =0;
};

class btree : public sorts
{
    public:
        btree();
        ~btree();

	    void build(const vector <int> & data);
        void insert(int key);
	    void remove(int key);
        void destroy_tree();
		void printOrder();
		void printQuiet();
		bool check_sorted();
		void search_key(int key);

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key);
        node *search(int key, node *leaf);
		void printOrder(node *leaf);
		void printQuiet(node *leaf);
		void check_sorted(node *leaf, int & tracker, bool & b1);
		//collects the integers below the leaf, so we can remove a key
		void collect_for_remove(node *leaf, vector <int> & collect);

        node *root;
};

class bubble : public sorts
{
    public:
	    void build(const vector <int> & data);
        void insert(int key);
	    void remove(int key);
        void destroy_tree();
		void printOrder();
		void printQuiet();
		bool check_sorted();
		void search_key(int key);
	private:
		vector <int> sorted;
};

class quick : public sorts
{
    public:
	    void build(const vector <int> & data);
        void insert(int key);
	    void remove(int key);
        void destroy_tree();
		void printOrder();
		void printQuiet();
		bool check_sorted();
		void search_key(int key);
	private:
		vector <int> sorted;
		vector <int> quicksort(const vector <int> & b);
};

class _merge : public sorts
{
    public:
	    void build(const vector <int> & data);
        void insert(int key);
	    void remove(int key);
        void destroy_tree();
		void printOrder();
		void printQuiet();
		bool check_sorted();
		void search_key(int key);
	private:
		vector <int> sorted;
		vector <int> mergesort(const vector <int> & b);
		void merge_helper(vector <int> & for_sort, int left, int right, vector <int> & scratch);
};
