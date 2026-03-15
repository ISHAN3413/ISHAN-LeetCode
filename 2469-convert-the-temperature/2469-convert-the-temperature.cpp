class Solution {
public:
    vector<double> convertTemperature(double c) {
        vector<double> a;
        a.push_back(c+273.15);
        a.push_back(c*1.8+32);
        return a;
    }
};