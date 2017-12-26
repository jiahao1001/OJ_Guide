/*******************************************************
* problem id : 150
* problem title : Evaluate Reverse Polish Notation
* problem link : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
********************************************************/

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int a, b;

    for(int i=0; i<tokens.size(); i++) {
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
            st.push(stoi(tokens[i]));
        else {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if(tokens[i]=="+")
                st.push(b+a);
            if(tokens[i]=="-")
                st.push(b-a);
            if(tokens[i]=="*")
                st.push(b*a);
            if(tokens[i]=="/")
                st.push(b/a);
        }
    }

    return st.top();
}
