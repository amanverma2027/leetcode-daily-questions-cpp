class Solution {
public:
    string simplifyPath(string path) {
        // string ok;
        // vector<string>store;

        // int i = 1, n = path.size();

        // while(i < n) {
        //     while(path[i]=='/') i++;
        //     while(path[i] and path[i] != '/') ok += path[i++];
        //     if(ok == ".." and store.size()) store.pop_back();
        //     else if(ok.size() and ok != "." and ok != "..")
        //     store.push_back(ok);
        //         ok.clear();
        // }
        // ok = "/";
        // for(auto str:store) ok += str, ok += "/";
        // if(ok.size() > 1) ok.pop_back();

        // return ok;

        string ok;
        vector<string> store;

        int i = 1;
        int n = path.size();

        while (i < n) {
            while (i < n && path[i] == '/')
                i++;
            
            while (i < n && path[i] != '/')
                ok += path[i++];

            if (ok == ".." && !store.empty()) {
                store.pop_back();
            }

            else if (!ok.empty() && ok != "." && ok != "..") {
                store.push_back(ok);
            }

            ok.clear();
        }

        ok = "/";

        for (auto str : store) {
            ok += str;
            ok += "/";
        }

        if (ok.size() > 1)
            ok.pop_back();

        return ok;
        
    }
};