class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> result = new ArrayList<>();
        for (int i = 1; i < 10; i++) {
            dfs(i, n, result);
        }
        return result;
    }

    private void dfs(int current, int n, List<Integer> result) {
        if (current > n) {
            return;
        }
        result.add(current);
        for (int i = 0; i < 10; i++) {
            dfs(current * 10 + i, n, result);
        }
    }
}