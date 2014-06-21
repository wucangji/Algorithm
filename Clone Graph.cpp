/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // method 1    DFS
        unordered_map<int, UndirectedGraphNode *> map;
        return clone(node,map);
    }
    
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &map){
        if (!node) return node;                // consider null pointer~!!
        if(map.count(node->label))   return map[node->label];    // count is easier, if use find, need adding findxxx !map.end();
        // if find in the map, just return 
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        
        // add this newnode into the map;
        map[node->label] = newnode;
        for(int i=0; i<node->neighbors.size();i++){
            (newnode->neighbors).push_back(clone(node->neighbors[i],map));
        }
        
        return newnode;
    }
};