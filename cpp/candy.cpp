/*
 * Candy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int MIN_RATE;
public:
    int candy(vector<int>& ratings) {
    	if (ratings.size() <= 1) 
    		return ratings.size();

    	// cout<<*max_element(ratings.begin(), ratings.end())<<endl;
    	MIN_RATE = *min_element(ratings.begin(), ratings.end());
    	for (int i = 0; i < ratings.size(); ++i)
    	{
    		ratings[i] -= MIN_RATE - 1;
    	}
    	MIN_RATE = 1;

    	sink(ratings, 0, ratings.size() - 1);


    	for (int m : ratings)
    		cout<<m<<" ";
    	cout<<endl;

    	int sum = 0;
    	for (int m : ratings)
    		sum += m;
        return sum;
    }

    void sink(vector<int>& ratings, int i, int j) {
    	if (j <= i) 
    		return;
    	vector<int>::iterator it = ratings.begin();
    	vector<int>::iterator curr = max_element(it+i, it+j);
    	int center = curr - it;
    	int left = center, right = center;
    	while (left > i 
    		&& ratings[left] > ratings[left-1] 
    		&& ratings[left-1] > MIN_RATE)
    	{
    		left --;
    	}
    	while (right < j 
    		&& ratings[right] > ratings[right+1] 
    		&& ratings[right+1] > MIN_RATE)
    	{
    		right ++;
    	}
    	cout<<ratings[left]<<" "<<ratings[right]<<endl;
    	vector<int>::iterator pMinRate = min_element(it+left, it+right);
    	if (*pMinRate > MIN_RATE){
    		int minus = *pMinRate - MIN_RATE - 1;
    		for (int k=left; k <= right; k++) {
    			ratings[k] -= minus;
    		}
    	}else {
    		return;
    	}
    	sink(ratings, i, left-1);
    	sink(ratings, right+1, j);
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> ratings = {2,2};
	int sum = s.candy(ratings);
	cout<<"At least "<<sum<<" candys."<<endl;
	return 0;
}