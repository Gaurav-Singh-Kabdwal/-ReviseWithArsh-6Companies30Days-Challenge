class ThroneInheritance {

    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        
        vector<string> order;
        getOrder(order, king);
        return order;
    }


    void getOrder(vector<string> &order, string parent){

        if(!dead.count(parent)) order.push_back(parent);

        for(auto child : children[parent]){
            getOrder(order, child);
        }    
    

    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */