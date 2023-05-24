class Solution {
public:
    string reverseWords(string s) {
    

        // first Approach
       /*
        stack<char> st;

        st.push(' ');

        for(int i=s.length()-1; i >= 0; i--){
            if(st.top() == ' ' && s[i] == ' ') continue;
            else st.push(s[i]);                        
        }

        string str="";
        string temp ="";
        
        if(st.top() == ' ') st.pop();

        while(st.size() != 0){
            if(st.top() != ' '){
                temp+=st.top();  
            }
            else if(st.top() == ' ' && st.size() != 1){
                str = " "+temp+str;
                temp ="";
            }
            else if(st.size() == 1){
                str= temp+str;
            }
            st.pop();
        }

        return str;


        */

        // second Approach

        bool wordEncounter = false;
        string temp = "", str="";
        int spaceCount =0;

        for(int i=s.length()-1; i>=0; i--){
            if(s[i] != ' '){
                temp = s[i]+temp;
                wordEncounter = true;
            }
            else if(s[i] == ' ' && wordEncounter){
                if(spaceCount == 0) str = temp;
                else str = str + " "+ temp;
                temp = "";
                wordEncounter = false;
                spaceCount = 1;
            }

        }

        if(wordEncounter && spaceCount == 1) str = str + " "+ temp;
        else if(wordEncounter && spaceCount == 0) str = temp;
        
        return str;
       
    }
};
