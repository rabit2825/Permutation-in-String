class Solution {
private:
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};

        // Count frequencies of characters in s1
        for(int i = 0; i < s1.length(); i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int windowSize = s1.length();
        int count2[26] = {0};

       
        for(int i = 0; i < s2.length() && i < windowSize; i++) {
            int index = s2[i] - 'a';
            count2[index]++;
        }

        if(checkEqual(count1, count2)) {
            return true;
        }

       
        for(int i = windowSize; i < s2.length(); i++) {
            
            char newChar = s2[i];
            int indexNew = newChar - 'a';
            count2[indexNew]++;

            
            char oldChar = s2[i - windowSize];
            int indexOld = oldChar - 'a';
            count2[indexOld]--;

            
            if(checkEqual(count1, count2)) {
                return true;
            }
        }

        return false;
    }
};
