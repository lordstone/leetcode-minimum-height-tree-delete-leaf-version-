class Solution {
public:

    typedef struct node{
        set<int> arr;
        int val;
        node(int myval){val = myval;}
    }node;
    
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<int> ans;
        
        if(n == 0 ) return ans;
        if(n == 1 && edges.size() == 0){
            ans.push_back(0);
            return ans;
        }
        vector<node> arr;
        set<int> arrset;
        for(int i = 0; i < n; i ++){
            arr.push_back(node(i));
            arrset.insert(i);
        }

        for(int i = 0; i < edges.size(); i ++){
            arr[edges[i].first].arr.insert(edges[i].second);
            arr[edges[i].second].arr.insert(edges[i].first);
        } 
         
        while(arrset.size() > 2){
            
            //mark all the nodes to be delete
            vector<int> toDelete;

            for(auto iter = arrset.begin(); iter != arrset.end(); iter ++){
                if(arr[(*iter)].arr.size() <= 1){
                    
                    toDelete.push_back((*iter));
                }
            }

            for(int i = 0; i < toDelete.size(); i++){
                
                arr[*(arr[toDelete[i]].arr.begin())].arr.erase(toDelete[i]);
                arrset.erase(toDelete[i]);
               
            }

        }
        
        
        while(arrset.size() > 0 ){
            ans.push_back((*arrset.begin()) );
            arrset.erase(arrset.begin());
        }
        
        
        return ans;
    }
    
    
};
