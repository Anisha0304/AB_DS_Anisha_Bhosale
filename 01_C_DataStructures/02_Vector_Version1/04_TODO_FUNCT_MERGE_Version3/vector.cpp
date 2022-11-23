#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted vectors into a single sorted vector
vector<int> merge(vector<int> a, vector<int> b) {
	// The vector that will contain the sorted output
	vector<int> c;
	int indexA = 0, indexB = 0;
	
	/* 
	 * While vector a or vector b still have numbers we haven't gone through, push the smaller element
	 * between vector a and b into c and increase the respective index.
	 */
	while(indexA < a.size() && indexB < b.size()) {
		if(a[indexA] < b[indexB]){
			c.push_back(a[indexA]);
			indexA++;
		}
		else {
			c.push_back(b[indexB]);
			indexB++;
		}
	}
	
	// Push the last numbers from the vector with remaining numbers
	// Vector a has remaining numbers; push them onto c
	if(indexA < a.size()) {
		for(int i = indexA; i < a.size(); ++i) {
			c.push_back(a[indexA]);
			indexA++;
		}
	}
	// Vector b has remaining numbers; push them onto c
	else {
		for(int i = indexB; i < b.size(); ++i) {
			c.push_back(b[indexB]);
			indexB++;
		}
	}
	
	return c;
}

// Use the helper merge function from above to sort a vector of sorted vectors
vector<int> mergeVectors(vector<vector<int>> a){
	// The vector that will contain the sorted output
	vector<int> c;
	// c is now a sorted vector composed of the first two vectors of a (vector<vector<int>>)
	c = merge(a[0], a[1]);
	
	// If there are more vectors in a, keep merging them with c
	if(a.size() > 2) {
		for(int i = 2; i < a.size(); ++i){
			c = merge(c, a[i]);
		}
	}
	
	return c;
} 

int main() {
	vector<vector<int>> a{{0,5,8,9},{1,2,7},{10}};
	
	vector<int> b = mergeVectors(a);
	
	for(int i = 0; i < b.size(); ++i) {
		cout << b[i] << " ";
	}
	
	return 0;
}