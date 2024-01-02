class DataStream {
    
    int val, K, cnt=0;

public:

    DataStream(int value, int k) {
        K = k;
        val = value;
    }
    
    bool consec(int num) {
        if(num==val) cnt++;
        else cnt = 0;
        return cnt>=K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */