/**
 * 判断有向图是否存在长度大于等于2的闭环
 * @param edge 有向图的邻接矩阵，edge[i][j]表示节点i到节点j是否有一条有向边
 * @return 若存在长度大于等于2的闭环则返回true，否则返回false
 */
bool detectCycle(int v, int edge[26][26], bool visited[26], bool recStack[26])
{
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < 26; i++) {
        if (edge[v][i]) {
            if (!visited[i] && detectCycle(i, edge, visited, recStack)) {
                return true;
            }
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

/**
 * 检测以节点v为起点的路径是否存在闭环
 * @param v 起点
 * @param edge 有向图的邻接矩阵，edge[i][j]表示节点i到节点j是否有一条有向边
 * @param visited 记录节点是否已被访问过
 * @param recStack 记录当前正在访问的节点，防止访问形成环
 * @return 若存在长度大于等于2的闭环则返回true，否则返回false
 */
bool hasCycle(int edge[26][26])
{
    bool visited[26] = {false};
    bool recStack[26] = {false};

    for (int i = 0; i < 26; i++) {
        if (!visited[i] && detectCycle(i, edge, visited, recStack)) {
            return true;
        }
    }

    return false;
}
