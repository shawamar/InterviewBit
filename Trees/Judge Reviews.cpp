/*
Judge Reviews
You are given the task of ranking hotel reviews in this question. Lets say, you are given a bunch of user reviews where 
each review is a string. Assume that our Expedia bots have figured out a set of "Good words" which indicate that the 
user likes the hotel. The more the number of "Good words", the more the user likes the hotel. Given multiple such 
reviews and the list of good words, you need to rank the reviews with the most positive review first and the most 
negative review the last. In other words, the review with the most number of good words comes first and the one with 
least number of good words comes last in the ranking. Note: Sorting should be stable. If review i and review j have 
the same number of "Good words", then their original order would be preserved.

Example:
Input: 
S = "pool_fridge_wifi"
R = ["water_in_pool", "pond_fridge_drink", "pool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["pool_wifi_speed", "water_in_pool", "pond_fridge_drink"]

#Python 3.7
class Solution:
    # @param A : string
    # @param B : list of strings
    # @return a list of integers
    def solve(self, A, B):
        goodKeyword=(A.split('_'))
        good_dict={}
        for word in goodKeyword:
            good_dict[word]=1
        points=[]
        sol=[]
        i=0
        for review in B:
            c=0
            for keyword in (review.split('_')):
                if keyword in good_dict:
                    c+=1
            points.append([-c,i])
            i+=1
        points.sort()
        return [x[1] for x in points]

*/
struct TrieNode{
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(bool word): isWord(word) {}
};
 
struct res {
    int index, score;
};
 
void tokenize (string good_string, vector<string> &goodWords) {
    good_string += "_";
    string temp="";
    
    for (int i=0; i<good_string.length(); i++) {
        if (good_string[i]!='_') {
            temp += good_string[i];
        } else {
            if (temp.length()) {
                goodWords.push_back(temp);
                temp = "";
            }
        }
    }
}
 
bool sortByScore (res lhs, res rhs) {
    if (lhs.score > rhs.score) return true;
    else if (lhs.score == rhs.score) return lhs.index < rhs.index;
    return false;
}
 
void constructTrie(TrieNode* A, vector<string> goodWords) {
    TrieNode* current = A;
    
    for (int i=0; i<goodWords.size(); i++) {
        current = A;
        
        for (int j=0; j<goodWords[i].length(); j++) {
            auto it = (current->children).find(goodWords[i][j]);
            
            if (it != (current->children).end()) {
                current = it->second;
            } else {
                
                TrieNode* B = new TrieNode(false);
                (current->children)[goodWords[i][j]] = B;
                current = B;
                
            }
            
            if (j == goodWords[i].length()-1) current->isWord = true;
        }
    }
    
}
 
vector<int> sortReviews(vector<string> reviews, TrieNode* root) {
    int score;
    vector<res> result;
    TrieNode* current;
    
    vector<string> temp;
    
    
    
    for (int i=0; i<reviews.size(); i++) {
        res t;
        temp.clear();
        score = 0;
        reviews[i] +=  "_";
        tokenize(reviews[i], temp);
        
        for (int j=0; j<temp.size(); j++) {
            current = root;
            for (int k=0; k<temp[j].length(); k++) {
                
                auto it = (current->children).find(temp[j][k]);
                if (it == (current->children).end()) {
                    break;
                }
                
                current = it->second;
                
                if (k == temp[j].length()-1 && current->isWord) score++; 
            }
        }
        t.index = i;
        t.score = score;
        result.push_back(t);
    }
    
    sort(result.begin(), result.end(), sortByScore);
    
    vector<int> ret;
    
    for (int i=0; i<result.size(); i++) {
        ret.push_back(result[i].index);
    }
    
    return ret;
}
 
vector<int> Solution::solve(string A, vector<string> &B) {
    TrieNode* root = new TrieNode(false);
    vector<string> good_words;
    
    tokenize(A, good_words);
    
    constructTrie(root, good_words);
    
    vector<int> result = sortReviews(B, root);
    
    return result;
}
