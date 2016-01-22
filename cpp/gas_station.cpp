/*
 *	Gas Station
 *
 *	Travel around a circuit.
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 0)
        	return -1;

        int total = 0,
        	left  = 0,
        	pos   = 0;

        for (int i = 0; i < n; ++i)
        {
        	left += gas[i] - cost[i];
        	if (left < 0) {
        		//加入总量（总油量 > 总消耗）
        		total += left;
        		//基于一个重要的前提：only one UNIQUE solution。
        		//一旦出现余量不足（left < 0），则证明前i个点都不可能是起点。
        		//重设left，并将下一个点作为起点。
        		left = 0;
        		pos = i + 1;
        	}
        }
        total += left;

        if (total < 0) 
        	return -1;
        return pos;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> gas = {5,24,3};
	vector<int> cost = {16,2,4};
	cout<<s.canCompleteCircuit(gas, cost)<<endl;
	return 0;
}