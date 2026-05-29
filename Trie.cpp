/*ffff*/
#include<iostream>


struct TrieNode{
    TrieNode* next[26];
    int min_sz=INT_MAX;
    int best_i=-1;
};

static constexpr int N=500003;
static TrieNode pool[N];
static int ptr=0;

struct Trie{
    TrieNode* root;

    TrieNode* newNode(){
        TrieNode* node=&pool[ptr++];
        memset(node->next,0,sizeof(node->next));
        node->min_sz=INT_MAX;
        node->best_i=-1;
        return node;
    }

    Trie(){
        ptr=0;
        root=newNode();
    }

    void insert(const string& w,int idx){
        int wz=w.size();
        TrieNode* curr=root;

        if(wz<curr->min_sz){
            curr->min_sz=wz;
            curr->best_i=idx;
        }

        for(int i=wz-1;i>=0;i--){
            int c=w[i]-'a';
            if(curr->next[c]==NULL)
                curr->next[c]=newNode();
            curr=curr->next[c];

            if(wz<curr->min_sz){
                curr->min_sz=wz;
                curr->best_i=idx;
            }
        }
    }

    int find(const string& w){
        TrieNode* curr=root;
        int best = curr->best_i,n=w.size()-1;
        

        for(int i=n;i>=0;i--){
            int c=w[i]-'a';
            if(curr->next[c]==NULL)
                break;
            curr=curr->next[c];
            best=curr->best_i;
        }
        return best;
    }
};

class Solution {
public:
    static vector<int> stringIndices(vector<string>& words, vector<string>& wordsQ) {
        int i=0;
        Trie trie;
        vector<int> ans(wordsQ.size());
        for(auto& w:words)
            trie.insert(w,i++);

        i=0;
        for(auto& q:wordsQ){
            ans[i++]=trie.find(q);
        
     
        }
        return ans;
    }
};

auto init=[]() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    return 'c';
}();
