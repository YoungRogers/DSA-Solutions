/*
	Using Topological Sort
*/

class Solution {
public:

	bool helper(vector<vector<int>>& adjList, unordered_map<int, int>& indegree) {

		queue<int> q;
		// Adding all 0 indegree vertices to the q
		for (auto x : indegree) {
			if (x.second == 0)
				q.push(x.first);
		}

		while (!q.empty()) {
			int frontElt = q.front();
			q.pop();

			// Visit the neighbours and reduce their indegree
			for (const int& y : adjList[frontElt]) {
				indegree[y]--;
				if (indegree[y] == 0) {
					q.push(y);
				}
			}
		}

		for (const auto z : indegree) {
			if (z.second != 0) {
				return false;
			}
		}

		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		// Constructing an Indegree map
		// first-> val. of node second->indegree
		unordered_map<int, int> indegree;

		// Initiliazing the map
		for (int i = 0 ; i < numCourses ; i++) {
			indegree[i] = 0;
		}

		for (const vector<int> x : prerequisites) {
			indegree[x[0]]++;
		}

		// Creating an adjacency list
		vector<vector<int>> adjList(numCourses);
		for (const vector<int> x : prerequisites) {
			adjList[x[1]].push_back(x[0]);
		}

		return helper(adjList, indegree);

	}
};
