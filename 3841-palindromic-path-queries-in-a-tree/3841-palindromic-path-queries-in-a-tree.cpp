
class Solution {
    vector<vector<int>> g;
    vector<int> par, dep, sz, heavy, head, pos;
    vector<int> seg;
    int timer = 0, base = 1;

    void update(int p, int val) {
        p += base;
        seg[p] = val;
        for (p /= 2; p; p /= 2)
            seg[p] = seg[2 * p] ^ seg[2 * p + 1];
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += base, r += base; l <= r; l /= 2, r /= 2) {
            if (l & 1) ans ^= seg[l++];
            if (!(r & 1)) ans ^= seg[r--];
        }
        return ans;
    }

    int pathQuery(int u, int v) {
        int ans = 0;

        while (head[u] != head[v]) {
            if (dep[head[u]] < dep[head[v]])
                swap(u, v);

            ans ^= query(pos[head[u]], pos[u]);
            u = par[head[u]];
        }

        if (dep[u] > dep[v]) swap(u, v);
        return ans ^ query(pos[u], pos[v]);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        g.assign(n, {});
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        par.assign(n, -1);
        dep.assign(n, 0);
        sz.assign(n, 1);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);

        vector<int> order, st = {0};
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            order.push_back(u);

            for (int v : g[u]) {
                if (v == par[u]) continue;
                par[v] = u;
                dep[v] = dep[u] + 1;
                st.push_back(v);
            }
        }

        for (int i = n - 1; i > 0; i--) {
            int u = order[i], p = par[u];
            sz[p] += sz[u];
            if (heavy[p] == -1 || sz[u] > sz[heavy[p]])
                heavy[p] = u;
        }

        vector<pair<int,int>> chains = {{0, 0}};
        while (!chains.empty()) {
            auto [u, h] = chains.back();
            chains.pop_back();

            for (int x = u; x != -1; x = heavy[x]) {
                head[x] = h;
                pos[x] = timer++;

                for (int v : g[x])
                    if (par[v] == x && v != heavy[x])
                        chains.push_back({v, v});
            }
        }

        while (base < n) base *= 2;
        seg.assign(2 * base, 0);

        for (int i = 0; i < n; i++)
            update(pos[i], 1 << (s[i] - 'a'));

        vector<bool> ans;

        for (auto &q : queries) {
            string op;
            int u, v;
            char c;
            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;
                s[u] = c;
                update(pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;
                int mask = pathQuery(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
