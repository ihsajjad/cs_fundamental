
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (is_valid(ci, cj) && !vis[ci][cj] && adj_mat[ci][cj] == '.')
            {