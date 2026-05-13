class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

    // if the time needed to reach target is same for x cars, x cars together is one fleet.
    // calculate time needed for each car -- unique values = number of fleet?

    // example 1: balance_distance [9, 6] speed [3,2] time array = [3, 3]
    // example 2: balance_distance [6, 9, 10, 3] time array = [3, 4, 10, 3]

    vector<pair<int,int>> posSpd;
    for(int i = 0; i < position.size(); i++)
    {
        posSpd.push_back({position[i], speed[i]});
    }
    // posSpd = [{4,2}, {1,2}, {0,1}, {7,1}]
    sort(posSpd.rbegin(), posSpd.rend());
    // posSpd = [{7,1}, {4,2}, {1,2}, {0,1}]

    vector<double> targetTime;


    for(auto& i : posSpd)
    {
        targetTime.push_back((double)(target - i.first) / i.second); 
        if(targetTime.size() >=2  && (targetTime.back() <= targetTime[targetTime.size() - 2]))
            targetTime.pop_back();
    }
    return targetTime.size();
        
    }
};
